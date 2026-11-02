#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "school.h"

/**
 *  schools.txt ファイルから学校データを読み込む関数
 * Function to load school data from schools.txt file
 * schools.txt ဖိုင်မှ ကျောင်းအချက်အလက်များကို ဖတ်ယူသည့် Function
 */
int load_schools(School schools[], int max_schools) {
    // テキストファイルを読み込みモードで開く
    // Open the text file in read mode
    //  Text ဖိုင်ကို ဖတ်ရန်သီးသန့် (Read Mode) ဖြင့် ဖွင့်ခြင်း
    FILE *file = fopen("schools.txt", "r");
    if (file == NULL) {
        // ファイルが見つからない場合のエラー処理
        //  Error handling if the file is not found
        // ဖိုင်ရှာမတွေ့ပါက ပြသပေးမည့် Error Message
        printf("[Warning] schools.txt file not found! Please create the data file.\n");
        return 0;
    }

    int count = 0;
    char line[300];

    //  1行ずつ読み込み、区切り文字 '|' で分割して構造体に格納
    // Read line by line and parse into struct using '|' delimiter
    //  တစ်ကြောင်းစီ ဖတ်ယူပြီး '|' သင်္ကေတဖြင့် ခွဲခြားကာ Struct ထဲသို့ ထည့်ခြင်း
    while (fgets(line, sizeof(line), file) && count < max_schools) {
        sscanf(line, "%d|%[^|]|%[^|]|%[^|]|%[^\n]", 
               &schools[count].id, 
               schools[count].name, 
               schools[count].location, 
               schools[count].category, 
               schools[count].open_campus_url);
        
        schools[count].review_count = 0; // JP: レビュー数の初期化 / EN: Initialize review count / MM: Review အရေအတွက် စတင်သတ်မှတ်ခြင်း
        count++;
    }

    //  ファイルを閉じ、読み込んだ件数を返す
    // Close the file and return total school count
    // ဖိုင်ကို ပိတ်ပြီး ဖတ်ရရှိသော ကျောင်းအရေအတွက်ကို Return ပြန်ခြင်း
    fclose(file);
    return count; 
}
