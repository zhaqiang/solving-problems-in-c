#include<stdio.h>
#define MAXLINE 1000	/* maximum input line size */

int getline(char line[], int maxline);
void reverse(char s[]);

/* reverse input lines, a line at a time */
main()
{
	char line[MAXLINE];	/* current input line */
	
	while(getline(line, MAXLINE) > 0){
		reverse(line);
		printf("%s", line);
	}
}

/* reverse: reverse string a */
void reverse(char s[])
{
	int i, j;
	char temp;
	
	i = 0;
	while(s[i] != '\0')	/* find the end of string s */
		++i;
	--i;	/* back off from '\0' */
	if(s[i] == '\n')
		--i;
	j = 0;
	while(j < i){
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		--i;
		++j;
	}
}

/* getline: read a line into s, return length */
int getline(char s[], int maxline){
	int c, i, j;

	j = 0;
	for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		if(i < maxline-2) {
			s[j] = c;
			++j;
		}
	if(c == '\n'){
		s[j] = c;
		++j;
		++i;
	}
	s[j] = '\0';
	return i;
}