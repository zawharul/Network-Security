#include<stdio.h>
#include<math.h>

float encrypt[3][1], decrypt[3][1], a[3][3], b[3][3], mes[3][1], c[3][3];

void encryption();
void decryption();
void inverse();

int main()
{
   int i, j,choice;
	char text[3];

    printf("Enter a 3x3 key matrix (It should have inverse matrix):\n");

	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++) {
			scanf("%f", &a[i][j]);
			c[i][j] = a[i][j];
		}

	printf("\nEnter a 3 letter string: ");
	scanf("%s", text);

	for(i = 0; i < 3; i++)
		mes[i][0] = text[i] - 97;

    do{

    printf("\n\nHill Cipher\n\n1.Press 1 for Encryption\n2.Press 2 for decryption\n3.Press 3 for Exit\n");
    scanf("%d",&choice);
    switch(choice){

case 1:
   encryption();
    break;
case 2:
    decryption();
    break;
case 3:
    printf("Exit");
    break;
default:
    printf("Please enter a valid choice");
    break;
    }
    }
    while(choice!=3);
return 0;
}

void encryption() {
	int i, j, k;

	for(i = 0; i < 3; i++)
		for(j = 0; j < 1; j++)
			for(k = 0; k < 3; k++)
				encrypt[i][j] = encrypt[i][j] + a[i][k] * mes[k][j];

	printf("\nEncrypted string is: ");
	for(i = 0; i < 3; i++)
		printf("%c", (char)(fmod(encrypt[i][0], 26) + 97));

}

void decryption() {
	int i, j, k;

	inverse();

	for(i = 0; i < 3; i++)
		for(j = 0; j < 1; j++)
			for(k = 0; k < 3; k++)
				decrypt[i][j] = decrypt[i][j] + b[i][k] * encrypt[k][j];

	printf("\nDecrypted string is: ");
	for(i = 0; i < 3; i++)
		printf("%c", (char)(fmod(decrypt[i][0], 26) + 97));

	printf("\n");
}



void inverse() {
	int i, j, k;
	float p, q;

	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++) {
			if(i == j)
				b[i][j]=1;
			else
				b[i][j]=0;
		}

	for(k = 0; k < 3; k++) {
		for(i = 0; i < 3; i++) {
			p = c[i][k];
			q = c[k][k];

			for(j = 0; j < 3; j++) {
				if(i != k) {
					c[i][j] = c[i][j]*q - p*c[k][j];
					b[i][j] = b[i][j]*q - p*b[k][j];
				}
			}
		}
	}

	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			b[i][j] = b[i][j] / c[i][i];

	printf("\n\nInverse Matrix is:\n");
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++)
			printf("%d ", b[i][j]);

		printf("\n");
	}
}


