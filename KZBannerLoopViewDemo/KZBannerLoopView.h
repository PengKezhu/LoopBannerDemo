//
//  KZBannerLoopView.h
//  LoopBannersDemo
//
//  Created by pengkezhu on 2018/12/7.
//  Copyright © 2018 彭柯柱. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class KZBannerLoopView;
@protocol KZBannerLoopViewDelegate <NSObject>

- (UIView *)loopView:(KZBannerLoopView *)loopView itemForIndex:(NSInteger)index reuseId:(NSString *)reuseId;

@optional
- (void)loopView:(KZBannerLoopView *)loopView didSelectIndex:(NSInteger)index;

@end

@interface KZBannerLoopView : UIView

@property (nonatomic, assign) NSInteger itemsCount;//item的总数量
@property (nonatomic, weak) id <KZBannerLoopViewDelegate> delegate;

@property (nonatomic, assign) NSTimeInterval timeInterval;//时间间隔，默认3秒一换

//pageControl相关
@property (nonatomic, strong) UIColor *pageIndicatorTintColor;
@property (nonatomic, strong) UIColor *currentPageIndicatorTintColor;
@property (nonatomic, assign) CGFloat edgeInsetBottom;      //底边距

@property (nonatomic, assign) BOOL isAutoLoop;//是否开启自动轮播，默认开启

- (__kindof UIView *)dequeueReusableItemWithIdentifier:(NSString *)identifier;//复用，用法类似UITableView

- (void)reloadData;//载入数据， 设置以上属性之后调用

@end

NS_ASSUME_NONNULL_END
