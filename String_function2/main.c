/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainC03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:55:06 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/01/16 18:18:36 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "ex00/ft_strcmp.c"
#include "ex01/ft_strncmp.c"
#include "ex02/ft_strcat.c"
#include "ex03/ft_strncat.c"
#include "ex04/ft_strstr.c"
#include "ex05/ft_strlcat.c"

int	ft_strlen(char *str);

int main()
{
	printf("made by <jaeyojun>\n");
	printf("made by <jaeyojun>\n");
	printf("made by <jaeyojun>\n");
	//ex00
	printf("---------------ex00--------------\n");
	printf("\n");
	char s1[10] = "awd";
	char s2[10] = "awd";
	char s3[10] = "awd";
	char s4[10] = "awd";

	printf("----------case1-------------\n");
	printf("input\n");
	printf("s1: %s, s2: %s, ft_strcmp : %d\n",s1, s2, ft_strcmp(s1, s2));
	printf("answer\n");
	printf("s3: %s, s4: %s, strcmp : %d\n", s3, s4, strcmp(s3, s4));

	char s5[10] = "aa";
	char s6[10] = "c";
	char s7[10] = "aa";
	char s8[10] = "c";
	printf("----------case2-------------\n");
	printf("input\n");
	printf("s5: %s, s6: %s, ft_strcmp : %d\n", s5, 26, ft_strcmp(s5, s6));
	printf("answer\n");
	printf("s7, %s, s8: %s, strcmp : %d\n", strcmp(s7, s8));

	
	char s9[10] = "cc";
	char s10[10] = "a";
	char s11[10] = "cc";
	char s12[10] = "a";
	printf("----------case3-------------\n");
	printf("input\n");
	printf("ft_strcmp: %d\n", ft_strcmp(s9, s10));
	printf("answer\n");
	printf("strcmp: %d\n", strcmp(s11, s12));
	
	char	our_1[10] = {'H', 'E', 'L', 'L', 'O'};
	char	our_2[10] = {'H', 'E', 'L', 200, 'O'};
	char	our_3[10] = {'H', 'E', 'L', 'L', 'O'};
	char	our_4[10] = {'H', 'E', 'L', 200, 'O'};
	printf("----------case4-------------\n");
	printf("input\n");
	printf("ft_strcmp: %d\n", ft_strcmp(our_1, our_2));
	printf("answer\n");
	printf("strcmp: %d\n", strcmp(our_3, our_4));

	//ex01
	printf("\n");
	printf("---------------ex01--------------\n");
	printf("\n");

	char s13[10] = "awd";
	char s14[10] = "awd";
	char s15[10] = "awd";
	char s16[10] = "awd";
	unsigned int a = 2;
	printf("----------case1-------------\n");
	printf("input\n");
	printf("ft_strncmp : %d\n", ft_strncmp(s13, s14, a));
	printf("answer\n");
	printf("strncmp : %d\n", strncmp(s15, s16, a));

	char s17[10] = "aa";
	char s18[10] = "c";
	char s19[10] = "aa";
	char s20[10] = "c";
	unsigned int b = 4;
	printf("----------case2-------------\n");
	printf("input\n");
	printf("ft_strncmp : %d\n", ft_strncmp(s17, s18, b));
	printf("answer\n");
	printf("strncmp : %d\n", strncmp(s19, s20, b));

	
	char s21[10] = "Hello";
	char s22[10] = "Helloaa";
	char s23[10] = "Hello";
	char s24[10] = "Helloaa";
	unsigned int c = 6;
	printf("----------case3-------------\n");
	printf("input\n");
	printf("ft_strncmp: %d\n", ft_strncmp(s21, s22, c));
	printf("answer\n");
	printf("strncmp: %d\n", strncmp(s23, s24, c));
	
	
	char s25[10] = "Hello";
	char s26[11] = "jaeyoondog";
	char s27[10] = "Hello";
	char s28[11] = "jaeyoondog";
	unsigned int d = 6;
	printf("----------case4-------------\n");
	printf("input\n");
	printf("ft_strncmp: %d\n", ft_strncmp(s25, s26, d));
	printf("answer\n");
	printf("strncmp: %d\n", strncmp(s27, s28, d));
	
	
	char s29[10] = "Hello";
	char s30[11] = "jaeyoondog";
	char s31[10] = "Hello";
	char s32[11] = "jaeyoondog";
	unsigned int e = 0;
	printf("----------case5-------------\n");
	printf("input\n");
	printf("ft_strncmp: %d\n", ft_strncmp(s29, s30, e));
	printf("answer\n");
	printf("strncmp: %d\n", strncmp(s31, s32, e));
	
	char	our_5[10] = {'H', 'E', 'L', 'L', 'O'};
	char	our_6[10] = {'H', 'E', 'L', 200, 'O'};
	char	our_7[10] = {'H', 'E', 'L', 'L', 'O'};
	char	our_8[10] = {'H', 'E', 'L', 200, 'O'};
	unsigned int qwc = 4;
	printf("----------case4-------------\n");
	printf("input\n");
	printf("ft_strncmp: %u\n", ft_strncmp(our_5, our_6, qwc));
	printf("answer\n");
	printf("strncmp: %u\n", strncmp(our_7, our_8, qwc));

	
	//ex02
	printf("\n");
	printf("---------------ex02--------------\n");
	printf("\n");
	
	char s33[30] = "awd";
	char s34[10] = "awd";
	char s35[30] = "awd";
	char s36[10] = "awd";
	
	printf("----------case1-------------\n");
	printf("input\n");
	printf("ft_strcat : %s\n", ft_strcat(s33, s34));
	printf("answer\n");
	printf("strcat : %s\n", strcat(s35, s36));

	char a1[30] = "aa";
	char a2[10] = "c";
	char a3[30] = "aa";
	char a4[10] = "c";

	printf("----------case2-------------\n");
	printf("input\n");
	printf("ft_strcat : %s\n", ft_strcat(a1, a2));
	printf("answer\n");
	printf("strcat : %s\n", strcat(a3, a4));

	
	char a5[30] = "Hello";
	char a6[30] = "Helloaa";
	char a7[30] = "Hello";
	char a8[30] = "Helloaa";

	printf("----------case3-------------\n");
	printf("input\n");
	printf("ft_strcat: %s\n", ft_strcat(a5, a6));
	printf("answer\n");
	printf("strcat: %s\n", strcat(a7, a8));
	
	
	char a9[40] = "Hello";
	char a10[40] = "jaeyoondog";
	char a11[40] = "Hello";
	char a12[40] = "jaeyoondog";
	printf("----------case4-------------\n");
	printf("input\n");
	printf("ft_strcat: %s\n", ft_strcat(a9, a10));
	printf("answer\n");
	printf("strcat: %s\n", strcat(a11, a12));
	
	
	//ex03
	printf("\n");
	printf("---------------ex03--------------\n");
	printf("\n");
	
	char b1[30] = "awd";
	char b2[10] = "awd";
	char b3[30] = "awd";
	char b4[10] = "awd";
	unsigned int f = 3;
	printf("----------case1-------------\n");
	printf("input\n");
	printf("ft_strncat : %s\n", ft_strncat(b1, b2, f));
	printf("answer\n");
	printf("strncat : %s\n", strncat(b3, b4, f));


	char b5[30] = "aa";
	char b6[10] = "c";
	char b7[30] = "aa";
	char b8[10] = "c";
	unsigned int g = 1;

	printf("----------case2-------------\n");
	printf("input\n");
	printf("ft_strncat : %s\n", ft_strncat(b5, b6, g));
	printf("answer\n");
	printf("strncat : %s\n", strncat(b7, b8, g));

	
	char b9[30] = "Hello";
	char b10[30] = "Helloaa";
	char b11[30] = "Hello";
	char b12[30] = "Helloaa";
	unsigned int h = 5;

	printf("----------case3-------------\n");
	printf("input\n");
	printf("ft_strncat: %s\n", ft_strncat(b9, b10,h));
	printf("answer\n");
	printf("strncat: %s\n", strncat(b11, b12, h));
	
	
	char b13[40] = "Hello";
	char b14[40] = "jaeyoondog";
	char b15[40] = "Hello";
	char b16[40] = "jaeyoondog";
		unsigned int i = 7;

	printf("----------case4-------------\n");
	printf("input\n");
	printf("ft_strncat: %s\n", ft_strncat(b13, b14, i));
	printf("answer\n");
	printf("strncat: %s\n", strncat(b15, b16, i));
	
	char b17[30] = "awd";
	char b18[10] = "awd";
	char b19[30] = "awd";
	char b20[10] = "awd";
	unsigned int k = 0;
	printf("----------case5-------------\n");
	printf("input\n");
	printf("ft_strncat : %s\n", ft_strncat(b17, b18, k));
	printf("answer\n");
	printf("strncat : %s\n", strncat(b19, b20, k));
	
	
	//ex04
	printf("\n");
	printf("---------------ex04--------------\n");
	printf("\n");
	
	char c1[30] = "my name is <jaeyojun>";
	char c2[10] = "jaeyojun";
	char c3[30] = "my name is <jaeyojun>";
	char c4[10] = "jaeyojun";

	printf("----------case1-------------\n");
	printf("input\n");
	printf("ft_strstr : %s\n", ft_strstr(c1, c2));
	printf("answer\n");
	printf("strstr : %s\n", strstr(c3, c4));


	char c5[30] = "fuck";
	char c6[10] = "de";
	char c7[30] = "fuck";
	char c8[10] = "de";

	printf("----------case2-------------\n");
	printf("input\n");
	printf("ft_strstr : %s\n", ft_strstr(c5, c6));
	printf("answer\n");
	printf("strstr : %s\n", strstr(c7, c8));

	
	char c9[30] = "we meet on the 25th of october";
	char c10[30] = "25";
	char c11[30] = "we meet on the 25th of october";
	char c12[30] = "25";


	printf("----------case3-------------\n");
	printf("input\n");
	printf("ft_strstr: %s\n", ft_strstr(c9, c10));
	printf("answer\n");
	printf("strstr: %s\n", strstr(c11, c12));
	
	
	char c13[40] = "I am Jaeyoon Jeong";
	char c14[40] = "Jae";
	char c15[40] = "I am Jaeyoon Jeong";
	char c16[40] = "Jae";

	printf("----------case4-------------\n");
	printf("input\n");
	printf("ft_strstr: %s\n", ft_strstr(c13, c14));
	printf("answer\n");
	printf("strstr: %s\n", strstr(c15, c16));
	
	//joogmoon 케이스 추가 ++
	char e1[30] = "abc";
	char e2[10] = "";
	char e3[30] = "abc";
	char e4[10] = "";

	printf("----------case5-------------(abc, )\n");
	printf("input\n");
	printf("ft_strstr : %s\n", ft_strstr(e1, e2));
	printf("answer\n");
	printf("strstr : %s\n", strstr(e3, e4));
	
	
	
	
	char e5[30] = "";
	char e6[10] = "abc";
	char e7[30] = "";
	char e8[10] = "abc";

	printf("----------case6---------------( , abc)\n");
	printf("input\n");
	printf("ft_strstr : %s\n", ft_strstr(e5, e6));
	printf("answer\n");
	printf("strstr : %s\n", strstr(e7, e8));
	

	char e9[30] = "";
	char e10[10] = "";
	char e11[30] = "";
	char e12[10] = "";

	printf("----------case7---------------(공백 , 공백)\n");
	printf("input\n");
	printf("ft_strstr : %s\n", ft_strstr(e9, e10));
	printf("answer\n");
	printf("strstr : %s\n", strstr(e11, e12));
	
	//ex05
	printf("\n");
	printf("---------------ex05--------------\n");
	printf("\n");
	
	char str3[40] = "BlockDMask";
    char str4[7] = "Hell";

	printf("----------case1-------------\n");
	printf("intput\n");
    printf("ft_strlcat count: %u\n", ft_strlcat(str3, str4, 10));
	printf("dest :%s\n", str3);
	
	printf("------------------------\n");
	char dest[40] = "BlockDMask";
    char src[7] = "Hell";
	
	printf("ouput\n");
    printf("strlcat count: %lu\n", strlcat(dest, src, 10));
	printf("dest :%s\n", dest);

	printf("\n");
	printf("----------case2-------------\n");
	char qw1[40] = "Bloae";
    char ee1[7] = "Hell";
	
	printf("iutput\n");
    printf("ft_strlcat count: %u\n", ft_strlcat(qw1, ee1,2 ));
	printf("dest :%s\n", qw1);

	printf("------------------------\n");

	char qw[40] = "Bloae";
    char ee[7] = "Hell";
	
	printf("output\n");
    printf("ft_strlcat count: %u\n", ft_strlcat(qw, ee, 2));
	printf("dest :%s", qw);
}