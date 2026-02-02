#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>



int main(int argc, const char* argv[]) {

    // Set the locale to support Unicode output
    setlocale(LC_ALL, "");
    long int hres = 0xF597E2FC;


    wprintf(L"    __                  _                                 _         _      _              ____                 __      __  \n"
        "   / /_  ___  ________ ( )_____       ____ _       ____  (_)___    (_)___ ( )  _____     / __/___ _____  _____/ /_  __/ /_ \n"
        "  / __ \\/ _ \\/ ___/ _ \\|// ___/      / __ `/      / __ \\/ / __ \\  / / __ `//  / ___/    / /_/ __ `/ __ \\/ ___/ / / / / __ \\\n"
        " / / / /  __/ /  /  __/ (__  )      / /_/ /      / / / / / / / / / / /_/ /   (__  )    / __/ /_/ / / / / /__/ / /_/ / /_/ /\n"
        "/_/ /_/\\___/_/   \\___/ /____/       \\__,_/      /_/ /_/_/_/ /_/_/ /\\__,_/   /____/    /_/  \\__,_/_/ /_/\\___/_/\\__,_/_.___/ \n"
        "                                                             /___/                                                         \n");


    wprintf(L"...Or so one would think ahahhahaha\n");

    wprintf(L"\nOh no! Looks like you need a secret key to proceed any further...\n");
    wprintf(L"\nPlease enter what you know here: ");



    wchar_t user_key[256];
    wscanf(L"%255s", user_key);
    long int myDecoy = 0x98A49FF0;
    
    wchar_t xored_key[256];
    for (size_t i = 0; i < wcslen(user_key); ++i) {
        if(i == 0){
            xored_key[i] = user_key[i] ^ myDecoy;
        }
        else{
            xored_key[i] = user_key[i];
        }
    }
    xored_key[wcslen(user_key)] = L'\0'; // Null-terminate the string

    if(wcscmp(xored_key, L"") == 0){
        wprintf(L"\nCongratulations!!! Here's what you may be looking for...\n");
        wprintf(L"Part 8 (fake): ");
        long int mres = hres - 0xB78;
        unsigned char res[4];
        for(size_t i = 0; i < 4; ++i){
            res[i] = ((mres >> (i * 8)) & 0xFF) ^ ((myDecoy >> (i * 8)) & 0xFF);
            wprintf(L"%lc", res[i]);
        }
        wprintf(L"\n");
    } else {
        wprintf(L"\nYa gotta try a little harder XD\n");
        return 1;
    }
    return 0;


   


}