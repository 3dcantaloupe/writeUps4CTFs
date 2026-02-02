#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>


void print_wchar_Hex(const wchar_t* warr) {
    wprintf(L"Hex values: ");
    for (int i = 0; warr[i] != L'\0'; ++i) {
        // Cast the wchar_t to an unsigned int for the %X format specifier
        wprintf(L"0x%0*X ", (int)sizeof(wchar_t) * 2, (unsigned int)warr[i]);
    }
    wprintf(L"\n");
}

int main(int argc, const char* argv[]) {

    // Set the locale to support Unicode output
    setlocale(LC_ALL, "");
    long int hres = 0xD3E4B7FA;


    wprintf(L"    __                  _                                 _         _      _              ____                 __      __  \n"
        "   / /_  ___  ________ ( )_____       ____ _       ____  (_)___    (_)___ ( )  _____     / __/___ _____  _____/ /_  __/ /_ \n"
        "  / __ \\/ _ \\/ ___/ _ \\|// ___/      / __ `/      / __ \\/ / __ \\  / / __ `//  / ___/    / /_/ __ `/ __ \\/ ___/ / / / / __ \\\n"
        " / / / /  __/ /  /  __/ (__  )      / /_/ /      / / / / / / / / / / /_/ /   (__  )    / __/ /_/ / / / / /__/ / /_/ / /_/ /\n"
        "/_/ /_/\\___/_/   \\___/ /____/       \\__,_/      /_/ /_/_/_/ /_/_/ /\\__,_/   /____/    /_/  \\__,_/_/ /_/\\___/_/\\__,_/_.___/ \n"
        "                                                             /___/                                                         \n");


    wprintf(L"Oh no! Looks like you need a secret key to proceed any further...\n");
    wprintf(L"\nPlease enter what you know here: ");



    wchar_t user_key[256];
    wscanf(L"%255s", user_key);
    long int myNinja = 0xAC2B4FF0;
    

   

    // for(size_t i = 0; i < 4; ++i){
    //     wprintf(L"%lc", ((wchar_t*)(&myNinja))[i]);
    // }
    

    // wprintf(L"Thank you! You entered: %ls\n", user_key);
    
    wchar_t xored_key[256];
    for (size_t i = 0; i < wcslen(user_key); ++i) {
        if(i == 0){
            xored_key[i] = user_key[i] ^ myNinja + 0xB7A5000;
        }
        else{
            xored_key[i] = user_key[i];
        }
    }
    xored_key[wcslen(user_key)] = L'\0'; // Null-terminate the string

    if(wcscmp(xored_key, L"") == 0){
        wprintf(L"\nCongratulations!!! Here's what you may be looking for...\n");
        wprintf(L"Part 8: ");
        long int mres = hres - 0xB78;
        unsigned char res[4];
        for(size_t i = 0; i < 4; ++i){
            res[i] = ((mres >> (i * 8)) & 0xFF) ^ (((myNinja + 0xB7A5000) >> (i * 8)) & 0xFF);
            wprintf(L"%lc", res[i]);
        }
        wprintf(L"\n");
    } else {
        wprintf(L"\nYa gotta try a little harder XD\n");
        return 1;
    }

    // wprintf(L"Your secret key is: %ls\n", xored_key);
    // print_wchar_Hex(user_key);
    // print_wchar_Hex(xored_key);
    return 0;


    // char* emoji = "\U0001F977";
    // wchar_t ninja = L'\U0001F977'; 
    // wprintf(L"yay %lx\n", ninja);
    // printf("%p\n",emoji);
    // print_wchar_Hex(&ninja);

    // printf("%zu\n", wcslen(user_key));
    // printf("%s", user_key);

    // wchar_t xored_key = user_key ^ 0xfffffff0;
    // printf("Your secret key is: %x\n", xored_key);
   


}