//
//  AwfulActions.m
//  Awful
//
//  Created by Regular Berry on 6/23/11.
//  Copyright 2011 Regular Berry Software LLC. All rights reserved.
//

#import "AwfulActions.h"
#import "AwfulNavigator.h"
#import "AwfulAppDelegate.h"

@implementation AwfulActions

@synthesize titles = _titles;
@synthesize delegate = _delegate;

-(id)init
{
    if((self=[super init])) {
        _titles = [[NSMutableArray alloc] init];
        _delegate = nil;
    }
    return self;
}

-(void)dealloc
{
    [_titles release];
    [super dealloc];
}

-(NSString *)getOverallTitle
{
    return @"Actions";
}

-(void)show
{
    if(UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone) {
        UIActionSheet *sheet = [[UIActionSheet alloc] initWithTitle:[self getOverallTitle] delegate:self cancelButtonTitle:nil destructiveButtonTitle:nil otherButtonTitles:nil];
        for(NSString *title in self.titles) {
            [sheet addButtonWithTitle:title];
        }
        [sheet addButtonWithTitle:@"Cancel"];
        sheet.cancelButtonIndex = [self.titles count];
        
        AwfulNavigator *nav = getNavigator();
        [nav forceShow];
        [sheet showFromToolbar:nav.navigationController.toolbar];
        [sheet release];
    } else if(UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) {
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:[self getOverallTitle] message:nil delegate:self cancelButtonTitle:@"Cancel" otherButtonTitles:nil];
        for(NSString *title in self.titles) {
            [alert addButtonWithTitle:title];
        }
        [alert show];
        [alert release];
    }
}

- (void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex
{
}

-(void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    [self actionSheet:nil clickedButtonAtIndex:buttonIndex-1];
}

-(BOOL)isCancelled : (int)index
{
    return index == [self.titles count] || index == -1;
}

@end
