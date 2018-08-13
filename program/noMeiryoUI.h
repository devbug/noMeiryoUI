﻿/*
noMeiryoUI (C) 2005,2012-2018 Tatsuhiko Shoji
The sources for noMeiryoUI are distributed under the MIT open source license
*/
#ifndef NOMEIRYOUI_H
#define NOMEIRYOUI_H

#include "DialogAppliBase.h"
#include "TwrMenu.h"

void initializeLocale(void);
BOOL CALLBACK MonitorNearMouseCallback(
	HMONITOR hMonitor,
	HDC hdcMonitor,
	LPRECT lprcMonitor,
	LPARAM dwData
);
BOOL CALLBACK MonitorNearWindowCallback(
	HMONITOR hMonitor,
	HDC hdcMonitor,
	LPRECT lprcMonitor,
	LPARAM dwData
);
BOOL CALLBACK setWindowSize(HWND hWnd, LPARAM lparam);


class NoMeiryoUI : public DialogAppliBase {
private:

	enum fontType {
		all,
		title,
		icon,
		palette,
		hint,
		message,
		menu
	};

	tstring allFontName;
	tstring titleFontName;
	tstring iconFontName;
	tstring paletteFontName;
	tstring hintFontName;
	tstring messageFontName;
	tstring menuFontName;

	NONCLIENTMETRICS metrics;
	LOGFONT iconFont;

	NONCLIENTMETRICS metricsAll;
	LOGFONT iconFontAll;

	bool noMeiryoUI;
	bool noTahoma;
	TwrWnd *verInfo;

	TwrMenu *appMenu;

	HFONT displayFont;

	HFONT allFont;
	HFONT titleFont;
	HFONT iconFontHandle;
	HFONT paletteFont;
	HFONT hintFont;
	HFONT messageFont;
	HFONT menuFont;

	TwrWnd *allFontTextBox;
	TwrWnd *titleFontTextBox;
	TwrWnd *iconFontTextBox;
	TwrWnd *paletteFontTextBox;
	TwrWnd *hintFontTextBox;
	TwrWnd *messageFontTextBox;
	TwrWnd *menuFontTextBox;

	TCHAR settingFile[MAX_PATH];
	bool setOnStart;

	void OnLoad();
	BOOL loadFontInfo(TCHAR *filename);
	BOOL loadFont(TCHAR *filename, TCHAR *section, LOGFONT *font);
	void OnSave();
	BOOL startSaveFont(TCHAR *filename);
	BOOL saveFont(TCHAR *filename, TCHAR *section, LOGFONT *font);
	void selectFont(enum fontType type);
	void updateDisplay(void);

	INT_PTR OnBnClickedOk();
	void OnBnClickedAll();
	void OnSet8();
	void OnSet10(void);
	void SetWinVer(void);
	void getWin10Ver(TCHAR *buf, DWORD major, DWORD minor);
	int getDPI(void);

	void setFont(
		NONCLIENTMETRICS *fontMetrics,
		LOGFONT *iconLogFont
	);
	void showHelp(void);
	HFONT createFont(LOGFONT *font);
	void getActualFont(void);
	void getOption(TCHAR *lpCmdLine);
	void parseOption(TCHAR *param, int argCount);
	void applyResource();
	void showVersion(void);

protected:
	INT_PTR OnCommand(WPARAM wParam);

public:
	BaseDialog *createBaseDialog();
	int OnAppliStart(TCHAR *lpCmdLine);
	int OnWindowShow();
	int OnAppliEnd();
	INT_PTR OnInitDialog();
	void UpdateData(bool toObj);

};

#endif
