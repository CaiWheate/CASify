#include "background.h"

#include "../platform/fxlib.h"

// Following variables are static because they should not be accessed outside of background.c:

static UIMode uiMode = UIMODE_FULLSCREEN;
static UIStyle uiStyle = UISTYLE_STARS;

static int offsetX = 0; // x-offset increases when background is running.
static int offsetY = 0; // y-offset increases when background is running.

static int displayAreaWidth = SCREEN_WIDTH;
static int displayAreaHeight = SCREEN_HEIGHT;

void Background_startBackground()
{
	Background_setBackgroundStatus(UIMODE_BORDERED);
}
void Background_stopBackground()
{
	Background_setBackgroundStatus(UIMODE_FULLSCREEN);
}

void Background_setBackgroundStatus(UIMode uimode)
{
	uiMode = uimode;

	if (uimode == UIMODE_BORDERED)
	{
		offsetX = 1;
		offsetY = 1;

		displayAreaWidth = SCREEN_WIDTH - 2;
		displayAreaHeight = SCREEN_HEIGHT - 2;
	}
	else if (uimode == UIMODE_FULLSCREEN)
	{
		offsetX = 0;
		offsetY = 0;

		displayAreaWidth = SCREEN_WIDTH;
		displayAreaHeight = SCREEN_HEIGHT;
	}
}
void Background_setBackgroundStyle(UIStyle uistyle)
{
	uiStyle = uistyle;
}

UIMode Background_getBackgroundStatus()
{
	return uiMode;
}
UIStyle Background_getBackgroundStyle()
{
	return uiStyle;
}

// This layout information is exposed for printer to access:

int Background_getOffsetX()
{
	return offsetX;
}
int Background_getOffsetY()
{
	return offsetY;
}

int Background_getDisplayAreaWidth()
{
	return displayAreaWidth;
}
int Background_getDisplayAreaHeight()
{
	return displayAreaHeight;
}

void Background_render()
{
	int y;

	if (uiMode == UIMODE_FULLSCREEN) // Return is background is deactivated.
	{
		return;
	}

	locate(1, 1);
	
	switch (uiStyle)
	{
		case UISTYLE_STARS: Print((unsigned char*)"*********************"); break;
		case UISTYLE_LINES: Print((unsigned char*)"+-------------------+"); break;
		case UISTYLE_HASHTAGS: Print((unsigned char*)"#####################"); break;
		case UISTYLE_CIRCLES: Print((unsigned char*)"OOOOOOOOOOOOOOOOOOOOO"); break;
	}

	for (y = 2; y < SCREEN_HEIGHT; y++)
	{
		locate(1, y);

		switch (uiStyle)
		{
			case UISTYLE_STARS: Print((unsigned char*)"*                   *"); break;
			case UISTYLE_LINES: Print((unsigned char*)"|                   |"); break;
			case UISTYLE_HASHTAGS: Print((unsigned char*)"#                   #"); break;
			case UISTYLE_CIRCLES: Print((unsigned char*)"O                   O"); break;
		}
	}

	locate(1, SCREEN_HEIGHT);

	switch (uiStyle)
	{
		case UISTYLE_STARS: Print((unsigned char*)"*********************"); break;
		case UISTYLE_LINES: Print((unsigned char*)"+-------------------+"); break;
		case UISTYLE_HASHTAGS: Print((unsigned char*)"#####################"); break;
		case UISTYLE_CIRCLES: Print((unsigned char*)"OOOOOOOOOOOOOOOOOOOOO"); break;
	}
}