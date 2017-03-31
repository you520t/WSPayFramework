//
//  WSPay.h
//  PayDemo
//
//  Created by lcyu on 2017/3/30.
//  Copyright © 2017年 you520t. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef NS_ENUM(NSInteger, WSPayType) {
    WSPayTypeWeiXin = 0,
    WSPayTypeAlipay,
    WSPayTypeHiCard
};



@interface WSPayTypeModel : NSObject
@property (nonatomic, strong) NSString *schemeKey;
@property (nonatomic, assign) WSPayType payType;
-(id)initWithSchemeKey:(NSString *)schemeKey payType:(WSPayType)payType;
@end

@interface WSPay : NSObject
@property (nonatomic, strong, readonly) NSArray<WSPayTypeModel *> *payTypeDic;
+ (instancetype)shardInstance;
-(void)registerApp:(NSArray<WSPayTypeModel *> *)payTypeDic;
+(BOOL)handleOpenURL:(NSURL *)url completion:(void(^)())completion;
+(void)sendPay:(WSPayType)payType withAmount:(long long)amount completion:(void(^)(id response)) completion;
@end
