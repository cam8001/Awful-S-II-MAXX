/*
 Copyright (c) 2010, Dante Torres All rights reserved.
 
 Redistribution and use in source and binary forms, with or without 
 modification, are permitted provided that the following conditions 
 are met:
 
 * Redistributions of source code must retain the above copyright 
 notice, this list of conditions and the following disclaimer.
 
 * Redistributions in binary form must reproduce the above copyright 
 notice, this list of conditions and the following disclaimer in the 
 documentation and/or other materials provided with the distribution.
 
 * Neither the name of the author nor the names of its 
 contributors may be used to endorse or promote products derived from 
 this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
 LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>


/*
	This protocol should be implemented by the delegate that will listen to javascript
	notifications. It is an extension of UIWebViewDelegate, this way you may listen to
	the regular UIWebView notifications (i.e. page did start loding, page loading error, etc.)
 */
@protocol JSBridgeWebViewDelegate <UIWebViewDelegate>
- (void)webView:(UIWebView*) webview didReceiveJSNotificationWithDictionary:(NSDictionary*) dictionary;
-(void)didScroll;
@end

/*
	JSBridgeWebView class is responsible for identifying javascript notifications. Its delegate must 
	comply with the JSBridgeWebViewDelegate.
 */
@interface JSBridgeWebView : UIWebView <UIWebViewDelegate> {

	/* 
		The external delegate that will listen to the javascript notifications.
		The UIWebView delegate is used internally for handling the notifications
		from javascript. The JSBridge API user does not need to worry about
		the bridgeDelegate.
	 */
	id<JSBridgeWebViewDelegate> bridgeDelegate;
}

@end
