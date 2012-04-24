//
//  AwfulHistory.h
//  Awful
//
//  Created by Regular Berry on 3/30/11.
//  Copyright 2011 Regular Berry Software LLC. All rights reserved.
//

typedef enum {
    AwfulHistoryTypeUnknown,
    AwfulHistoryTypePage,
    AwfulHistoryTypeThreadlist
} AwfulHistoryType;

@class AwfulPageCount;

@protocol AwfulHistoryRecorder;

@interface AwfulHistory : NSObject {
    AwfulHistoryType _historyType;
    int _pageNum;
    id _modelObj;
}

@property (nonatomic, assign) AwfulHistoryType historyType;
@property (nonatomic, assign) int pageNum;
@property (nonatomic, retain) id modelObj;

-(id)newThreadObj;

@end

@protocol AwfulHistoryRecorder <NSObject>

-(id)newRecordedHistory;
-(id)initWithAwfulHistory : (AwfulHistory *)history;
                             
@end