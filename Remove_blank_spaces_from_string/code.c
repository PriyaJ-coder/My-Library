#include <stdio.h>
#include <string.h>
 
void deleteblankspaces(char *s)
{
	static int i,k=0;
    if(s[i])
    {
    	 s[i]=s[i+k];
     	if(s[i]==' '|| s[i]=='\t')
     	{
		  k++;
		  i--;
	    }
	    i++;
     	deleteblankspaces(s);
	}
}
 
int main()
{
    char s[1000];
    printf("Enter  the string : ");
    gets(s);
    deleteblankspaces(s);
    printf("string after removing all duplicates:");
    printf("%s",s);
	return 0;
}