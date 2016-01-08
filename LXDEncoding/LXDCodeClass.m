
//
//  LXDCodeClass.m
//  LXDEncoding
//
//  Created by 林欣达 on 16/1/8.
//  Copyright © 2016年 SindriLin. All rights reserved.
//

#import "LXDCodeClass.h"
#import "LXDEncoding.h"

@implementation LXDCodeClass

LXDObjectCodingImplement

- (instancetype)init
{
    if (self = [super init]) {
        [self codePropertiesWithHandler: ^(objc_property_t property, NSString *propertyName) {
            NSLog(@"\n--name: %s\n--attributes: %s", property_getName(property), property_getAttributes(property));
        }];
    }
    return self;
}


@end
