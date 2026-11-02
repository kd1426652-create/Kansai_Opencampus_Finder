#ifndef UI_HELPERS_H
#define UI_HELPERS_H

#include <stdio.h>
#include <stdlib.h>

/**
 *  画面をクリアする関数 (Windows / Mac / Linux 対応)
 *  Function to clear the console screen
 *  Terminal Screen ကို ရှင်းပေးသည့် Function
 */
void clear_screen() {
    #ifdef _WIN32
        system("cls");   // Windows 用 (For Windows / Windows အတွက်)
    #else
        system("clear"); // Mac/Linux 用 (For Mac/Linux / Mac နဲ့ Linux အတွက်)
    #endif
}

/**
 * ユーザーが Enter キーを押すまで一時停止する関数
 * Function to pause execution until the user presses ENTER
 * စာဖတ်ချိန်ရအောင် Pause လုပ်ပြီး Enter ခလုတ်နှိပ်တာကို စောင့်ပေးသည့် Function
 */
void pause_screen() {
    printf("\n-----------------------------------------\n");
    printf("Press ENTER to return to Main Menu / メインメニューに戻るには ENTER を押してください...");
    fflush(stdout);
    getchar(); // バッファをクリア (Clear previous input buffer / ရိုက်ထားသည့် buffer ကို ရှင်းခြင်း)
    getchar(); // ENTER キーの入力を待つ (Wait for ENTER key press / Enter ခလုတ်ကို စောင့်ခြင်း)
}

/**
 *  指定された Open Campus URL をデフォルトのブラウザで開く関数
 * Function to open the specified Open Campus URL in the default browser
 * Web Browser တွင် Open Campus Link ကို တိုက်ရိုက်ပွင့်စေသည့် Function
 */
void open_url(const char *url) {
    char command[300];
    #ifdef _WIN32
        sprintf(command, "start %s", url);    // Windows 用 (For Windows)
    #elif __APPLE__
        sprintf(command, "open %s", url);     // Mac 用 (For Mac)
    #else
        sprintf(command, "xdg-open %s", url); // Linux 用 (For Linux)
    #endif
    system(command);
}

#endif
