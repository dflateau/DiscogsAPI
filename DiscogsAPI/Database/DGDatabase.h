// DGDatabase.h
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
#import "DGSearch.h"
#import "DGArtist.h"
#import "DGArtistRelease.h"
#import "DGRelease.h"
#import "DGMaster.h"
#import "DGMasterVersion.h"
#import "DGLabel.h"
#import "DGLabelRelease.h"
#import "DGImage.h"
#import "DGMember.h"

@class DGOperation;

NS_ASSUME_NONNULL_BEGIN

/**
 Database class to manage operation with Discogs database.
 */
@interface DGDatabase : DGEndpoint

/**
 Searches in Discogs database.
 
 @param request The search request.
 @param success A block object to be executed when the search operation finishes successfully. This block has no return value and one argument: the search response.
 @param failure A block object to be executed when the synchronization operation finishes unsuccessfully. This block has no return value and takes one argument: The `NSError` object describing the error that occurred.
 */
- (void)searchFor:(DGSearchRequest *)request success:(void (^)(DGSearchResponse *response))success failure:(nullable DGFailureBlock)failure;

/**
 Gets an artist from Discogs database.
 
 @param artistID The requested artist ID.
 @param success  A block object to be executed when the get operation finishes successfully. This block has no return value and one argument: the artist.
 @param failure  A block object to be executed when the synchronization operation finishes unsuccessfully. This block has no return value and takes one argument: The `NSError` object describing the error that occurred.
 */
- (void)getArtist:(NSNumber *)artistID success:(void (^)(DGArtist *artist))success failure:(nullable DGFailureBlock)failure;

/**
 Gets an artist's releases.
 
 @param request The paginated artist releases request.
 @param success A block object to be executed when the get operation finishes successfully. This block has no return value and one argument: the paginated artist releases response.
 @param failure A block object to be executed when the synchronization operation finishes unsuccessfully. This block has no return value and takes one argument: The `NSError` object describing the error that occurred.
 */
- (void)getArtistReleases:(DGArtistReleasesRequest *)request success:(void (^)(DGArtistReleasesResponse *response))success failure:(nullable DGFailureBlock)failure;

/**
 Batch request a group of releases and get notified of updates
 
 @param releaseIDs an array of NSNumbers of all releases requested
 @param success Block object to be executed when a specific release request succeeds. ie if a batch of 100 requests is made, this could be called up to 100 times, once for each.
 @param failure Block object called when a specific release request fails (same conditions as above but for failure)
 @param progress Block called after each request finishes that contains both current index of finished request and total number of requests that were batched
 @param completion Block called when all requests have completed with the array of batched operations
 */
- (void)getReleases:(NSArray<NSNumber *> *)releaseIDs
            success:(void (^)(DGRelease* release))success
            failure:(nullable DGFailureBlock)failure
           progress:(nullable DGProgressBlock)progress
         completion:(nullable void (^)(NSArray<DGOperation *> *operations))completion;

/**
 Gets a release from Discogs database.
 
 @param releaseID The requested release ID.
 @param success   A block object to be executed when the get operation finishes successfully. This block has no return value and one argument: the release.
 @param failure   A block object to be executed when the synchronization operation finishes unsuccessfully. This block has no return value and takes one argument: The `NSError` object describing the error that occurred.
 */
- (void)getRelease:(NSNumber *)releaseID success:(void (^)(DGRelease *release))success failure:(nullable DGFailureBlock)failure;

/**
 Gets a master release from Dsicogs database.
 
 @param masterID The master ID.
 @param success  A block object to be executed when the get operation finishes successfully. This block has no return value and one argument: the master release.
 @param failure  A block object to be executed when the synchronization operation finishes unsuccessfully. This block has no return value and takes one argument: The `NSError` object describing the error that occurred.
 */
- (void)getMaster:(NSNumber *)masterID success:(void (^)(DGMaster *master))success failure:(nullable DGFailureBlock)failure;

/**
 Gets a label from Discogs database.
 
 @param labelID The label ID.
 @param success A block object to be executed when the get operation finishes successfully. This block has no return value and one argument: the label.
 @param failure A block object to be executed when the synchronization operation finishes unsuccessfully. This block has no return value and takes one argument: The `NSError` object describing the error that occurred.
 */
- (void)getLabel:(NSNumber *)labelID success:(void (^)(DGLabel *label))success failure:(nullable DGFailureBlock)failure;

/**
 Gets a labels's releases.
 
 @param request The paginated label's releases request.
 @param success A block object to be executed when the get operation finishes successfully. This block has no return value and one argument: the paginated label releases response.
 @param failure A block object to be executed when the synchronization operation finishes unsuccessfully. This block has no return value and takes one argument: The `NSError` object describing the error that occurred.
 */
- (void)getLabelReleases:(DGLabelReleasesRequest *)request success:(void (^)(DGLabelReleasesResponse *response))success failure:(nullable DGFailureBlock)failure;

/**
 Gets a master's versions
 
 @param request The master versions paginated request.
 @param success A block object to be executed when the get operation finishes successfully. This block has no return value and one argument: the paginated master releases response.
 @param failure A block object to be executed when the synchronization operation finishes unsuccessfully. This block has no return value and takes one argument: The `NSError` object describing the error that occurred.
 */
- (void)getMasterVersion:(DGMasterVersionsRequest *)request success:(void (^)(DGMasterVersionsResponse *response))success failure:(nullable DGFailureBlock)failure;

@end

NS_ASSUME_NONNULL_END
