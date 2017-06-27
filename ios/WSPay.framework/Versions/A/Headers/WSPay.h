//
//  WSPay.h
//  PayDemo
//
//  Created by lcyu on 2017/3/30.
//  Copyright © 2017年 you520t. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
/**
 支付类型
 **/
typedef NS_ENUM(NSInteger, WSPayType) {
    WSPayTypeWeiXin = 4,
    WSPayTypeAlipay=5,
    WSPayTypeHiCard=2,
    WSPayTypeAll
};

/**
支付结果
 **/
typedef NS_ENUM(NSInteger,WSPayResultCode) {
    WSPayResultPaySucceed =0,  //支付成功
    WSPayResultUserCancel =1,  // 用户取消支付
    WSPayResultPayFailed =2, // 支付失败
    WSPayResultMissingRequiredParameter =3, // 缺少必要参数（手机号or appid）
    WSPayResultInterfaceError =4,//  接口错误
    WSPayResutNoChannelIdAndSecret=5  //  缺少channelId或APPSecret
};

/**
 取消的回调code
 */
typedef NS_ENUM(NSInteger,WSPDeleteOrderCode) {
    WSPDeleteOrderCodeSucceed=0,
    WSPDeleteOrderCodeFailed=1
};

//  支付吊起的入口类型
typedef NS_ENUM(NSInteger,WSPayEntrance) {
    WSPayEntranceByApp =0, //  原生吊起
    WSPayEntranceByWebView //  webview吊起
};

//支付类型model
@interface WSPayTypeModel : NSObject
@property (nonatomic, strong) NSString *schemeKey;
@property (nonatomic, assign) WSPayType payType;
-(id)initWithSchemeKey:(NSString *)schemeKey payType:(WSPayType)payType;
@end

// 支付结果
@interface WSPayResultModel : NSObject
@property (nonatomic, strong) NSString * errString; // 支付结果描述
@property (nonatomic, assign) WSPayResultCode code; // 支付状态码
@property (nonatomic, assign) WSPayType payType; // 支付方式
@property (nonatomic, strong) NSDictionary * extraDictionary; // Hi卡支付数据
@end

typedef void(^PayResult)(WSPayResultModel *);
typedef void(^DeleteResult) (WSPDeleteOrderCode);
typedef void(^ProductList)(NSArray *);

@interface WSPay : NSObject

+ (instancetype)shardInstance;

/**
 注册支付SDK

 @param payTypeDic 注册支付方式列表
 @param channelId 渠道ID
 @param appSecret 加解密key
 */
-(void)registerApp:(NSArray<WSPayTypeModel *> *)payTypeDic channelId:(NSString *)channelId appSecret:(NSString *)appSecret;

/**
 这个是放到AppDelegate里面，当支付完成接收微信和支付宝回调，返回值是判断是否是微信和支付宝的回调信息，返回NO则App自己处理

 @param url 微信和支付宝的回调URL
 @param completion 处理完成的回调
 @return 返回值，返回NO则App自己处理
 */
+(BOOL)handleOpenURL:(NSURL *)url completion:(void(^)())completion;

/** 
 支付调取方法

 @param parameters 支付参数(必传参数:appId 对应app的appId,mobile 用户手机号;若为游戏消耗品则还有:productId 项目id,qunatity 购买数量;其他不走IAP的商品传的参数为:moneyBaseFen 支付价格以分为单位 businessOrderNo 订单id)
 @param controller 是显示UI用
 @param completion 支付完成的回调
 */
-(void)wsStartPayWithPaymentParameters:(NSDictionary *)parameters withController:(UIViewController *)controller completion:(PayResult) completion;

/**
 这个方法是获取App在苹果后台注册的IAP项目列表，也可以自行通过后端获取

 @param businessId 对应app的商户id
 @param completion 回调给app的IAP项目列表
 */
-(void)getAppProductListByBusinessId:(NSString *)businessId productList:(ProductList)completion;

/**
 这个是IAP恢复购买非消耗品的方法（暂时还未启用）
 */
-(void)restoreTranscation;

@end
