// DGOperation.h
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

#import <RestKit/RestKit.h>

#import "DGMapping.h"

NS_ASSUME_NONNULL_BEGIN

/**
 `DGOperation` is an `RKObjectRequestOperation` subclass that uses `DGResponseObject` class to perform response mapping.
 */
@interface DGOperation<DGResponseType> : RKObjectRequestOperation

/**
 The operation response.
 */
@property (nonatomic, nullable, readonly) DGResponseType response;

/**
 Creates and initializers an operation with the given URL request and map to the response class.

 @param request       The request object to be used with the underlying network operation.
 @param responseClass An class adopting the `DGResponseObject` protocol specifying how object mapping is to be performed on the response loaded by the network operation.

 @return The newly-initialized operation.
 */
+ (instancetype)operationWithRequest:(NSURLRequest *)request responseClass:(nullable Class<DGResponseObject>)responseClass;

/**
 Initializers an operation with the given URL request and map to the response class.

 @param request       The request object to be used with the underlying network operation.
 @param responseClass An class adopting the `DGResponseObject` protocol specifying how object mapping is to be performed on the response loaded by the network operation.

 @return The initialized operation.
 */
- (instancetype)initWithRequest:(NSURLRequest *)request responseClass:(nullable Class<DGResponseObject>)responseClass;

/**
 Sets the `completionBlock` property with a block that executes either the specified success or failure block, depending on the state of the object request on completion. 
 If `error` returns a value, which can be set during HTTP transport by the underlying `HTTPRequestOperation` or during object mapping by the `DGResponseObject` protocol, then `failure` is executed. 
 If the object request operation is cancelled, then the failure block will be executed with either a `RKOperationCancelledError` or a `NSURLErrorCancelled`, depending on the internal state of the operation at time of cancellation. Otherwise, `success` is executed.

 @param success The block to be executed on the completion of a successful operation. This block has no return value and takes one argument: the response object.
 @param failure The block to be executed on the completion of an unsuccessful operation. This block has no return value and takes two arguments: the receiver operation and the error that occurred during the execution of the operation.
 */
- (void)setCompletionBlockWithSuccess:(void (^)(DGResponseType response))success failure:(nullable void (^)(NSError * _Nullable error))failure;

@end

/**
 NSError extension to create and map Discogs errors.
 
 Note: userInfo will contain the failing object operation via DGErrorRKObjectOperationKey as an RKObjectionRequestOperation
 */
@interface NSError (Mapping) <DGResponseObject>

@end

/**
 NSNull extension to accept empty body responses (e.g 204).
 */
@interface NSNull (Mapping) <DGResponseObject>

@end

NS_ASSUME_NONNULL_END
