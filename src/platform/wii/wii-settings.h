/* Copyright (c) 2015 Juan Carlos Ruvalcaba
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

struct WiiSettings{
	char fullRomPath[256];
	int render;
	int video_mode;
	int reduceScale;
	bool useCustomInput;
	char buttonA[5];
	char buttonB[5];
	char buttonL[5];
	char buttonR[5];
};

extern struct WiiSettings wiiSettings;

void _wiiParseArgs(int argc, char *argv[]);
void _fixInvalidSettings();
