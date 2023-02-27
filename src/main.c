#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int width = 320;
int height = 200;
int gutter = 10;
int buttonCount = 0;

Rectangle buttonRects[10] = {0};
char *buttonTexts[10] = {0};
char *buttonScripts[10] = {0};

int main(int argc, char *argv[])
{
	if (argc < 3) {
		printf("You must provide at least 3 arguments: ./main \"window title\" \"button 1 text\" \"./button_1_script.sh\"\n");
		return 1;
	}

	for (int i = 2; i < argc && buttonCount < 10; i += 2)
	{
		buttonTexts[buttonCount] = argv[i];
		buttonScripts[buttonCount] = argv[i + 1];
		buttonCount++;
	}

	InitWindow(320, 200, argv[1]);

	int buttonHeight = (height - (gutter * (buttonCount + 1))) / buttonCount;

	for (int i = 0; i < buttonCount; i++)
	{
		int top = gutter + ((buttonHeight + gutter) * i);
		buttonRects[i].x = gutter;
		buttonRects[i].y = top;
		buttonRects[i].width = width - (gutter * 2);
		buttonRects[i].height = buttonHeight;
	}

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		for (int i = 0; i < buttonCount; i++)
		{
			if (GuiButton(buttonRects[i], buttonTexts[i]))
			{
				EndDrawing();
				BeginDrawing();
				ClearBackground(BLACK);
				DrawText(TextFormat("Running:\n%s", buttonScripts[i]), 10, 10, GetFontDefault().baseSize * 2, WHITE);
				EndDrawing();
				system(buttonScripts[i]);
				BeginDrawing();
			}
		}
		EndDrawing();
	}

	CloseWindow();
}