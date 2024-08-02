#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void free_all(char ***args, char ***path_args, char **temp)
{
    int i = 0;

    for (i = 0; (*args)[i] != NULL; i++)
        free(*args[i]);
    free(*args);
    *args = NULL;
    if (*path_args != NULL)
    {
        for (i = 0; (*path_args)[i] != NULL; i++)
        {
            free(*path_args[i]);
        }
    }
    free(*path_args);
    *path_args = NULL;
}

char **get_tokens(char *buf, char *sep)
{
    char *word, *str;
    char **args;
    char *temp_str;
    int count = 0;

    str = malloc(sizeof(char) * (strlen(buf) + 1));
    strcpy(str, buf);
    temp_str = strdup(str);

    for (word = strtok(temp_str, sep); word != NULL; word = strtok(NULL, sep))
    {
        count++;
    }

    args = malloc(sizeof(char *) * (count + 1));

    count = 0;
    for (word = strtok(str, sep); word != NULL; word = strtok(NULL, sep))
    {
        args[count] = malloc(sizeof(char) * (strlen(word) + 1));
        strcpy(args[count], word);
        count++;
    }
    args[count] = NULL;
    free(temp_str);
    temp_str = NULL;
    free(str);
    str = NULL;
    return (args);
}

char *check_build(char *arg, char **path)
{
    char *temp = NULL;
    int count, i;
    char **temp_args;

    for (count = 0; path[count] != NULL; count++)
    {}
    temp_args = malloc(sizeof(char *) * (count + 1));
    temp_args[count] = NULL;

    for (count = 0; path[count] != NULL; count++)
    {
        temp_args[count] = malloc(sizeof(char) * (strlen(path[count]) + strlen(arg) + 2));
        strcpy(temp_args[count], path[count]);
        strcat(temp_args[count], "/");
        strcat(temp_args[count], arg);
    }
    for (count = 1; temp_args[count] != NULL; ++count) /*loop that iterates through the passed path args*/
    {
        temp = strdup(temp_args[count]);
        free(temp);
        temp = NULL;
    }
    for (count = 0; temp_args[count] != NULL; count++)
        free(temp_args[count]);
    free(temp_args);
    temp_args = NULL;
    return (NULL);
}

int main(void)
{
    char *sep = " \t\r\n:;=";
    size_t size = 64;
    ssize_t check;
    char **args, **path_args;
    char *buf = "lsd";
    extern char **environ;
    char *path, *temp = NULL;

    printf("$ ");
    args = get_tokens(buf, sep);
    path = "PATH=/usr:/bin";
    path_args = get_tokens(path, sep);
    temp = check_build(args[0], path_args);
    if (temp == NULL)
    {
        free_all(&args, &path_args, &temp);
        perror("Cannot find command\n");
        exit(EXIT_FAILURE);
    }
    return (0);
}