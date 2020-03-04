//
//  MMLiveSource.h
//  MLStreamPublisher
//
//  Created by hrs on 2020/2/6.
//

#ifndef MMLiveSource_h
#define MMLiveSource_h
#import <Foundation/Foundation.h>
#import "MMCommonParam.h"
#import <MLVideoProcessing/MLCameraSource.h>
@interface MMLiveSource : NSObject

#pragma mark - 音视频输出的对象
/**
* 添加视频输出对象
*
* @param outputSource 输出到的实例对象
*/
- (void) addVideoOutputSource:(id)outputSource;

/**
* 去除视频输出对象
*
* @param outputSource 输出到的实例对象
*/
- (void) removeVideoOutputSource:(id)outputSource;

#pragma mark - 视频输入和预览
/**
* 设置使能视频外部采集
*
* @param enable YES 打开SDK外部采集， NO SDK自采集
*/
- (void) setEnableExternalCapture:(BOOL)enable;

/**
* 设置预览大小
*
* @param width 预览宽
* @param height 预览高
*/
- (void) setPreviewSize:(NSInteger)width height:(NSInteger)height;

/**
* 选择渲染方式
*
* @param renderMode 0 GPU渲染,1 metal 渲染
*/
- (void) setRenderMode:(MMLiveRenderMode)renderMode;

/**
* 开始预览
*
* @param cameraId 0 代表后置摄像头 ，1 代表前置摄像头
* @param view 预览视图
*/
- (void) startPreview:(NSInteger)cameraId view:(UIView*)view;

/**
* 停止预览
*
*/
- (void) stopPreview;

/**
* 切换前后摄像头
*
*/
- (int) switchCamera;

/**
* 用户发送自定义，需要用户定时每帧都输入
*
* @param sampleBuffer 用户z采集的视频
*/
- (void) sendCustomVideoData:(CMSampleBufferRef)sampleBuffer;

#pragma mark - 语音输入和预览

/**
* 添加音频输出对象
*
* @param outputSource 输出到的实例对象
*/
- (void) addAudioOutputSource:(id)outputSource;

/**
* 去除音频输出对象
*
* @param outputSource 输出到的实例对象
*/
- (void) removeAudioOutputSource:(id)outputSource;

/**
* 开始SDK音频采集
*
* @param audioSampleRate 采样率
* @param audioChannels 声道数
*/
- (void) startAudioCapture:(NSInteger)audioSampleRate channels:(NSInteger)audioChannels;

/**
* 停止SDK音频采集
*
*/
- (void) stopAudioCapture;

/**
* 开启音频耳返
*
* @param enable YES 开启耳返，NO 关闭耳返
*/
- (void) setEarPhoneMonitor:(BOOL)enable;

#pragma mark - 视频特效

/**
* 使能水印功能
*
* @param enable YES 打开水印 NO关闭水印。
*/
- (void) setWatermarkEnabled:(BOOL)enable;

/**
* 设置磨皮等级
*
* @param level 0～1。
*/
- (void) setSmoothSkinLevel:(CGFloat)level;

/**
* 设置美白等级
*
* @param level 0～1。
*/
- (void) setWhitenSkinLevel:(CGFloat)level;

/**
* 设置大眼级别
*
* @param level 大眼级别，level 0～1。
*/
- (void) setEyeScaleLevel:(CGFloat)level;

/**
* 设置瘦脸级别
*
* @param level 大脸级别，level 0～1。
*/
- (void) setFaceScaleLevel:(CGFloat)level;

/**
* 设置削脸
*
* @param level 大脸级别，level -0.5 ~ 0.5。
*/
- (void) setFaceWidthLevel:(CGFloat)level;

/**
* 设置下巴
*
* @param level 下巴级别，level -0.5 ~ 0.5。
*/
- (void) setChinLengthLevel:(CGFloat)level;

/**
* 设置鼻子
*
* @param level 鼻子大小级别，level -0.5 ~ 0.5。
*/
- (void) setNoseSizeLevel:(CGFloat)level;

/**
* 设置嘴唇厚度
*
* @param level 嘴唇厚度级别，level -0.5 ~ 0.5。
*/
- (void) setLipThicknessLevel:(CGFloat)level;

/**
* 设置腮红
*
* @param level 腮红级别，level 0.0 ~ 1.0。
*/
- (void)setMakeUpBlushLevel:(CGFloat)level;

/**
* 设置修容
*
* @param level 修容级别，level 0.0 ~ 1.0。
*/
- (void)setMakeUpFaceShadow:(CGFloat)level;

/**
* 设置眼影
*
* @param level 眼影级别，level 0.0 ~ 1.0。
*/
- (void)setMakeUpEyeShadow:(CGFloat)level;

/**
* 设置指定素材滤镜特效
*
* @param filter 滤镜的lookup图片
* @param identifier 滤镜的唯一标示号
*/
- (void) setFilter:(MLFilterDescriptor *)filter withIdentifier:(int)identifier;

/**
* 设置指定素材滤镜特效的强度
*
* @param intensityValue 滤镜特效的强度
*/
- (void) setFilterintensity:(CGFloat) intensityValue;

/**
* 添加贴纸
*
* @param decoration 贴纸的描述
* @param identifier 贴纸的唯一标示号
*/
- (void) setSticker:(FDKDecoration*)decoration withIdentifier:(NSString *)identifier;

/**
* 去除贴纸
*
* @param identifier 贴纸的唯一标示号
*/
- (void) removeStickerWithIdentifier:(NSString *)identifier;;

/**
* 添加手势
*
* @param decoration 手势资源描述
*/
- (void) addGesture:(NSArray<MLObjectTriggeredDecoration *> *)decoration ;

/**
* 去除手势
*
* @param decoration 手势资源描述
*/
- (void) removeGesture:(MLObjectTriggeredDecoration*) decoration;

#pragma mark - 语音特效

/**
* 设置语音EQ
*
* @param value -4 - 4(0, disable)
*/
- (void) setEqValue:(NSInteger)value;

/**
* 设置语音声音pitch的参数
*
* @param value 说话声音pitch的参数
*/
- (void) setPitchValue:(NSInteger)value;

/**
* 设置语音特效
*
* @param value 特效枚举
*/
- (void) setAeFilterValue:(MMLiveAEFilter) value;

/**
* 设置语音降噪
*
* @param level 0 - 4(0, disable)
*/
- (void) setDenoiseLevel:(NSInteger)level;

#pragma mark - 背景音乐

/**
* 设置播放背景音乐
*
* @param url 音乐地址
* @param loopback 是否循环 YES 循环 NO 不循环
* @param repeatCount 循环次数
*/
- (void) playMusicWithUrl:(NSString*) url loopback:(BOOL) loopback repeatCount:(int)repeatCount;

/**
* 停止音乐播放
*
*/
- (void) stopMusic;

/**
* 暂停音乐播放
*
*/
- (void) pauseMusic;

/**
* 恢复音乐播放
*
*/
- (void) resumeMusic;

/**
* seek播放位置
*
* @param pos 播放位置 单位ms
*/
- (void) seekMusic:(NSInteger)pos;

/**
* 获取当前播放位置 单位ms
*
*/
- (NSInteger) musicCurrentPosition;

/**
* 获取播放文件总长度 单位ms
*
*/
- (NSInteger) musicDuration;

/**
* 设置音乐播放的pitch
*
* @param value 设置音频pitch
*/
- (void) setMusicPitch:(NSInteger)value;

#pragma mark - 音效

/**
* 设置播放音效
*
* @param effectid 音效id
* @param url 播放地址
* @param loopEnable 是否循环播放
* @param publishEnable 是否推送到远端
*/
- (void) playEffect:(NSInteger)effectid url:(NSString*)url loopEnable:(BOOL) loopEnable publishEnable:(BOOL)publishEnable;

/**
* 停止某个音效的声音
*
*@param effectid 音效标识
*/
- (void) stopEffect:(NSInteger)effectid;

/**
* 停止所有音效播放
*
*/
- (void) stopAllEffect;

/**
* 设置某个音效的声音
*
*@param effectid 音效标识
*@param volume 音量大小
*/
- (void) setEffectVolumeWithId:(NSInteger)effectid volume:(CGFloat)volume;

/**
* 设置所有音效的声音
*
*@param volume 音量大小
*/
- (void) setEffectsVolume:(CGFloat)volume;
@end

#endif /* MMLiveSource_h */