# LXDEncoding
一键归档demo。
数据归档需要类遵循并实现NSCoding协议，在拥有大量属性的类中实现这些代码是个非常麻烦的事情。
基于runtime对序列化和反序列化进行了封装，任何需要数据归档的类在导入头文件后只需要在实现文件中添加一句代码即可实现数据归档

# Use
添加头文件 #import "LXDEncoding.h"
在.m文件中加入 LXDObjectCodingImplement 代码，即可实现数据归档协议
<span><img src="https://github.com/JustKeepRunning/LXDEncoding/blob/master/1.png"></span>

# Other
暂不支持实例变量ivar的数据归档，后期会陆续添加并支持功能
