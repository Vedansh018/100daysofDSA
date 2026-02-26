//Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.
#include <stdio.h>
#include <string.h>

void mirror(char str[], int index)
{
    if (index < 0)
        return;

    printf("%c", str[index]);

    mirror(str, index - 1);
}

int main()
{
    char str[100];

    printf("Enter code name: ");
    scanf("%s", str);

    int length = strlen(str);

    printf("Mirror code name: ");
    mirror(str, length - 1);

    return 0;
}