//
//  ZYGNetwork.h
//  ZYGNetworking
//
//  Created by ZhangYunguang on 15/11/23.
//  Copyright (c) 2015年 ZhangYungaung. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AFNetworking.h>
#import <AFNetworkActivityIndicatorManager.h>

@class AFHTTPRequestOperation;

// 请勿直接使用AFHTTPRequestOperation,以减少对第三方的依赖
typedef AFHTTPRequestOperation ZYGRequestOperation;

/*!
 *
 *  请求成功的回调
 *
 *  @param response 服务端返回的数据类型，通常是字典
 */
typedef void(^ZYGResponseSuccess)(id response);

/*!
 *
 *  网络响应失败时的回调
 *
 *  @param error 错误信息
 */
typedef void(^ZYGResponseFail)(NSError *error);

/*
 *
 *  基于AFNetworking的网络层封装类.
 *
 *  @note 这里只提供公共api
 */

@interface ZYGNetwork : NSObject

/*!
 *
 *  用于指定网络请求接口的基础url，如：
 *  http://henishuo.com或者http://101.200.209.244
 *  通常在AppDelegate中启动时就设置一次就可以了。如果接口有来源
 *  于多个服务器，可以调用更新
 *
 *  @param baseUrl 网络接口的基础url
 */
+ (void)updateBaseUrl:(NSString *)baseUrl;

/*!
 *
 *  对外公开可获取当前所设置的网络接口基础url
 *
 *  @return 当前基础url
 */
+ (NSString *)baseUrl;

/*!
 *
 *  开启或关闭接口打印信息
 *
 *  @param isDebug 开发期，最好打开，默认是NO
 */
+ (void)enableInterfaceDebug:(BOOL)isDebug;

/*!
 *
 *  开启或关闭是否自动将URL使用UTF8编码，用于处理链接中有中文时无法请求的问题
 *
 *  @param shouldAutoEncode YES or NO,默认为YES
 */
+ (void)shouldAutoEncodeUrl:(BOOL)shouldAutoEncode;

/*!
 *
 *  配置公共的请求头，只调用一次即可，通常放在应用启动的时候配置就可以了
 *
 *  @param httpHeaders 只需要将与服务器商定的固定参数设置即可
 */
+ (void)configCommonHttpHeaders:(NSDictionary *)httpHeaders;

/*!
 *
 *  GET请求接口，若不指定baseurl，可传完整的url
 *
 *  @param url     接口路径，如/path/getArticleList?categoryid=1
 *  @param success 接口成功请求到数据的回调
 *  @param fail    接口请求数据失败的回调
 *
 *  @return 返回的对象中有可取消请求的API
 */
+ (ZYGRequestOperation *)getWithUrl:(NSString *)url
                            success:(ZYGResponseSuccess)success
                               fail:(ZYGResponseFail)fail;
/*!
 *
 *  GET请求接口，若不指定baseurl，可传完整的url
 *
 *  @param url     接口路径，如/path/getArticleList
 *  @param params  接口中所需要的拼接参数，如@{"categoryid" : @(12)}
 *  @param success 接口成功请求到数据的回调
 *  @param fail    接口请求数据失败的回调
 *
 *  @return 返回的对象中有可取消请求的API
 */
+ (ZYGRequestOperation *)getWithUrl:(NSString *)url
                             params:(NSDictionary *)params
                            success:(ZYGResponseSuccess)success
                               fail:(ZYGResponseFail)fail;

/*!
 *
 *  POST请求接口，若不指定baseurl，可传完整的url
 *
 *  @param url     接口路径，如/path/getArticleList
 *  @param params  接口中所需的参数，如@{"categoryid" : @(12)}
 *  @param success 接口成功请求到数据的回调
 *  @param fail    接口请求数据失败的回调
 *
 *  @return 返回的对象中有可取消请求的API
 */
+ (ZYGRequestOperation *)postWithUrl:(NSString *)url
                              params:(NSDictionary *)params
                             success:(ZYGResponseSuccess)success
                                fail:(ZYGResponseFail)fail;

/*!
 *
 *  图片上传接口，若不指定baseurl，可传完整的url
 *
 *  @param image    图片对象
 *  @param url      上传图片的接口路径，如/path/images/
 *  @param filename 给图片起一个名字，默认为当前日期时间,格式为"yyyyMMddHHmmss"，后缀为`jpg`
 *  @param name     与指定的图片相关联的名称，这是由后端写接口的人指定的，如imagefiles
 *  @param success  上传成功的回调
 *  @param fail     上传失败的回调
 *
 *  @return 返回类型有取消请求的api
 */
+ (ZYGRequestOperation *)uploadWithImage:(UIImage *)image
                                     url:(NSString *)url
                                filename:(NSString *)filename
                                    name:(NSString *)name
                                 success:(ZYGResponseSuccess)success
                                    fail:(ZYGResponseFail)fail;

@end
