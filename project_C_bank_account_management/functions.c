#include"functions.h"
#include <stdio.h>
#include<string.h>
#include <stdbool.h>
#include <ctype.h>
//logic ham
void showMenu(){
	system("cls");
	printf("  ***Bank Management System Using C***\n\n");
	printf("\t   CHOOSE YOUR ROLE\n");
	printf("\t========================\n");
	printf("\t[1] Admin.\n");
	printf("\t[2] User.\n");
	printf("\t[0] Exit The Program.\n");
	printf("\t========================\n");
}
void adminMenu(){
	system("cls");
	printf("\n  ***Bank Management System Using C***\n\n");
	printf("\t   ADMIN MENU\n");
	printf("\t========================\n");
	printf("\t[1] Add A New User.\n");
	printf("\t[2] Show All users.\n");
	printf("\t[3] Search User By Name.\n");
	printf("\t[4] Check User Datas By ID.\n");
	printf("\t[5] Lock/Unlock User By ID.\n");
	printf("\t[6] Arrange Users List.\n");	
	printf("\t[0] Return To Menu.\n");
	printf("\t========================\n");
}
void inputUsersData(struct User users[], int *length){
	system("cls");
	int check=0;
	int subCheck;
	int i;
	printf("\n");
	getchar();
	while(check==0){
		printf("*Enter User's ID(Below 10 characters): ");
		fgets(users[*length].userId,sizeof(users[*length].userId),stdin);
		users[*length].userId[strcspn(users[*length].userId,"\n")]='\0';
		fflush(stdin);
		if(strlen(users[*length].userId)>9 || strlen(users[*length].userId)==0 ){
			printf(" \n*Invalid Input.Try again!*\n\n");
			fflush(stdin);
		}else{
			subCheck=1;
			fflush(stdin);
			for(i=0;i<*length;i++){
				if(strcmp(users[*length].userId,users[i].userId)==0){
					printf(" \n*User's Information Must Not Overlap!*\n\n");	
					subCheck=0;
					break;
				}
			}
			int subCheck2=0;
			for(i=0;i<strlen(users[*length].userId);i++){
				if(users[*length].userId[i]==' '){
					subCheck2++;	
				}
			}
			if(subCheck2==strlen(users[*length].userId)){
					subCheck=0;
					printf(" \n *User's ID Must Not Be Empty!*\n\n");
					continue;
			}
			if(subCheck!=0){
				break;
			}
		}
	}
	while(check==0){
    	printf("*Enter User's Name(Below 20 characters): ");
    	fgets(users[*length].name,sizeof(users[*length].name),stdin);
    	users[*length].name[strcspn(users[*length].name,"\n")]='\0';
		fflush(stdin);
    	if(strlen(users[*length].name)>19 || strlen(users[*length].name)==0){
			printf(" \n *Invalid Input.Try again!*\n\n");
			fflush(stdin);
		}else{
			subCheck=1;
			fflush(stdin);
			for(i=1;users[*length].name[i] != '\0';i++){
				if(users[*length].name[i-1]==' ' && users[*length].name[i]>='a' && users[*length].name[i]<='z'){
					subCheck=0;
					printf(" \n *Each Word Of User's Name Must Start In Uppercase!*\n\n");
					break;
				}			
			}
			if(users[*length].name[0]>='a' && users[*length].name[0]<='z'){
					subCheck=0;
					printf(" \n *User Name's First Letter Must Be Written In Uppercase!*\n\n");
			}
			int subCheck2=0;
			for(i=0;i<strlen(users[*length].name);i++){
				if(users[*length].name[i]==' '){
					subCheck2++;	
				}
			}
			if(subCheck2==strlen(users[*length].name)){
					subCheck=0;
					printf(" \n *User's Name Must Not Be Empty!*\n\n");
					continue;
			}
			if (users[*length].name[strlen(users[*length].name)-1] == ' '){
				printf(" \n *Invalid Character At The End Of User's Name!*\n\n");
				subCheck=0;
			} 
			if(subCheck!=0){
				break;
			}
		}
	}
	while(check==0){
    	printf("*Enter User's Phone Number(Below 10 characters): ");
   		fgets(users[*length].phone,sizeof(users[*length].phone),stdin);
   		users[*length].phone[strcspn(users[*length].phone,"\n")]='\0';
   	 	fflush(stdin);
    	if(strlen(users[*length].phone)>9 || strlen(users[*length].phone)==0){
			printf(" \n *Invalid Input.Try again!*\n\n");
			fflush(stdin);
		}else{
			subCheck=1;
			fflush(stdin);
			for(i=0;i<*length;i++){
				if(strcmp(users[*length].phone,users[i].phone)==0){
					printf(" \n *User's Information Must Not Overlap!*\n\n");	
					subCheck=0;
					break;
				}
			}
			int subCheck2=0;
			for(i=0;i<strlen(users[*length].phone);i++){
				if(users[*length].phone[i]==' '){
					subCheck2++;	
				}
			}
			if(subCheck2==strlen(users[*length].phone)){
					subCheck=0;
					printf(" \n *User's Number Must Not Be Empty!*\n\n");
					continue;
			}
		
			if(subCheck!=0){
				break;
			}
		}
	}

	//Validate
	while(check==0){
   		 printf("*Enter User's Email(Below 20 characters): ");
   		 fgets(users[*length].email,sizeof(users[*length].email),stdin);
   		 users[*length].email[strcspn(users[*length].email,"\n")]='\0';
   		 fflush(stdin);
    	if(strlen(users[*length].email)>19 || strlen(users[*length].email)==0){
			printf(" \n *Invalid Input.Try again!*\n\n");
			fflush(stdin);
		}else{
			subCheck=1;
			fflush(stdin);
			for(i=0;i<*length;i++){
				if(strcmp(users[*length].email,users[i].email)==0){
					printf(" \n *User's Information Must Not Overlap!*\n\n");	
					subCheck=0;
					break;
				}
			}
			int subCheck2=0;
			for(i=0;i<strlen(users[*length].email);i++){
				if(users[*length].email[i]==' '){
					subCheck2++;	
				}
			}
			if(subCheck2==strlen(users[*length].email)){
					subCheck=0;
					printf(" \n *User's Email Must Not Be Empty!*\n\n");
					continue;
			}
			char emailValidation[]="@gmail.com";
				for(i=0;i<strlen(users[*length].email);i++){
				if(users[*length].email[i]=='@'){
					break;	
				}
			}
			char *temp = strrchr(users[*length].email, users[*length].email[i]);
			if(strcmp(temp,emailValidation)!=0){
				subCheck=0;
				printf(" \n *Invalid Format!*\n\n");
				continue;
			}
			if(subCheck!=0){
				break;
			}
		}
	}
		while(check==0){
    	printf("*Enter UserName(Below 20 characters): ");
    	fgets(users[*length].userName,sizeof(users[*length].userName),stdin);
    	users[*length].userName[strcspn(users[*length].userName,"\n")]='\0';
		fflush(stdin);
    	if(strlen(users[*length].userName)>19 || strlen(users[*length].userName)==0){
			printf(" \n *Invalid Input.Try again!*\n\n");
			fflush(stdin);
		}else{
			subCheck=1;
			fflush(stdin);
			for(i=0;i<*length;i++){
				if(strcmp(users[*length].userName,users[i].userName)==0){
					printf(" \n *User's Information Must Not Overlap!*\n\n");	
					subCheck=0;
					break;
				}
			}
			
			for(i=0;i<strlen(users[*length].userName);i++){
				if(users[*length].userName[i]==' '){
					subCheck=0;
					printf(" \n *UserName Must Not Include [...]*\n\n");	
				}
			}
			if(subCheck!=0){
				break;
			}
		}
	}
	strcpy(users[*length].password, users[*length].phone);
	strcpy(users[*length].status, "Open");
	(*length)+=1;
	printf("\n **Successfully Added User Datas.**\n");
	printf(" =====================================\n");
	int choice;
	while(1){
		printf("\n\tGo back(1)? or Exit(2): ");
		scanf("%d", &choice);
		if(choice==1){
			break;
		}else if(choice==2){
			printf("\n  ==========Exited Program!===========\n");
			printf("   ========Thanks For Using Our App!=========\n");
			exit (1);
		}else{
			printf("\n\t*Invalid Input.Try again!*\n\n");
			fflush(stdin);
			continue;
		}
	}
}
void showUsersData(struct User users[],int length){
	system("cls");
	int choice;
	int i;
	printf("\n\t\t\t**LIST OF USERS**\n");
	printf("|===============================================================================================|\n");
    printf("|    ID    |       Name         |       Email        |   Phone   |      Username      |  Status |\n");
    printf("|==========|====================|====================|===========|====================|=========|\n");
	for(i=0;i<length;i++){
		printf("|%-9s |%-19s |%-19s |%-9s  |%-19s |%-9s|\n",users[i].userId,users[i].name,users[i].email,users[i].phone,users[i].userName,users[i].status);
		printf("|----------|--------------------|--------------------|-----------|--------------------|---------|\n");
	}
	//test file
//	for(i=0;i<length;i++){
//		printf("|%-9s |%-19s |%-19s |%-9s  |%-19s |%-9s|\n",usersFromFile[i].userId,usersFromFile[i].name,usersFromFile[i].email,usersFromFile[i].phone,usersFromFile[i].userName,usersFromFile[i].status);
//		printf("|----------|--------------------|--------------------|-----------|--------------------|---------|\n");
//	}
	//go back/ exit
	while(1){
		printf("\n\tGo back(1)? or Exit(2): ");
		scanf("%d", &choice);
		if(choice==1){
			break;
		}else if(choice==2){
			printf("\n  ==========Exited Program!===========\n");
			printf("   ========Thanks For Using Our App!=========\n");
			exit (1);
		}else{
			printf("\n\t*Invalid Input.Try again!*\n\n");
			fflush(stdin);
			continue;
		}
	}
	
}
void searchUserByName(struct User users[],int length){
	system("cls");
	int i,j;
	int check=0;
	int categoryCheck=0;
	printf("\n");
	getchar();
	char temp[25];
	char temp2[25];
	while(1){
		printf("*Enter User's Name To Search(Below 20 characters): ");
		fgets(temp,25,stdin);
   		temp[strcspn(temp,"\n")]='\0';	
   		fflush(stdin);
   		if(strlen(temp)>19 || strlen(temp)==0){
   			printf("\n *Invalid Input.Try again!*\n\n");
		}else{
			int subCheck=1;
			fflush(stdin);
			int subCheck2=0;
			for(i=0;i<strlen(temp);i++){
				if(temp[i]==' '){
					subCheck2++;	
				}
			}
			if(subCheck2==strlen(temp)){
					subCheck=0;
					printf(" \n *User's Name Must Not Be Empty!*\n\n");
					continue;
			}
			if (temp[strlen(temp)-1] == ' '){
				printf(" \n *Invalid Character At The End Of User's Name!*\n\n");
				subCheck=0;
				continue;
			} 
			for(j=0;j<strlen(temp);j++){
				temp[j]=tolower(temp[j]);
			}
			if(subCheck!=0){
				break;
			}
		}
	}
	for(i=0;i<length;i++){
		strcpy(temp2, (users[i].name));
		for(j=0;j<strlen(temp2);j++){
			temp2[j]=tolower(temp2[j]);
		}
		if (strstr(temp2, temp)!=NULL){
			if(categoryCheck==0){
			printf("|===============================================================================================|\n");
    		printf("|    ID    |       Name         |       Email        |   Phone   |      Username      |  Status |\n");
   			printf("|==========|====================|====================|===========|====================|=========|\n");
    			categoryCheck++;
			}
			printf("|%-9s |%-19s |%-19s |%-9s  |%-19s |%-9s|\n",users[i].userId,users[i].name,users[i].email,users[i].phone,users[i].userName,users[i].status);
			printf("|----------|--------------------|--------------------|-----------|--------------------|---------|\n");
			check++;
		}	
	}
	if(check!=0){
			int choice;
					while(1){
						printf("\n\tGo back(1)? or Exit(2): ");
						scanf("%d", &choice);
						if(choice==1){
							break;
						}else if(choice==2){
							printf("\n  ==========Exited Program!===========\n");
							printf("   ========Thanks For Using Our App!=========\n");
							exit (1);
						}else{
							printf("\n\t*Invalid Input.Try again!*\n\n");
							fflush(stdin);
							continue;
						}
					}
	}
	if(check==0){
		printf("\n **User Name Does Not Exist.**\n\n");
		int choice;
					while(1){
						printf("\n\tGo back(1)? or Exit(2): ");
						scanf("%d", &choice);
						if(choice==1){
							break;
						}else if(choice==2){
							printf("\n  ==========Exited Program!===========\n");
							printf("   ========Thanks For Using Our App!=========\n");
							exit (1);
						}else{
							printf("\n\t*Invalid Input.Try again!*\n\n");
							fflush(stdin);
							continue;
						}
					}
	}
}
void checkUserDataById(struct User users[],int length){
	system("cls");
	int i;
	int check=0;
	char temp[15];
	getchar();
	while(1){
		printf("*Enter User's ID To Check(Below 10 characters): ");
		fgets(temp,15,stdin);
   		temp[strcspn(temp,"\n")]='\0';	
   		fflush(stdin);
   		if(strlen(temp)>9 || strlen(temp)==0){
   			printf("\n *Invalid ID.Try again!*\n\n");
   			continue;
		}else{
			if(strlen(temp)==0){
   			printf("\n *Invalid Input.Try again!*\n\n");
   			continue;
		}
			int subCheck2=0;
			for(i=0;i<strlen(temp);i++){
				if(temp[i]==' '){
					subCheck2++;	
				}
			}
			if(subCheck2==strlen(temp)){
					printf(" \n *User's ID Must Not Be Empty!*\n\n");
					continue;
			}
			if (temp[strlen(temp)-1] == ' '){
				printf(" \n *Invalid Character At The End Of User's ID!*\n\n");
				continue;
			} 
			break;
		}
	}
	for(i=0;i<length;i++){
		if(strcmp(temp,users[i].userId)==0){
				printf("\t\t\t**User Found!**\n");
				check++;
					printf("|===============================================================================================|\n");
    				printf("|    ID    |       Name         |       Email        |   Phone   |      Username      |  Status |\n");
   					printf("|==========|====================|====================|===========|====================|=========|\n");
    			printf("|%-9s |%-19s |%-19s |%-9s  |%-19s |%-9s|\n",users[i].userId,users[i].name,users[i].email,users[i].phone,users[i].userName,users[i].status);
				printf("|----------|--------------------|--------------------|-----------|--------------------|---------|\n");
				break;
		}
	}
	int idCheck=0;
	if(check==0){
		printf("\n **ID Does Not Exist.**\n\n");
					int choice;
					while(1){
						printf("\n\tGo back(1)? or Exit(2): ");
						scanf("%d", &choice);
						if(choice==1){
							idCheck++;
							break;
						}else if(choice==2){
							printf("\n  ==========Exited Program!===========\n");
							printf("   ========Thanks For Using Our App!=========\n");
							exit (1);
						}else{
							printf("\n\t*Invalid Input.Try again!*\n\n");
							fflush(stdin);
							continue;
						}
					}
	}
	if(idCheck==0){
					int choice;
					while(1){
						printf("\n\tGo back(1)? or Exit(2): ");
						scanf("%d", &choice);
						if(choice==1){
							break;
						}else if(choice==2){
							printf("\n  ==========Exited Program!===========\n");
							printf("   ========Thanks For Using Our App!=========\n");
							exit (1);
						}else{
							printf("\n\t*Invalid Input.Try again!*\n\n");
							fflush(stdin);
							continue;
						}
					}
	}				
}
void lockAndUnlockId(struct User users[],int length){
	system("cls");
	printf("\n");
	int i;
	int check2=0;
	int check=0;
	char temp[15];
	int confirm=99;
	getchar();
	while(1){
		printf("*Enter User ID(Below 10 characters): ");
		fgets(temp,15,stdin);
   		temp[strcspn(temp,"\n")]='\0';	
   		fflush(stdin);
   		if(strlen(temp)>9 || strlen(temp)==0){
   			printf("\n *Invalid ID.Try again!*\n\n");
		}else{
			break;
		}
	}
		for(i=0;i<length;i++){
			if(strcmp(temp,users[i].userId)==0){
				printf("\t\t\t**User Found!**\n");
				check++;
				break;
			}
		}//POTENTIAL ERROR
		if(check==0){
			printf("\n\t***ID Does Not Exist.***\n\n");
			printf(" \n      **Check List Of Users In [2]**\n");
			printf(" =======================================\n");
			int choice;
					while(1){
						printf("\n\tGo back(1)? or Exit(2): ");
						scanf("%d", &choice);
						if(choice==1){
							check2++;
							break;
						}else if(choice==2){
							printf("\n  ==========Exited Program!===========\n");
							printf("   ========Thanks For Using Our App!=========\n");
							exit (1);
						}else{
							printf("\n\t*Invalid Input.Try again!*\n\n");
							fflush(stdin);
							continue;
						}
					}
		}else if(strcmp(users[i].status, "Open")==0){
			while(1){
				if (check2!=0){
					break;
				}
				printf("*This User's Account Is Currently Open, Do You Wish To Lock?(Press [1] To Confirm, [0] To Cancel): ");
				scanf("%d", &confirm);	
				if(confirm==1){
					strcpy(users[i].status, "Locked");
					printf(" **Successfully Locked.**\n");
						int choice;
					while(1){
						printf("\n\tGo back(1)? or Exit(2): ");
						scanf("%d", &choice);
						if(choice==1){
							check2++;
							break;
						}else if(choice==2){
							printf("\n  ==========Exited Program!===========\n");
							printf("   ========Thanks For Using Our App!=========\n");
							exit (1);
						}else{
							printf("\n\t*Invalid Input.Try again!*\n\n");
							fflush(stdin);
							continue;
						}
					}
				}else if(confirm==0){
					printf(" **Cancelled.**\n");
						int choice;
						while(1){
						printf("\n\tGo back(1)? or Exit(2): ");
						scanf("%d", &choice);
						if(choice==1){
							check2++;
							break;
						}else if(choice==2){
							printf("\n  ==========Exited Program!===========\n");
							printf("   ========Thanks For Using Our App!=========\n");
							exit (1);
						}else{
							printf("\n\t*Invalid Input.Try again!*\n\n");
							fflush(stdin);
							continue;
						}
					}
				}else{
					printf(" **Invalid Choice!**\n");
					fflush(stdin);
				}
			}
		}else{
			while(1){
					if (check2!=0){
					break;
				}
				printf("*This User's Account Is Currently Locked, Do You Wish To Open?(Press [1] To Confirm, [0] To Cancel): ");
				scanf("%d", &confirm);	
			if(confirm==1){
					strcpy(users[i].status, "Open");
					printf(" **Successfully Opened.**\n");
					int choice;
					while(1){
						printf("\n\tGo back(1)? or Exit(2): ");
						scanf("%d", &choice);
						if(choice==1){
							check2++;
							break;
						}else if(choice==2){
							printf("\n  ==========Exited Program!===========\n");
							printf("   ========Thanks For Using Our App!=========\n");
							exit (1);
						}else{
							printf("\n\t*Invalid Input.Try again!*\n\n");
							fflush(stdin);
							continue;
						}
					}
			}else if(confirm==0){
					printf(" **Cancelled.**\n");
						int choice;
					while(1){
						printf("\n\tGo back(1)? or Exit(2): ");
						scanf("%d", &choice);
						if(choice==1){
							check2++;
							break;
						}else if(choice==2){
							printf("\n  ==========Exited Program!===========\n");
							printf("   ========Thanks For Using Our App!=========\n");
							exit (1);
						}else{
							printf("\n\t*Invalid Input.Try again!*\n\n");
							fflush(stdin);
							continue;
						}
					}
			}else{
					printf(" **Invalid Choice!**\n");
					fflush(stdin);
				}
			}
		}
}
void arrangeUsers(struct User users[],int length){
	system("cls");
	printf("\n");
	int i,j;
	char min;
	char temp[30];
	int choice;
	printf(" **Select Arrange Options:**\n");
	while(1){	
		printf("*[1]From A-Z*\n");
		printf("*[2]From Z-A*\n");
		printf("\n*Your Choice: ");
		scanf("%d", &choice);
		if(choice==2){
			for(i=0;i<length;i++){
				for(j=i+1;j<length;j++){
					char *name1 = strrchr(usersFromFile[i].name, ' ');//points to[space]
            		char *name2 = strrchr(usersFromFile[j].name, ' ');
            		//checks if there is [space] or not(null)
            		if (name1!=NULL){
    					name1++; // if yes, points to letter behind space (Name)
					}else{
   						name1=usersFromFile[i].name; //if not, takes the entire name
					}
					if(name2!=NULL){
    					name2++; 
					}else{
    					name2=usersFromFile[j].name; 
					}
					if(name1[0]<name2[0]){
						//id
						strcpy(temp,usersFromFile[j].userId);
						strcpy(usersFromFile[j].userId, usersFromFile[i].userId);
						strcpy(usersFromFile[i].userId, temp);
						//name
						strcpy(temp,usersFromFile[j].name);
						strcpy(usersFromFile[j].name, usersFromFile[i].name);
						strcpy(usersFromFile[i].name, temp);
						//phone
						strcpy(temp, usersFromFile[j].phone);
						strcpy(usersFromFile[j].phone, usersFromFile[i].phone);
						strcpy(usersFromFile[i].phone, temp);
						//email
						strcpy(temp, usersFromFile[j].email);
						strcpy(usersFromFile[j].email, usersFromFile[i].email);
						strcpy(usersFromFile[i].email, temp);
						//status
						strcpy(temp, usersFromFile[j].status);
						strcpy(usersFromFile[j].status, usersFromFile[i].status);
						strcpy(usersFromFile[i].status, temp);
					}	
            	}
		 	}
		 	break;
		}else if(choice==1){
		    for(i=0;i<length;i++){
				for(j=i+1;j<length;j++){
					char *name1 = strrchr(usersFromFile[i].name, ' ');//points to[space]
            		char *name2 = strrchr(usersFromFile[j].name, ' ');
            		//checks if there is [space] or not(null)
            		if (name1!=NULL){
    					name1++; // if yes, points to letter behind space (Name)
					}else{
   						name1=usersFromFile[i].name; //if not, takes the entire name
					}
					if(name2!=NULL){
    					name2++; 
					}else{
    					name2=usersFromFile[j].name; 
					}
					if(name1[0]>name2[0]){
						//id
						strcpy(temp,usersFromFile[j].userId);
						strcpy(usersFromFile[j].userId, usersFromFile[i].userId);
						strcpy(usersFromFile[i].userId, temp);
						//name
						strcpy(temp,usersFromFile[j].name);
						strcpy(usersFromFile[j].name, usersFromFile[i].name);
						strcpy(usersFromFile[i].name, temp);
						//phone
						strcpy(temp, usersFromFile[j].phone);
						strcpy(usersFromFile[j].phone, usersFromFile[i].phone);
						strcpy(usersFromFile[i].phone, temp);
						//email
						strcpy(temp, usersFromFile[j].email);
						strcpy(usersFromFile[j].email, usersFromFile[i].email);
						strcpy(usersFromFile[i].email, temp);
						//status
						strcpy(temp, usersFromFile[j].status);
						strcpy(usersFromFile[j].status, usersFromFile[i].status);
						strcpy(usersFromFile[i].status, temp);
					}	
            	}
		 	}
		 	break;
		}else{
			printf(" \n**Invalid choice!.**\n\n");
		}
	}
			printf("|===============================================================================================|\n");
    		printf("|    ID    |       Name         |       Email        |   Phone   |      Username      |  Status |\n");
   			printf("|==========|====================|====================|===========|====================|=========|\n");
	for(i=0;i<length;i++){
			printf("|%-9s |%-19s |%-19s |%-9s  |%-19s |%-9s|\n",usersFromFile[i].userId,usersFromFile[i].name,usersFromFile[i].email,usersFromFile[i].phone,usersFromFile[i].userName,usersFromFile[i].status);
			printf("|----------|--------------------|--------------------|-----------|--------------------|---------|\n");
	}
	int subChoice;
	while(1){
		printf("\n\tGo back(1)? or Exit(2): ");
		scanf("%d", &subChoice);
		if(subChoice==1){
			break;
		}else if(subChoice==2){
			printf("\n  ==========Exited Program!===========\n");
			printf("   ========Thanks For Using Our App!=========\n");
			exit (1);
		}else{
			printf("\n\t*Invalid Input.Try again!*\n\n");
			fflush(stdin);
			continue;
		}
	}
}
void writeFile(struct User users[],int length){
	FILE *f=fopen("data.bin","wb");
	if (f== NULL){
        printf("Error");
        return;
    }
    fwrite(users,sizeof(struct User),length,f);
    fclose(f);
}
void readFile(struct User users[],int *length){
	FILE *f=fopen("data.bin","rb");
	if (f== NULL){
        printf("Error");
        return;
    }
    *length = fread(usersFromFile,sizeof(struct User),100,f);
    fclose(f);
}

