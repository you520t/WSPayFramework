//
//  WSPayAPI.h
//  PayDemo
//
//  Created by lcyu on 2017/3/31.
//  Copyright © 2017年 you520t. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface WSPayAPI : NSObject
+(UIViewController *)payViewController;
+(UIViewController *)payWebViewControllerWithUrlString:(NSString *)urlString;
@end
