#ifndef BACKGROUND_H
#define BACKGROUND_H

#define SCREEN_WIDTH 21
#define SCREEN_HEIGHT 8

typedef enum
{
	UIMODE_FULLSCREEN = 0,
	UIMODE_BORDERED = 1
} UIMode;

typedef enum
{
	UISTYLE_STARS = 0,
	UISTYLE_LINES = 1,
	UISTYLE_HASHTAGS = 2,
	UISTYLE_CIRCLES = 3
} UIStyle;

void Background_startBackground();
void Background_stopBackground();

void Background_setBackgroundStatus(UIMode uimode);
void Background_setBackgroundStyle(UIStyle uistyle);

UIMode Background_getBackgroundStatus();
UIStyle Background_getBackgroundStyle();

// This layout information is exposed for printer to access:

int Background_getOffsetX();
int Background_getOffsetY();

int Background_getDisplayAreaWidth();
int Background_getDisplayAreaHeight();

void Background_render();

#endif