#include<stdlib.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
    int ch;
    FILE *fp;
    unsigned long count=0;
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }
    if((fp = fopen(argv[1], "r")) == NULL)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    while((ch=fgetc(fp)) != EOF)
    {
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters\n", argv[1], count);
    return 0;
}