流动人员管理系统：
编译环境：
Windows11 
gcc version 8.1.0 (x86_64-posix-seh-rev0, Built by MinGW-W64 project)
UTF-8编码
开发环境：
VSCode
本项目用makefile编译，如想要手动编译需要了解make命令，具体可以上网了解。

注意事项：
1.登录账户名和密码默认为admin admin，如果想要手动注册生成可以运行generate admin account目录下的generateAdmin.exe文件，手动指定账户名和密码。
2.当前录入信息的时候仅支持英文输入，最后一次核酸时间含义是最近一次核酸距离今天的时间
3.不要直接关闭程序，退出时正常退出即可，以免用户信息文件userInfo.txt被截断
