//
//  ALAdView.h
//  AppLovinSDK
//
//  Created by Basil on 3/1/12.
//  Copyright © 2020 AppLovin Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ALSdk.h"
#import "ALAdService.h"
#import "ALAdViewEventDelegate.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * This interface represents a view-based ad — i.e. banner, mrec, or leader.
 */
@interface ALAdView : UIView

/**
 * @name Ad Delegates
 */

/**
 * An object that conforms to the {@link ALAdLoadDelegate} protocol. If you provide a value for `adLoadDelegate` in your instance, this delegate will be
 * notified of ad load events.
 *
 * @warning This delegate is retained strongly and might lead to retain cycles if delegate holds strong reference to this `ALAdView`.
 */
@property (nonatomic, strong, nullable) IBOutlet id<ALAdLoadDelegate> adLoadDelegate;

/**
 * An object that conforms to the {@link ALAdDisplayDelegate} protocol. If you provide a value for `adDisplayDelegate` in your instance, this delegate will be
 * notified of ad show/hide events.
 *
 * @warning This delegate is retained strongly and might lead to retain cycles if delegate holds strong reference to this `ALAdView`.
 */
@property (nonatomic, strong, nullable) IBOutlet id<ALAdDisplayDelegate> adDisplayDelegate;

/**
 * An object that conforms to the {@link ALAdViewEventDelegate} protocol. If you provide a value for `adEventDelegate` in your instance, this delegate will be
 * notified of `ALAdView`-specific events.
 *
 * @warning This delegate is retained strongly and might lead to retain cycles if delegate holds strong reference to this `ALAdView`.
 */
@property (nonatomic, strong, nullable) IBOutlet id<ALAdViewEventDelegate> adEventDelegate;

/**
 * @name Ad View Configuration
 */

/**
 * The size of ads to load within this `ALAdView`.
 */
@property (nonatomic, strong) ALAdSize *adSize;

/**
 * The zone identifier this `ALAdView` was initialized with and is loading ads for, if any.
 */
@property (nonatomic, copy, readonly, nullable) NSString *zoneIdentifier;

/**
 * Whether or not this ad view should automatically load the ad when iOS inflates it from a StoryBoard or from a nib file (when {@link UIView::awakeFromNib} is
 * called). The default value is `NO` which means you are responsible for loading the ad by invoking {@link loadNextAd}.
 */
@property (nonatomic, assign, getter=isAutoloadEnabled, setter=setAutoloadEnabled:) BOOL autoload;

/**
 * @name Loading and Rendering Ads
 */

/**
 * Loads <em>and</em> displays an ad into the view. This method returns immediately.
 *
 * <b>Note:</b> To load the ad but not display it, use {@link ALSdk::shared}.{@link ALSdk::adService adService}
 * {@link ALAdService::loadNextAd:andNotify: loadNextAd:andNotify:} then {@link render:} to render it.
 */
- (void)loadNextAd;

/**
 * Renders a specific ad that was loaded via {@link ALAdService}.
 *
 * @param ad Ad to render.
 */
- (void)render:(ALAd *)ad;

/**
 * @name Initialization
 */

/**
 * Initializes the ad view with a given size.
 *
 * @param size {@link ALAdSize} that represents the size of this ad. For example, {@link ALAdSize.banner}.
 *
 * @return A new instance of `ALAdView`.
 */
- (instancetype)initWithSize:(ALAdSize *)size;

/**
 * Initializes the ad view for a given size and zone.
 *
 * @param size           {@link ALAdSize} that represents the size of this ad. For example, {@link ALAdSize.banner}.
 * @param zoneIdentifier Identifier for the zone this `ALAdView` should load ads for.
 *
 * @return A new instance of `ALAdView`.
 */
- (instancetype)initWithSize:(ALAdSize *)size zoneIdentifier:(nullable NSString *)zoneIdentifier;

/**
 * Initializes the ad view with a given SDK and size.
 *
 * @param sdk  Instance of {@link ALSdk} to use.
 * @param size {@link ALAdSize} representing the size of this ad. For example, {@link ALAdSize.banner}.
 *
 * @return A new instance of `ALAdView`.
 */
- (instancetype)initWithSdk:(ALSdk *)sdk size:(ALAdSize *)size;

/**
 * Initializes the ad view with a given SDK, size, and zone.
 *
 * @param sdk            Instance of {@link ALSdk} to use.
 * @param size           {@link ALAdSize} that represents the size of this ad. For example, {@link ALAdSize.banner}.
 * @param zoneIdentifier Identifier for the zone that this `ALAdView` should load ads for.
 *
 * @return A new instance of `ALAdView`.
 */
- (instancetype)initWithSdk:(ALSdk *)sdk size:(ALAdSize *)size zoneIdentifier:(nullable NSString *)zoneIdentifier;

/**
 * Initializes the ad view with a given frame, ad size, and ALSdk instance.
 *
 * @param frame  Describes the position and dimensions of the ad.
 * @param size   {@link ALAdSize} that represents the size of this ad. For example, {@link ALAdSize.banner}.
 * @param sdk    Instance of {@link ALSdk} to use.
 *
 * @return A new instance of `ALAdView`.
 */
- (instancetype)initWithFrame:(CGRect)frame size:(ALAdSize *)size sdk:(ALSdk *)sdk;
/**
 * Use {@link initWithSize:}, {@link initWithSize:zoneIdentifier:}, {@link initWithSdk:size:}, {@link initWithSdk:size:zoneIdentifier:}, or
 * {@link initWithFrame:size:sdk:} instead.
 */
- (instancetype)init NS_UNAVAILABLE;
/**
 * Use {@link initWithSize:}, {@link initWithSize:zoneIdentifier:}, {@link initWithSdk:size:}, {@link initWithSdk:size:zoneIdentifier:}, or
 * {@link initWithFrame:size:sdk:} instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
