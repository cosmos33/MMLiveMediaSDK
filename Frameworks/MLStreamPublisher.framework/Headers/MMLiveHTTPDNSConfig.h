//
//  MMLiveHTTPDNSConfig.h
//
//  Created by Lihao on 2020/4/18.
//

#import <Foundation/Foundation.h>
#import <PhotonHTTPDNS/PhotonHTTPDNSConfigProtocol.h>
#import "MMLiveContext.h"
NS_ASSUME_NONNULL_BEGIN

@interface MMLiveHTTPDNSConfig : NSObject<PhotonHTTPDNSConfigProtocol>
- (void)updateInfoWithContext:(MMLiveUserContext *)context;
@end

NS_ASSUME_NONNULL_END
