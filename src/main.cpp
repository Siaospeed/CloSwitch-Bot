#include <MiraiCP.hpp>

#include <iostream>

using namespace std;
using namespace MiraiCP;

const PluginConfig CPPPlugin::config
{
    "priv.siaospeed.status",          // 插件id，如果和其他插件id重复将会被拒绝加载！
    "Status",        // 插件名称
    "1.2.0",            // 插件版本
    "Siaospeed",        // 插件作者
    "Online Check",  // 可选：插件描述
    "7/24/2023"        // 可选：日期
};

// 插件实例
class Status : public CPPPlugin
{
public:
    // 配置插件信息
    Status() : CPPPlugin() {}
    ~Status() override = default; // override关键字是为了防止内存泄漏

    // 入口函数。插件初始化时会被调用一次，请在此处注册监听
    void onEnable() override
    {
        Event::registerEvent<GroupMessageEvent>([](GroupMessageEvent e)
        {
            auto msg = e.message.filter<PlainText>();

            if (!msg.empty() && msg[0].content == "#status")
            {
                e.group.sendMessage("Bot Online!");
            }
                
        });
    }

    // 退出函数。请在这里结束掉所有子线程，否则可能会导致程序崩溃
    void onDisable() override
    {
        
    }
};

// 创建当前插件实例。请不要进行其他操作，
// 初始化请在onEnable中进行
void MiraiCP::enrollPlugin()
{
    MiraiCP::enrollPlugin<Status>();
}
