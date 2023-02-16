/**
 * @file SimpleHelloWorldProgram.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-16
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>

#define CECI_EST_UNE_MACRO_DÉSIGNANT_UNE_FONCTION_MAIN int main(int argc, char const *argv[]) {

#define CECI_EST_UNE_MACRO_DÉSIGNANT_UNE_FIN_DE_FONCTION_MAIN }

int afficher_character_h_puis_e_puis_l_puis_l_puis_o_puis_espace_puis_w_puis_o_puis_r_puis_l_puis_d()
{
    int n = 0;

again:
    for (int i = n == 0 ? 'H' : n == 1 ? 'E' : (n == 2 || n == 3) ? 'L' : n == 4 ? 'O' : n == 5 ? ' ' : n == 6 ? 'W' : n == 7 ? 'O' : n == 8 ? 'R' : n == 9 ? 'L' : n == 10 ? 'D' : 0; i;)
    {
        std::cout << (char)i;
        ++n;
        if (i)
        {
            goto again;
        }
    }
    return 0;
CECI_EST_UNE_MACRO_DÉSIGNANT_UNE_FIN_DE_FONCTION_MAIN

CECI_EST_UNE_MACRO_DÉSIGNANT_UNE_FONCTION_MAIN
    afficher_character_h_puis_e_puis_l_puis_l_puis_o_puis_espace_puis_w_puis_o_puis_r_puis_l_puis_d();
    return INT32_MAX;
CECI_EST_UNE_MACRO_DÉSIGNANT_UNE_FIN_DE_FONCTION_MAIN
