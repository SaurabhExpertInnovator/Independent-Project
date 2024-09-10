#include<stdio.h>
#include<string.h>
#include<ctype.h>
int is_valid_username(const char* username){
    if(strlen(username)==0){
        printf("Error!! Username cannot be empty\n");
        return 0;
    }
    return 1;
}

int is_valid_password(const char* password){
    if(strlen(password)<8){
        printf("Error!! Password must conatain atleast 8 characters.\n");
        return 0;
    }
    int has_special=0, has_digit=0;
    for(int i=0; i<strlen(password); i++){
        if(ispunct(password[i])) has_special=1;
        if(isdigit(password[i])) has_digit=1;
    }
    if(!has_special){
        printf("Error!! Password must contain atleast one special character\n");
        return 0;
    }
    if(!has_digit){
        printf("Error!! Password must contain atleast one number\n");
        return 0;
    }
    return 1;
}
void test_signup(const char* username, const char* password){
    if(is_valid_username(username)&& is_valid_password(password)){
        printf("Signup Successfull\n");
    }
    else{
        printf("Signup failed\n");
    }
}

int main(){
    // char user;
    // char pwd;
    // printf("Enter Username : ");
    // scanf("%c",user);
    // printf("Enter password : ");
    // scanf("%c",pwd);
    // test_signup(user,pwd);
       test_signup("ValidUser","Password@123");
       test_signup("","Saurabh@");
       test_signup("User","pass");
       test_signup("ValidUser","Password@");
       test_signup("ValidUser","Password123");
       test_signup("ValidUser","");
       test_signup("","");
    return 0;
}
