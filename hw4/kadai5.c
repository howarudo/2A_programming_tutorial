// 学籍番号： J4220368
// 名前：タンクルンホワルド
#include <stdio.h>
#include <string.h>

int roman2num(char*);
// set an array to hold key and value of roman numerals
// ex. key 'I' (ascii value of 'I' is used as index to be precise) will hold element 1
// (Idea taught by スンミン)
int romanArray[128];

int main() {
    // fill key(index) and value
    romanArray['I'] = 1;
    romanArray['V'] = 5;
    romanArray['X'] = 10;
    romanArray['L'] = 50;
    romanArray['C'] = 100;
    romanArray['D'] = 500;
    romanArray['M'] = 1000;
    printf("XIV = %d\n", roman2num("XIV"));
    printf("CDXCV = %d\n", roman2num("CDXCV"));
    printf("MCMXLV = %d\n", roman2num("MCMXLV"));
    printf("MMMCMXCIX = %d\n", roman2num("MMMCMXCIX"));
    return 0;
}

int roman2num(char *s) {
    int strLength = strlen(s);
    int ans = 0;
    for (int i = 0; i < strLength; i++){
        char roman = s[i];
        if ((i < strLength - 1) && (romanArray[roman] < romanArray[s[i+1]])) {
            // if the next roman numeral is bigger than current numeral, we subtract
            ans = ans - romanArray[roman];
        } else {
            ans = ans + romanArray[roman];
        }
    }
    return ans;
}
