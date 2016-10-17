// DGEndpoint+Configuration.h
//
// Copyright (c) 2016 Maxime Epain
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <DiscogsAPI/DGEndpoint.h>
#import <DiscogsAPI/DGOperation.h>

NS_ASSUME_NONNULL_BEGIN

#define DGCheckReachability(ret) { \
    if(!self.isReachable) { \
        if(failure) \
            failure([self errorWithCode:NSURLErrorNotConnectedToInternet info:@"Not connected"]); \
        return ret; \
    } \
}

#define DGCheckURL(url, ret) { \
    if( !url || [url isEqualToString:@""] ) { \
        if (failure) \
            failure([self errorWithCode:NSURLErrorZeroByteResource info:@"URL is empty"]); \
        return ret; \
    } \
}

/**
 `DGEndpoint` category to hold and configure the `RKObjectManager` with the endpoint specifications.
 */
@interface DGEndpoint (Configuration)

/**
 Whether or not the endpoint is reachable.
 */
@property (nonatomic, readonly) BOOL isReachable;

/**
 The `RKObjectManager`
 */
@property (nonatomic, readonly) RKObjectManager *manager;

/**
 Initializes an endpoint and configure the `RKObjectManager`object.

 @param manager The manager to configure.

 @return The initialized endpoint.
 */
- (instancetype)initWithManager:(RKObjectManager *)manager;

/**
 Abstract method to configure the manager.

 @param objectManager The manager to configure.
 */
- (void)configureManager:(RKObjectManager *)objectManager;

/**
 Create a `NSError`

 @param code The error code.
 @param info The error descritpion.

 @return The create error.
 */
- (NSError *)errorWithCode:(NSInteger)code info:(nullable NSString *)info;

@end

@interface RKErrorMessage (Mapping)

+ (RKMapping *)mapping;

+ (RKResponseDescriptor *)responseDescriptor;

@end

NS_ASSUME_NONNULL_END
