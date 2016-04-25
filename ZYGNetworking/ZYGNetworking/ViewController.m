//
//  ViewController.m
//  ZYGNetworking
//
//  Created by ZhangYunguang on 15/11/23.
//  Copyright (c) 2015年 ZhangYungaung. All rights reserved.
//

#import "ViewController.h"
#import "ZYGNetwork.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    self.view.backgroundColor = [UIColor blackColor];
    
    
    
    
    // 通常放在appdelegate就可以了
    [ZYGNetwork updateBaseUrl:@"http://apistore.baidu.com"];
    [ZYGNetwork enableInterfaceDebug:YES];
    
    
    // 测试GET API
    NSString *url = @"/microservice/cityinfo?cityname=北京";
    [ZYGNetwork getWithUrl:url success:^(id response) {
        NSLog(@"get测试成功");
    } fail:^(NSError *error) {
        NSLog(@"get测试失败");
    }];
    
    
    // 测试POST API：
    // 假数据
    NSDictionary *postDict = @{ @"urls": @[@"http://www.henishuo.com/git-use-inwork/",
                                           @"http://www.henishuo.com/ios-open-source-hybloopscrollview/"]
                                };
    NSString *path = @"/urls?site=www.henishuo.com&token=bRidefmXoNxIi3Jp";
    // 由于这里有两套基础路径，用时就需要更新
    [ZYGNetwork updateBaseUrl:@"http://data.zz.baidu.com"];
    [ZYGNetwork postWithUrl:path params:postDict success:^(id response) {
        NSLog(@"post测试成功");
    } fail:^(NSError *error) {
        NSLog(@"post测试失败");
    }];
    
    
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
