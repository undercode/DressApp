//
//  ConjuntoPrendaView.h
//  DressApp
//
//  Created by Javier Sanchez Sierra on 11/2/11.
//  Copyright (c) 2011 Javier Sanchez Sierra. All rights reserved.
//
// This file is part of DressApp.

// DressApp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// DressApp is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
//
// Permission is hereby granted, free of charge, to any person obtaining 
// a copy of this software and associated documentation files (the "Software"), 
// to deal in the Software without restriction, including without limitation the 
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or 
// sell copies of the Software, and to permit persons to whom the Software is furnished 
// to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN 
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

//https://github.com/jsanchezsierra/DressApp


#import <UIKit/UIKit.h>
#import "ConjuntoPrendas.h"

@protocol ConjuntoPrendaViewDelegate;

typedef enum 
{
    InitialTouchOfTypeNone = 0,    
    InitialTouchOfTypeRemove = 1,    
    InitialTouchOfTypeMove = 2,    
    InitialTouchOfTypeScale =3,  
} InitialTouchOfType;

@interface ConjuntoPrendaView : UIView <UIGestureRecognizerDelegate>
{
    BOOL isSelected;
    UITouch *secondTouch;
    UIColor *selectedColor;
    BOOL isVibrating;
    BOOL isScaled;
    float previousScale;
    CGRect initialFrame;
    NSTimer *myTimer;
    NSInteger timeCounterEnter;
    NSInteger timeCounterExit;
    UITouch *initialTouch;
    BOOL isCapturingFirstTouching;
    UIImageView *prendaImageViewBackground;
    InitialTouchOfType initialTouchType;
    CGPoint firstLocation;
}

@property (nonatomic, assign) id <ConjuntoPrendaViewDelegate> delegate;
@property (nonatomic, strong) UIImageView *prendaImageView;
@property (nonatomic, strong) ConjuntoPrendas *conjuntoPrenda;
@property (nonatomic, assign) float escala;
@property (nonatomic, assign) BOOL prendaDeleted;
@property (nonatomic, assign) BOOL isWaitingForDisappear;

-(void) initView;
-(void) selectConjuntoPrenda;
-(void) deselectConjuntoPrenda;
-(void) updateImageViewsPosition;
-(void) checkInitialTochType;
-(void) touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event;
-(void) touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event;
-(void) touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event;
-(void) touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event;
                    
@end


@protocol ConjuntoPrendaViewDelegate

- (void)ConjuntoPrendaViewDelegate:(ConjuntoPrendaView*)conjuntoPrendaView  didChangePrendaToPositionX:(NSInteger)positionX positionY:(NSInteger)positionY imageWidth:(NSInteger)width imageHeight:(NSInteger)height;
-(void) deselectConjuntoPrendaViewsExceptThis:(ConjuntoPrendaView*)selectedConjuntoPrendaView;
-(void) enableScroll:(BOOL)scrollEnabled  ;
-(void) removePrendaFromConjunto:(ConjuntoPrendas *)conjuntoPrenda withView:(ConjuntoPrendaView*)myView;
-(void) updateConjuntoPrendaViewControlPositionFromView:(ConjuntoPrendaView*)selectedConjuntoPrendaView setHidden:(BOOL)hiddenMode;

@end
