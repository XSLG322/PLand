#pragma once
#include "ll/api/base/StdInt.h"
#include "nlohmann/json.hpp"
#include "pland/Global.h"
#include "pland/LandPos.h"
#include <cstdint>


namespace land {


struct LandPermTable {
    // 标记 [x] 为复用权限
    bool allowFireSpread{true};          // 火焰蔓延
    bool allowAttackDragonEgg{false};    // 攻击龙蛋
    bool allowFarmDecay{true};           // 耕地退化
    bool allowPistonPush{true};          // 活塞推动
    bool allowRedstoneUpdate{true};      // 红石更新
    bool allowExplode{false};            // 爆炸
    bool allowDestroy{false};            // 允许破坏
    bool allowWitherDestroy{false};      // 允许凋零破坏
    bool allowPlace{false};              // 允许放置 [x]
    bool allowAttackPlayer{false};       // 允许攻击玩家
    bool allowAttackAnimal{false};       // 允许攻击动物
    bool allowAttackMob{true};           // 允许攻击怪物
    bool allowOpenChest{false};          // 允许打开箱子
    bool allowPickupItem{false};         // 允许拾取物品
    bool allowThrowSnowball{true};       // 允许投掷雪球
    bool allowThrowEnderPearl{true};     // 允许投掷末影珍珠
    bool allowThrowEgg{true};            // 允许投掷鸡蛋
    bool allowThrowTrident{true};        // 允许投掷三叉戟
    bool allowDropItem{true};            // 允许丢弃物品
    bool allowShoot{false};              // 允许射击 [x]
    bool allowThrowPotion{false};        // 允许投掷药水 [x]
    bool allowRideEntity{false};         // 允许骑乘实体
    bool allowRideTrans{false};          // 允许骑乘矿车、船
    bool allowAxePeeled{false};          // 允许斧头去皮
    bool allowAttackEnderCrystal{false}; // 允许攻击末地水晶
    bool allowDestroyArmorStand{false};  // 允许破坏盔甲架
    bool allowLiquidFlow{true};          // 允许液体流动
    bool allowSculkBlockGrowth{true};    // 允许幽匿尖啸体生长

    bool useAnvil{false};            // 使用铁砧
    bool useBarrel{false};           // 使用木桶
    bool useBeacon{false};           // 使用信标
    bool useBed{false};              // 使用床
    bool useBell{false};             // 使用钟
    bool useBlastFurnace{false};     // 使用高炉
    bool useBrewingStand{false};     // 使用酿造台
    bool useCampfire{false};         // 使用营火
    bool useFiregen{false};          // 使用打火石
    bool useCartographyTable{false}; // 使用制图台
    bool useComposter{false};        // 使用堆肥桶
    bool useCraftingTable{false};    // 使用工作台
    bool useDaylightDetector{false}; // 使用阳光探测器
    bool useDispenser{false};        // 使用发射器
    bool useDropper{false};          // 使用投掷器
    bool useEnchantingTable{false};  // 使用附魔台
    bool useDoor{false};             // 使用门
    bool useFenceGate{false};        // 使用栅栏门
    bool useFurnace{false};          // 使用熔炉
    bool useGrindstone{false};       // 使用砂轮
    bool useHopper{false};           // 使用漏斗
    bool useJukebox{false};          // 使用唱片机
    bool useLoom{false};             // 使用织布机
    bool useStonecutter{false};      // 使用切石机
    bool useNoteBlock{false};        // 使用音符盒
    bool useShulkerBox{false};       // 使用潜影盒
    bool useSmithingTable{false};    // 使用锻造台
    bool useSmoker{false};           // 使用烟熏炉
    bool useTrapdoor{false};         // 使用活板门
    bool useLectern{false};          // 使用讲台
    bool useCauldron{false};         // 使用炼药锅
    bool useLever{false};            // 使用拉杆
    bool useButton{false};           // 使用按钮
    bool useRespawnAnchor{false};    // 使用重生锚
    bool useItemFrame{false};        // 使用物品展示框
    bool useFishingHook{false};      // 使用钓鱼竿
    bool useBucket{false};           // 使用桶
    bool usePressurePlate{false};    // 使用压力板
    bool useArmorStand{false};       // 使用盔甲架
    bool useBoneMeal{false};         // 使用骨粉
    bool useHoe{false};              // 使用锄头
    bool useShovel{false};           // 使用锹

    bool editFlowerPot{false}; // 编辑花盆
    bool editSign{false};      // 编辑告示牌
};


using LandData_sptr = std::shared_ptr<class LandData>; // 共享指针
using LandData_wptr = std::weak_ptr<class LandData>;   // 弱指针
class LandData {
public:
    int                version{5};                         // 版本号
    LandPos            mPos;                               // 领地对角坐标
    PosBase            mTeleportPos;                       // 领地传送坐标
    LandID             mLandID{static_cast<uint64_t>(-1)}; // 领地唯一ID  (由 PLand::addLand() 时分配)
    LandDimid          mLandDimid;                         // 领地所在维度
    bool               mIs3DLand;                          // 是否为3D领地
    LandPermTable      mLandPermTable;                     // 领地权限
    UUIDs              mLandOwner;                         // 领地主人(默认UUID,其余情况看mOwnerDataIsXUID)
    std::vector<UUIDs> mLandMembers;                       // 领地成员
    std::string        mLandName{"Unnamed territories"};   // 领地名称
    std::string        mLandDescribe{"No description"};    // 领地描述
    bool               mIsSaleing{false};                  // 是否正在出售
    int                mSalePrice{0};                      // 出售价格
    int                mOriginalBuyPrice{0};               // 原始购买价格
    bool               mIsConvertedLand{false};            // 是否为转换后的领地(其它插件创建的领地)
    bool               mOwnerDataIsXUID{false}; // 领地主人数据是否为XUID (如果为true，则主人上线自动转换为UUID)

    [[nodiscard]] LDAPI static LandData_sptr make(); // 创建一个空领地数据(反射使用)
    [[nodiscard]] LDAPI static LandData_sptr
    make(LandPos const& pos, LandDimid dimid, bool is3D, UUIDs const& owner); // 新建领地数据

    // getters
    [[nodiscard]] LDAPI LandPos const& getLandPos() const;
    [[nodiscard]] LDAPI LandID         getLandID() const;
    [[nodiscard]] LDAPI LandDimid      getLandDimid() const;
    [[nodiscard]] LDAPI int            getSalePrice() const;

    [[nodiscard]] LDAPI LandPermTable&       getLandPermTable();
    [[nodiscard]] LDAPI LandPermTable const& getLandPermTableConst() const;

    [[nodiscard]] LDAPI UUIDs const& getLandOwner() const;
    [[nodiscard]] LDAPI std::vector<UUIDs> const& getLandMembers() const;
    [[nodiscard]] LDAPI std::string const& getLandName() const;
    [[nodiscard]] LDAPI std::string const& getLandDescribe() const;


    // setters
    LDAPI bool setSaleing(bool isSaleing);
    LDAPI bool setIs3DLand(bool is3D);
    LDAPI bool setLandOwner(UUIDs const& uuid);
    LDAPI bool setSalePrice(int price);

    LDAPI bool setLandName(std::string const& name);
    LDAPI bool setLandDescribe(std::string const& describe);
    LDAPI bool _setLandPos(LandPos const& pos); // private

    LDAPI bool addLandMember(UUIDs const& uuid);
    LDAPI bool removeLandMember(UUIDs const& uuid);


    // others
    [[nodiscard]] LDAPI bool is3DLand() const;
    [[nodiscard]] LDAPI bool isLandOwner(UUIDs const& uuid) const;
    [[nodiscard]] LDAPI bool isLandMember(UUIDs const& uuid) const;
    [[nodiscard]] LDAPI bool isSaleing() const;

    [[nodiscard]] LDAPI bool isRadiusInLand(BlockPos const& pos, int radius) const;
    [[nodiscard]] LDAPI bool isAABBInLand(BlockPos const& pos1, BlockPos const& pos2) const;

    [[nodiscard]] LDAPI LandPermType getPermType(UUIDs const& uuid) const;

    [[nodiscard]] LDAPI nlohmann::json toJSON() const;
};


} // namespace land