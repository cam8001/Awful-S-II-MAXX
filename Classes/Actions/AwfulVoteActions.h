//
//  AwfulVoteActions.h
//  Awful
//
//  Created by Regular Berry on 6/23/11.
//  Copyright 2011 Regular Berry Software LLC. All rights reserved.
//

#import "AwfulActions.h"

@class AwfulThread;

@interface AwfulVoteActions : AwfulActions {
    AwfulThread *_thread;
}

@property (nonatomic, retain) AwfulThread *thread;

-(id)initWithAwfulThread : (AwfulThread *)thread;

@end
