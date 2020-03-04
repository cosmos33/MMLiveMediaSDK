//
//  MMLiveRTC.h
//  MLStreamPublisher
//
//  Created by hrs on 2020/2/6.
//

#ifndef MMLiveRTC_h
#define MMLiveRTC_h
#import <Foundation/Foundation.h>
#import "MMCommonParam.h"

@class MMLiveRTC;
#pragma mark - MMLiveRTCDelegate
@protocol MMLiveRTCDelegate <NSObject>

/**
推流器开始推流
*/
- (void)MMLiveRTCPushStarting:(MMLiveRTC *)pusher type:(MMLivePushType)type error:(NSError*)error;

/**
推流器停止推流
*/
- (void)MMLiveRTCPushStopped:(MMLiveRTC *)pusher type:(MMLivePushType)type error:(NSError*)error;

/**
推流器推流失败
*/
- (void)MMLiveRTCPushFailed:(MMLiveRTC *)pusher type:(MMLivePushType)type error:(NSError*)error;

/**
推流卡顿开始
*/
- (void)MMLiveRTCBufferStart:(MMLiveRTC *)pusher type:(MMLivePushType)type error:(NSError*)error;

/**
推流卡顿结束
*/
- (void)MMLiveRTCBufferStopped:(MMLiveRTC *)pusher type:(MMLivePushType)type error:(NSError*)error;

/**
推流数据到达cdn（经验值），只用于平滑切换的优化方案
*/
- (void)MMLiveRTCPushReplaced:(MMLiveRTC *)pusher type:(MMLivePushType)type error:(NSError*)error;

/**
用户自己加入频道
*/
- (void)MMLiveRTC:(MMLiveRTC *)pusher hostDidJoinChannel:(NSString *)channel type:(MMLivePushType)type;

/**
其他用户加入频道
*/
- (void)MMLiveRTC:(MMLiveRTC *)pusher didMemberJoinChannel:(NSString *)channel withUid:(NSUInteger)uid type:(MMLivePushType)type;

/**
其他用户退出频道
*/
- (void)MMLiveRTC:(MMLiveRTC *)pusher MemberLeaveWithUserId:(NSString *)userId reason:(NSInteger)reason type:(MMLivePushType)type;

/**
用户离开频道
*/
- (void)MMLiveRTChostDidLeaveChannel:(MMLiveRTC *)pusher type:(MMLivePushType)type;

/**
其他用户掉线
*/
- (void)MMLiveRTC:(MMLiveRTC *)pusher didMemberOfflineWithUid:(NSString *)uid type:(MMLivePushType)type;

/**
收到其他用户第一帧视频
*/
- (void)MMLiveRTC:(MMLiveRTC *)pusher didReceivedFirstVideoFrameWithRemoteId:(NSString *)uid remoteView:(UIView *)remoteView type:(MMLivePushType)type;

/**
其他用户声音是否静音
*/
- (void)MMLiveRTC:(MMLiveRTC *)pusher didMemberAudioMuted:(BOOL)muted remoteUid:(NSUInteger)uid type:(MMLivePushType)type;

/**
其他用户画面是否关闭
*/
- (void)MMLiveRTC:(MMLiveRTC *)pusher didMemberVideoMuted:(BOOL)muted remoteUid:(NSUInteger)uid type:(MMLivePushType)type;

/**
连线错误
*/
- (void)MMLiveRTC:(MMLiveRTC *)pusher didOccurError:(RTCErrorCode)errorCode type:(MMLivePushType)type;
@end


@interface MMLiveRTC: NSObject

- (instancetype) initWithUserConfig:(MMLiveUserConfig *)userConfig;
/**
设置代理
*/
@property (nonatomic, weak) id<MMLiveRTCDelegate> delegate;

/**
获取MMLivePusherConfig
*/
@property (nonatomic, readonly, strong) MMLiveMediaConfig *pusherConfig;

@property (nonatomic, strong) MMLiveUserConfig *userConfig;

@property (nonatomic, strong) id sourceHandle;

/**
设置用户角色
@param role 角色类型
*/
- (void)setClientRole:(MMLiveRTCClientRole)role;

/**
设置进房参数
@param config 配置结构体
*/
- (void)setRoomParams:(MMLiveRoomParams *)config;

/**
更新channelKey
@param channelKey 动态key
*/
- (void)updateChannelKey:(NSString *)channelKey;

/**
进房
@param config 进房信息
*/
- (int)enterRoom:(MMLiveMediaConfig *)config;

/**
退房
*/
- (void)leaveRoom;

/**
设置SEI
@param sei sei结构体
*/
- (int)setLinkSei:(MMLiveSei *)sei;

/**
是否发送本地音频
@param audioMute 本地视频发送开关
*/
- (void)setLocalAudioMute:(BOOL)audioMute;

/**
是否发送本地视频
@param videoMute 本地视频发送开关
*/
- (void)setLocalVideoMute:(BOOL)videoMute;

/**
是否禁止所有的远端音频
@param audioMute 静音开关
*/
- (void)setAllRemoteAudioMute:(BOOL)audioMute;

/**
是否禁止所有的远端视频
@param videoMute 远端视频禁用开关
*/
- (void)setAllRemoteVideoMute:(BOOL)videoMute;

/**
禁止远端某个uid音频
@param mute 静音开关
@param userId 用户id
*/
- (void)setRemoteAudioStreamMute:(BOOL)mute forUser:(NSString *)userId;

/**
禁止远端某个uid视频
@param mute 视频禁用开关
@param userId 用户id
*/
- (void)setRemoteVideoStreamMute:(BOOL)mute forUser:(NSString *)userId;

/**
大小流切换开关
@param mute 切换开关
@param userId 用户id
*/
- (void)setRemoteDualVideoStreamMute:(BOOL)mute forUser:(NSString *)userId;

/**
发起跨房pk
@param roomId 房间id
@param userId 用户id
*/
- (void)accrossOtherRoomWithRoomId:(NSString *)roomId userId:(NSString *)userId;

/**
结束跨房pk
@param roomid 房间id
*/
- (void)unaccrossOtherRoom:(NSString *)roomid;

/**
使能软回声消除
@param enable 软回声消除开关
*/
- (void)enableSoftAEC:(BOOL)enable;

/**
使能媒体音频采集
@param enable 媒体音频采集开关
*/
- (void)enableRemoteIO:(BOOL)enable;

/**
设置连线播放是外放还是听筒
@param enable 外放开关
*/
- (void)setConferencePlaybackSpeakerphone:(BOOL)enable;

/**
调整远端用户的音量
@param volumeScale 音量
@param userId 用户id
*/
- (void)adjustRemoteUserVolmue:(float)volumeScale forUser:(NSString *)userId;

/**
调整混屏的背景图片
@param url 背景图片地址
*/
- (void)updateConferenceBackgroundImage:(NSURL *)url;

/**
更新混屏画布的尺寸
@param size 混屏画布尺寸
*/
- (void)updateCanvasSize:(CGSize)size;

/**
打开与web sdk的互通功能
@param enable 开关
*/
- (void)setEnableWebSdkInteroperability:(BOOL)enable;

/**
重新推流功能
@param url 推流地址
*/
- (void)setRestartWithURL:(NSURL *)url;
@end

#endif /* MMLiveRTC_h */