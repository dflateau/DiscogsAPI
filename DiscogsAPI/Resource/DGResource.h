// DGResource.h
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

NS_ASSUME_NONNULL_BEGIN

@class UIImage;

/**
 Resource class to manage Discogs resources.
 */
@interface DGResource : DGEndpoint

/**
 The resource endpoint dispatches request on its own operation queue.
 */
@property (nonatomic, strong) NSOperationQueue *operationQueue;

/**
 Proxy server url. (@example https://github.com/hendriks73/coxy )
 */
@property (nonatomic, strong, nullable) NSString *proxyURL;

/**
 Gets a Discogs image
 
 @param imageURL The Discogs image URL.
 @param success  A block object to be executed when the get operation finishes successfully. This block has no return value and one argument: the image.
 */
- (void)getImage:(NSString *)imageURL success:(void (^)(UIImage *image))success NS_SWIFT_NAME(get(image:success:));

/**
 Gets a Discogs image
 
 @param imageURL The Discogs image URL.
 @param success  A block object to be executed when the get operation finishes successfully. This block has no return value and one argument: the image.
 @param failure  A block object to be executed when the synchronization operation finishes unsuccessfully. This block has no return value and takes one argument: The `NSError` object describing the error that occurred.
 */
- (void)getImage:(NSString *)imageURL success:(void (^)(UIImage *image))success failure:(nullable DGFailureBlock)failure NS_SWIFT_NAME(get(image:success:failure:));

/**
 Creates a image request operation.
 
 @param url     The Discogs image URL.
 @param success A block object to be executed when the get operation finishes successfully. This block has no return value and one argument: the image.
 @param failure A block object to be executed when the synchronization operation finishes unsuccessfully. This block has no return value and takes one argument: The `NSError` object describing the error that occurred.
 
 @return The Coxy image request operation.
 */
- (NSOperation *)createImageRequestOperationWithUrl:(NSString *)url success:(void (^)(UIImage *image))success failure:(nullable DGFailureBlock)failure;

@end

NS_ASSUME_NONNULL_END
