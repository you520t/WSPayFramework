//
//  WSPay.h
//  PayDemo
//
//  Created by lcyu on 2017/3/30.
//  Copyright © 2017年 you520t. All rights reserved.
//

#import <Foundation/Foundation.h>
//支付类型
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
    WSPayResultPaySucceed =0,
    WSPayResultUserCancel =1,
    WSPayResultPayFailed =2,
    WSPayResultNoMobile =3,
    WSPayResultInterfaceError =4
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
@end

typedef void(^PayResult)(WSPayResultModel *);

@interface WSPay : NSObject

+ (instancetype)shardInstance;
//  需传递对应商户的channelId，channelId是给网关使用
-(void)registerApp:(NSArray<WSPayTypeModel *> *)payTypeDic channelId:(NSString *)channelId;

+(BOOL)handleOpenURL:(NSURL *)url completion:(void(^)())completion;
-(void)wsStartPayWithPaymentParameters:(NSDictionary *)parameters withController:(UIViewController *)controller completion:(PayResult) completion;
-(BOOL)handleWebViewRequestWithWebView:(WKWebView *)webView action:(WKNavigationAction *)action withController:(UIViewController *)controller completion:(PayResult) completion;
//url转换参数
+(NSDictionary *)convertOrderInfoWithUrl:(NSString *)url;
@end
