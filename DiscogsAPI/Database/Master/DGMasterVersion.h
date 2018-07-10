// DGMasterVersion.h
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

#import "DGLabelRelease.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Master version description class.
 */
@interface DGMasterVersion : DGLabelRelease

/// denotes physical media formats. this has been moved out of DGMasterVersion.format on the server
@property (nonatomic, strong, nullable) NSArray<NSString *> *majorFormats;

@end

/**
 The master versions request.
 */
@interface DGMasterVersionsRequest : NSObject

/**
 The request pagination parameters.
 */
@property (nonatomic, strong) DGPagination *pagination;

/**
 Requested master ID.
 */
@property (nonatomic, strong) NSNumber *masterID;

@end

/**
 The paginated master versions response.
 */
@interface DGMasterVersionsResponse : NSObject <DGPaginated>

/**
 The master's versions requested.
 */
@property (nonatomic, strong) NSArray<DGMasterVersion *> *versions;

@end

NS_ASSUME_NONNULL_END
