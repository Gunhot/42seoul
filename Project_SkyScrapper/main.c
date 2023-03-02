#include <unistd.h>

int start(int *input);

int check_space(char c)
{
    if(c == ' ' || c == '\t' || c == '\n'
    || c == '\v' || c == '\f' || c == '\r')
        return 1;
    return 0;
}

void delete_extra_space(char *argv, char *str)
{
    int argv_idx;
    int str_idx;

    argv_idx = 0;
    str_idx = 0;
    while (argv[argv_idx] != '\0' && str_idx < 16)
    {
        while (check_space(argv[argv_idx]))
            argv_idx++;
        str[str_idx] = argv[argv_idx];
        str_idx++;
        argv_idx++;
    }
    str[str_idx] = '\0';
}

int input_str_to_int(char *input_str, int *input_int)
{
    int idx;

    idx = 0;
    while (input_str[idx] != '\0')
    {
        if  ('1' <= input_str[idx] && input_str[idx] <= '4')
            input_int[idx] = input_str[idx] - '0';
        else
        return (0);
        idx++;
    }
    if(idx != 16)
        return 0;
    return (1);
}

int main(int argc, char **argv)
{
    char input_str[17];
    int input_int[16];

    if (argc == 2)
    {
        delete_extra_space(argv[1], input_str);
        if (input_str_to_int(input_str, input_int) == 1)
            start(input_int);
        else
            write(1, "Error\n", 6);
    }
    else
        write(1, "Error\n", 6);
    return (0);
} 