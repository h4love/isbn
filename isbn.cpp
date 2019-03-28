#include <stdio.h>

int main()
{	
	char input[64];
	char num[11];
	
	printf("[>] Enter string: ");
	scanf("%s",input);
	/*
	printf("\n[>] Enter X: ");
	scanf("%s",input);
	*/
	int count = 0, i = 0;
	
	while (input[i] != '\0'){
		if ((input[i] >= '0') && (input[i] <= '9')) {
			num[count++] = input[i];
		}
		i++;
	}
	
	int sum = 0;
	for (int i = 0; i < count; i++){
		sum += (num[i]-'0')*(count-i);
	}
	num[count] = '\0';
	printf("[<] String: %s, length: %d", num, count);
	if ((sum %= 11) != 0){
		printf("\n[<] Error found");
		for (int i = 0; i < count; i++){
			//printf("\n[+] Counting number with index: %d",i);
			for (int j = 0; j < 10; j++){
				//printf("\n[+] Trying digit: %d",j);
				int tempsum = 0;
				for (int k = 0; k < count; k++){
					if (k != i){
						tempsum += (num[k]-'0')*(count-k);
						//printf("(%d=%d*%d)", tempsum,(num[k]-'0'),(count-k));
					} else {
						//printf("(%d=%d*%d)", tempsum,j,(count-k));
						tempsum += j*(count-k);
					}
				}
				/*
				printf("\n");
				for(int z = 0; z < count; z++){
					if (z != i){
						printf("%c",num[z]);
					} else {
						printf("%c",j+'0');
					}					
				}
				printf(" / sum = %d", tempsum);
				*/
				if ((tempsum %= 11) == 0){
					//exit = 1;
					printf("\n[%d] -> %d: ",i,j);
					for(int z = 0; z < count; z++){
						if (z != i){
							printf("%c",num[z]);
						} else {
							printf("%c",j+'0');
						}
						
					}
				}
			}
			/*if (exit){
				break;
			}
			*/
			
		}
	} else {
		printf("\n[<] No errors");
	}
	
	return 0;
}