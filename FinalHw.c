#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// My name is ADO.
// delete name
// 

void Delete(char str[100],char dstr[100]){
	int pos;
	char *ptr;
	
	ptr = strstr(str,dstr);
	if(ptr == NULL)
		return ;
	
	pos = ptr-str;
	
	char front[100], back[100];
	strncpy(front,str,pos);
	strcpy(back,ptr + strlen(dstr));

	strcpy(str, front);
	strcat(str, back);

	printf("%s\n",str);
}
void Insert(char str[100],char istr[100],int pos){
	int i;
	int str_len,istr_len;
	
	str_len = strlen(str);
	istr_len = strlen(istr);
	
	istr[istr_len]=' ';
	istr[istr_len+1]='\0';
	istr_len++;
	
	for(i = str_len;i>=pos-1;i--){
		str[i+istr_len] = str[i];
		
	}
	for(i = 0;i < istr_len;i++){
		str[pos-1] = istr[i];
		pos++;
	}
	
	printf("New resource : %s",str);
	printf("\n");			
}
void Locate(char str[100],char lstr[100]){
	
	int pos;
	char *ptr;
	
	ptr = strstr(str,lstr);
	pos = ptr-str;
	
	printf("The '%s' is in the %d of source string.\n",lstr,pos + 1);
}
void  Print(char str[100]){
	printf("Source string is : %s\n",str);
}
void  Replace(char str[100],char rstr[100],char nstr[100]){
	int pos;
	char *ptr;
	
	ptr = strstr(str,rstr);
	if(ptr == NULL)
		return ;
	
	pos = ptr-str;
	
	char front[100], back[100];
	strncpy(front,str,pos);
	strcpy(back,ptr + strlen(rstr));

	strcpy(str, front);
	strcat(str, back);


	Insert(str,nstr,pos + 1);
}

int main(void) {
	
	char str[100];
	char dstr[100],istr[100],lstr[100],rstr[100],nstr[100];
	int pos;
	char choose;
	
	while(1){
		
		printf("Your choice : ");
		scanf("%c",&choose);
		fflush(stdin);
		
		if(choose == 'D'){
			printf("Delete what string? ");
			gets(dstr);
			fflush(stdin);
			Delete(str,dstr);
		}
		else if(choose == 'E'){
			printf("Please input source string : ");
			gets(str);
		}
		else if(choose == 'I'){
			printf("Insert what string : ");
			gets(istr);
			fflush(stdin);
			printf("At What position? ");
			scanf("%d",&pos);
			fflush(stdin);
			Insert(str,istr,pos);
		}
		else if(choose == 'L'){
			printf("Locate what string? ");
			gets(lstr);
			fflush(stdin);
			Locate(str,lstr);
		}
		else if(choose == 'P'){
			Print(str);
			fflush(stdin);
		}
		else if(choose == 'R'){
			printf("Replace old string? ");
			gets(rstr);
			fflush(stdin);
			printf("With new string? ");
			gets(nstr);
			fflush(stdin);
			Replace(str,rstr,nstr);
		}
		else if(choose == 'S'){
			printf("**** Edit function ****\n");
			printf("D - Delete a sub-string\n");
			printf("E - Input a string\n");
			printf("I - Insert a sub-string\n");
			printf("L - Locate a sub-string\n");
			printf("P - Print source string\n");
			printf("R - Replace a sub-string\n");
			printf("S - Show function\n");
			printf("Q - Quit\n");
		}
		else if(choose == 'Q'){
			break;
		}

	}
	
	
	
	return 0;
}
