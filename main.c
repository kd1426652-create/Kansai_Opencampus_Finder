#include <stdio.h>
#include "school.h"

// メニュー画面を表示する関数 (Show Main Menu Function)
void show_menu() {
    printf("\n=========================================\n");
    printf(" Kansai IT Open Campus Finder & Rating \n");
    printf("=========================================\n");
    printf("1. View All Schools (学校一覧表示)\n");
    printf("2. Search School / Link (学校・リンク検索)\n");
    printf("3. Add Review & Rating (レビュー・評価追加)\n");
    printf("4. Exit (終了)\n");
    printf("=========================================\n");
    printf("Select Option (1-4): ");
}

int main() {
    int choice;
    
    // ユーザーが終了(4)を選択するまで処理を繰り返す
    do {
        show_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                // 全学校データの表示機能 (Data Team の関数の呼び出し場所)
                printf("\n[Displaying Schools List...]\n");
                break;
            case 2:
                // Keyword検索機能 (Search Team の関数の呼び出し場所)
                printf("\n[Search Engine...]\n");
                break;
            case 3:
                // レビュー・評価追加機能 (Review Team の関数の呼び出し場所)
                printf("\n[Review & Rating System...]\n");
                break;
            case 4:
                // プログラムの終了処理
                printf("\nExiting Program. Thank you!\n");
                break;
            default:
                // 無効な入力への対応
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}
