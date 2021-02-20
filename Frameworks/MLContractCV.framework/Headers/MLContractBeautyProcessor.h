//
//  MLContractBeautyProcessor.h
//  MLContractCV
//
//  Created by 杨乃川 on 2021/1/12.
//

#import <Foundation/Foundation.h>
#import "MLContractBeautySourceManager.h"


NS_ASSUME_NONNULL_BEGIN
@class MMFaceFeature;
@interface MLContractBeautyProcessorOption : NSObject
@property (nonatomic, assign) int orientation;
@property (nonatomic, assign) float landmarkScale;
@end


@interface MLContractBeautyProcessor : NSObject

+ (void)setLicenseURL:(NSURL *)url;
- (instancetype)init NS_UNAVAILABLE;
- (nullable instancetype)initWithModelDirectory:(NSURL *)modelDir error:(NSError **)error;

@end


@interface MLContractBeautyProcessor(Process)
- (CVPixelBufferRef)processPixelBuffer:(CVPixelBufferRef)inputPixelBuffer;
- (CVPixelBufferRef)processPixelBuffer:(CVPixelBufferRef)inputPixelBuffer option:(nullable MLContractBeautyProcessorOption *)option;
- (NSArray <MMFaceFeature *>*)processedFaceFeature;
@end


@interface MLContractBeautyProcessor(Beauty)

- (void)addBeautyItems:(NSArray <MLContractBeautySourceItem *> *)items;
- (void)removeBeautyItems:(NSArray <MLContractBeautySourceItem *> *)items;
- (void)updateBeautyItem:(MLContractBeautySourceItem *)item key:(NSString*)key intensity:(float)intensity;


/*
 nodes [absolute paths]
 */
- (void)addComposeNodes:(NSArray <NSString *> *)nodes;
- (void)removeComposeNodes:(NSArray <NSString *> *)nodes;
- (void)updateNode:(NSString *)node key:(NSString *)key intensity:(float)intensity;

- (void)addLutFilterNode:(NSString *)nodePath;
- (void)removeLutFilterNode:(NSString *)nodePath;
- (void)updateFilter:(NSString *)nodePath intensity:(float)intensity;
@end
NS_ASSUME_NONNULL_END