#pragma once
#include "ll/api/data/KeyValueDB.h"
#include "pland/Global.h"
#include "pland/LandData.h"
#include <atomic>
#include <memory>
#include <thread>
#include <unordered_map>
#include <utility>
#include <vector>

class Player;
class BlockPos;

namespace land {

struct PlayerSettings {
    bool showEnterLandTitle{true};     // 是否显示进入领地提示
    bool showBottomContinuedTip{true}; // 是否持续显示底部提示
};

class PLand {
public:
    PLand()                        = default;
    PLand(const PLand&)            = delete;
    PLand& operator=(const PLand&) = delete;
    PLand(PLand&&)                 = delete;
    PLand& operator=(PLand&&)      = delete;

private:
    std::unique_ptr<ll::data::KeyValueDB>     mDB;                    // 领地数据库
    std::vector<UUIDs>                        mLandOperators;         // 领地操作员
    std::unordered_map<UUIDs, PlayerSettings> mPlayerSettings;        // 玩家设置
    std::atomic<LandID>                       mNextLandID{0};         // 下一个领地ID
    std::unordered_map<LandID, LandData_sptr> mLandCache;             // 领地缓存
    mutable std::shared_mutex                 mMutex;                 // 读写锁
    std::thread                               mThread;                // 线程
    std::atomic<bool>                         mThreadStopFlag{false}; // 线程停止标志

    // 维度 -> 区块 -> [领地] (快速查询领地)
    std::unordered_map<LandDimid, std::unordered_map<ChunkID, std::vector<LandID>>> mLandMap;

private: //! private 方法非线程安全
    void _loadOperators();
    void _loadPlayerSettings();
    void _loadLands();

    void _initLandMap();

    void _updateLandMap(LandData_sptr const& ptr, bool add);
    void _refreshLandRange(LandData_sptr const& ptr);

public:
    [[nodiscard]] LDAPI static PLand& getInstance();

    LDAPI void init();
    LDAPI void save();
    LDAPI void stopThread();

public:
    [[nodiscard]] LDAPI bool isOperator(UUIDs const& uuid) const;

    [[nodiscard]] LDAPI bool addOperator(UUIDs const& uuid);

    [[nodiscard]] LDAPI bool removeOperator(UUIDs const& uuid);

    [[nodiscard]] LDAPI bool hasPlayerSettings(UUIDs const& uuid) const;

    [[nodiscard]] LDAPI PlayerSettings* getPlayerSettings(UUIDs const& uuid);

    LDAPI bool setPlayerSettings(UUIDs const& uuid, PlayerSettings settings);

    [[nodiscard]] LDAPI bool hasLand(LandID id) const;

    LDAPI bool addLand(LandData_sptr land);

    LDAPI bool removeLand(LandID id);

    LDAPI void refreshLandRange(LandData_sptr const& ptr); // 刷新领地范围 (_refreshLandRange)

public: // 领地查询API
    [[nodiscard]] LDAPI LandData_wptr getLandWeakPtr(LandID id) const;
    [[nodiscard]] LDAPI LandData_sptr getLand(LandID id) const;
    [[nodiscard]] LDAPI std::vector<LandData_sptr> getLands() const;
    [[nodiscard]] LDAPI std::vector<LandData_sptr> getLands(LandDimid dimid) const;
    [[nodiscard]] LDAPI std::vector<LandData_sptr> getLands(UUIDs const& uuid, bool includeShared = false) const;
    [[nodiscard]] LDAPI std::vector<LandData_sptr> getLands(UUIDs const& uuid, LandDimid dimid) const;

    [[nodiscard]] LDAPI LandPermType getPermType(UUIDs const& uuid, LandID id = 0, bool ignoreOperator = false) const;

    [[nodiscard]] LDAPI LandData_sptr getLandAt(BlockPos const& pos, LandDimid dimid) const;

    [[nodiscard]] LDAPI std::vector<LandData_sptr> getLandAt(BlockPos const& center, int radius, LandDimid dimid) const;

    [[nodiscard]] LDAPI std::vector<LandData_sptr>
                        getLandAt(BlockPos const& pos1, BlockPos const& pos2, LandDimid dimid) const;

public:
    LDAPI LandID generateLandID();

public:
    LDAPI static ChunkID             EncodeChunkID(int x, int z);
    LDAPI static std::pair<int, int> DecodeChunkID(ChunkID id);

    static string DB_DIR_NAME();
    static string DB_KEY_OPERATORS();
    static string DB_KEY_PLAYER_SETTINGS();
};


} // namespace land