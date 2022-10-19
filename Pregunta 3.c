#include "stdio.h"
#include "string.h"
#include "omp.h"
int main(){
    char string1[20];
    int i, length;
    int flag = 0;

    printf("Ingrese una palabra:");
    scanf("%s", string1);

    length = strlen(string1);
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        if(id==0){
            for(i=0;i < length ;i++){
                if(string1[i] != string1[length-i-1]){
                    flag = 1;
                    break;
                }
            }
        }else{
            if (flag) {
                printf("%s no es palindromo", string1);
            }
            else {
                printf("%s es palindromo", string1);
            }
        }
    }



    return 0;
}


