//
//  AwfulVoteActions.m
//  Awful
//
//  Created by Regular Berry on 6/23/11.
//  Copyright 2011 Regular Berry Software LLC. All rights reserved.
//

#import "AwfulVoteActions.h"
#import "AwfulThread.h"
#import "AwfulNavigator.h"
#import "ASIFormDataRequest.h"

@implementation AwfulVoteActions

@synthesize thread = _thread;

-(id)initWithAwfulThread : (AwfulThread *)thread
{
    if((self=[super init])) {
        _thread = [thread retain];
        [self.titles addObjectsFromArray:[NSArray arrayWithObjects:@"5", @"4", @"3", @"2", @"1", nil]];
    }
    return self;
}

-(void)dealloc
{
    [_thread release];
    [super dealloc];
}

-(NSString *)getOverallTitle
{
    return @"Vote!";
}

-(void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex
{
    // 0=5, 1=4, 2=3, 3=2, 4=1
    int vote_num = -1;
    switch (buttonIndex) {
        case 0:
            vote_num = 5;
            break;
        case 1:
            vote_num = 4;
            break;
        case 2:
            vote_num = 3;
            break;
        case 3:
            vote_num = 2;
            break;
        case 4:
            vote_num = 1;
            break;
        default:
            break;
    }
    
    if(vote_num != -1) {
        NSURL *url = [NSURL URLWithString:@"http://forums.somethingawful.com/threadrate.php"];
        ASIFormDataRequest *form = [ASIFormDataRequest requestWithURL:url];
        [form addPostValue:[[NSNumber numberWithInt:vote_num] stringValue] forKey:@"vote"];
        [form addPostValue:self.thread.threadID forKey:@"threadid"];
        form.userInfo = [NSDictionary dictionaryWithObject:@"Great Job!" forKey:@"completionMsg"];
        
        loadRequestAndWait(form);
    }
    [self.delegate setActions:nil];
}

@end
