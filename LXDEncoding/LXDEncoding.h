//
//  LXDEncoding.h
//  LXDEncoding
//
//  Created by 林欣达 on 16/1/8.
//  Copyright © 2016年 SindriLin. All rights reserved.
//

#ifndef LXDEncoding_h
#define LXDEncoding_h

#import <objc/runtime.h>
#import <UIKit/UIKit.h>

typedef void(^LXDCodingHandler)(objc_property_t property, NSString * propertyName);

/// 遍历属性列表
#define LXDCodingHandlerDef    \
    - (void)codePropertiesWithHandler: (LXDCodingHandler)codingHandler  \
    {   \
        unsigned int propertyCount; \
        objc_property_t * properties = class_copyPropertyList([self class], &propertyCount);    \
        for (int idx = 0; idx < propertyCount; idx++) { \
            \
            objc_property_t property = properties[idx]; \
            if (codingHandler) {    \
                codingHandler(property, [NSString stringWithUTF8String: property_getName(property)]);   \
            }   \
        }   \
        free(properties);   \
    }

/// 反序列化
#define LXDInitWithCoder    \
    - (instancetype)initWithCoder: (NSCoder *)aDecoder {   \
        self = [super init];\
        [self codePropertiesWithHandler: ^(objc_property_t property, NSString * key) {   \
            [self setValue: [aDecoder decodeObjectForKey: key] forKey: key]; \
        }]; \
        return self;    \
    }

/// 序列化
#define LXDEncodeWithCoder  \
    - (void)encodeWithCoder: (NSCoder *)aCoder {    \
        [self codePropertiesWithHandler: ^(objc_property_t property, NSString * key) { \
            [aCoder encodeObject: [self valueForKey: key] forKey: key]; \
        }]; \
    }

/// 遵守NSCoding协议的model只要在.m中加入这句宏定义，即可实现序列化反序列化功能
#define LXDObjectCodingImplement    \
    LXDCodingHandlerDef \
    LXDEncodeWithCoder  \
    LXDInitWithCoder

#endif /* LXDEncoding_h */
