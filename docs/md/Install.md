# 安装

> 安装分为手动安装和 Lip 安装  
> 在大多数情况下，我们建议使用 Lip 安装

## Lip

> 使用以下命令安装 PLand

```bash
lip install github.com/engsr6982/PLand
```

> 或者安装指定版本的 PLand

```bash
lip install github.com/engsr6982/PLand@v1.0.0
```

> 您可以使用一下命令更新 PLand

```bash
lip install --upgrade github.com/engsr6982/PLand
```

- 安装后，您可以在 `plugins` 文件夹中找到 PLand 的安装文件

- 双击 `bedrock_server_mod.exe` 启动服务器

- 在服务器启动日志中，您应该能够看到 PLand 的启动日志 [启动日志](#启动日志)

## 手动安装

目前 PLand 依赖以下前置库

- LeviLamina
- [iListenAttentively](https://github.com/MiracleForest/iListenAttentively-Release)
- [BedrockServerClientInterface](https://github.com/OEOTYAN/BedrockServerClientInterface)

> 您需要手动下载对应版本的前置组件  
> 在下载前置组件时，请确保您下载的版本与 PLand 的版本兼容  
> 如果您不确定，我们建议您使用 Lip 安装

!> 本文档默认您已经安装好了前置组件

1. 前往 Minebbs 或者 Github Release 下载 PLand 的最新版本

2. 解压下载的 `PLand-windows-x64.zip`

3. 将解压后的 `PLand` 文件夹移动到 `plugins` 文件夹下

4. 双击 `bedrock_server_mod.exe` 启动服务器

5. 在服务器启动日志中，您应该能够看到 PLand 的启动日志 [启动日志](#启动日志)

## 启动日志

```log
22:03:02.933 INFO [PLand]   _____   _                        _
22:03:02.933 INFO [PLand]  |  __ \ | |                      | |
22:03:02.933 INFO [PLand]  | |__) || |      __ _  _ __    __| |
22:03:02.933 INFO [PLand]  |  ___/ | |     / _` || '_ \  / _` |
22:03:02.933 INFO [PLand]  | |     | |____| (_| || | | || (_| |
22:03:02.933 INFO [PLand]  |_|     |______|\__,_||_| |_| \__,_|
22:03:02.933 INFO [PLand]
22:03:02.933 INFO [PLand] Loading...
22:03:02.933 INFO [PLand] Build Time: 2024-09-22 22:43:13
22:03:02.964 INFO [PLand] 已加载 1 位操作员
22:03:02.964 INFO [PLand] 已加载 1 块领地数据
22:03:02.964 INFO [PLand] 初始化领地缓存系统完成
22:03:02.964 WARN [PLand] Debug Mode
22:03:02.964 INFO [LeviLamina] PLand 已加载
```
