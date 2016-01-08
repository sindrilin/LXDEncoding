//
//  ViewController.m
//  LXDEncoding
//
//  Created by 林欣达 on 16/1/8.
//  Copyright © 2016年 SindriLin. All rights reserved.
//

#import "ViewController.h"
#import "LXDCodeClass.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    LXDCodeClass * code = [LXDCodeClass new];
    [[UIApplication sharedApplication] openURL: [NSURL URLWithString: @"https://appsto.re/cn/jd2W-.i"]];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
