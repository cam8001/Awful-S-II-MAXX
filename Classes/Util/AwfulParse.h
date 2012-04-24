//
//  AwfulParse.h
//  Awful
//
//  Created by Sean Berry on 10/7/10.
//  Copyright 2010 Regular Berry Software LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AwfulPageCount;
@class AwfulPost;
@class TFHpple;

@interface AwfulParse : NSObject {

}

+(NSString *)constructPageHTMLFromPosts : (NSMutableArray *)posts pagesLeft : (int)pages_left numOldPosts : (int)num_above adHTML : (NSString *)adHTML;
+(NSString *)getPostActionHTML;
+(NSString *)getModImgHTML;
+(NSString *)getAdminImgHTML;

+(NSMutableArray *)newPostsFromThread : (TFHpple *)hpple isFYAD : (BOOL)is_fyad;

+(NSString *)parseYouTubes : (NSString *)html;
+(NSString *)parseOutImages : (NSString *)html;

+(NSMutableArray *)newThreadsFromForum : (TFHpple *)hpple;
+(NSString *)getAdHTMLFromData : (TFHpple *)hpple;

+(AwfulPageCount *)newPageCount : (TFHpple *)hpple;
+(int)getNewPostNumFromURL : (NSURL *)url;

@end
