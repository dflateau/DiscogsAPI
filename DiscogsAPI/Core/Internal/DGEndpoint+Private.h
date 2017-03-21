// DGEndpoint+Private.h
//
// Copyright (c) 2017 Maxime Epain
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

#import "DGEndpoint.h"
#import "DGObjectManager.h"

NS_ASSUME_NONNULL_BEGIN

/**
 `DGEndpoint` category to hold and configure the `DGObjectManager` with the endpoint specifications.
 */
@interface DGEndpoint (Private)

/**
 Whether or not the endpoint is reachable.
 */
@property (nonatomic, readonly) BOOL isReachable;

/**
 The `DGObjectManager`
 */
@property (nonatomic, readonly) DGObjectManager *manager;

/**
 Expose underlying queue so we can assign it to the manager's shared queue
 This is undoing the private queue scheme of mainline DiscogsAPI. This is a rate-limited service so it actually doesn't make sense to have private queues.
 */
@property (nonatomic, strong) NSOperationQueue *queue;

/**
 Initializes an endpoint and configure the `DGObjectManager`object.

 @param manager The manager to configure.

 @return The initialized endpoint.
 */
- (instancetype)initWithManager:(DGObjectManager *)manager;

/**
 Abstract method to configure the manager.

 @param manager The manager to configure.
 */
- (void)configureManager:(DGObjectManager *)manager;

@end

NS_ASSUME_NONNULL_END
