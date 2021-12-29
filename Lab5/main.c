#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int N=0;
    double *A, *B;
    FILE *test, *rezultat, *binar;

    test = fopen("test.txt", "r");
    fscanf(test, "%u", &N);

  A = (double *) calloc(N, sizeof(double));
   if(A == NULL) {
       printf("\nError");
       printf("\nPress any key to exit...");
       getch();
       exit(1);
   }
    masive(A, N);

    rezultat = fopen("rezultat.txt", "w");
    if(rezultat == NULL) {
      printf("Cannot open a file!!!\n");
      printf("Press any key to exit...");
      getch();
      exit(1);
   }
    for (int i = 0; i < N; i++)  fprintf(rezultat, "%3d", A[i]);

    binar = fopen("binar.bin", "wb");
    if(binar == NULL) {
      printf("Cannot open a file!!!\n");
      printf("Press any key to exit...");
      getch();
      exit(1);
   }
    for (int i = 0; i < N; i++) fwrite(&A[i], sizeof (double), 1, binar);


if ((fclose(test) !=0) || (fclose(rezultat) !=0) || (fclose(binar) !=0)) {
    printf("Cannot closes a file!!!\n");
      printf("Press any key to exit...");
      getch();
      exit(1);
}



binar = fopen("binar.bin", "rb");
    if(binar == NULL) {
      printf("Cannot open a file!!!\n");
      printf("Press any key to exit...");
      getch();
      exit(1);
   }

   B = (double*) malloc(N * sizeof (double));
    if(B == NULL) {
      printf("Error!!!\n");
      printf("Press any key to exit...");
      getch();
      exit(1);
    }

       for (int i = 0; i < N; i++) {
            fread(B, sizeof (double), N, binar);
            printf("\nB[%i]=%d", i, B[i]);
    }

    free(A);
    free(B);

    if (fclose(binar) !=0) {
    printf("Cannot closes a file!!!\n");
      printf("Press any key to exit...");
      getch();
      exit(1);
}

    return 0;
}

void masive(double *A, int N)
{
 for (int i = 0; i < N; i++) {
    printf("vedin znach A[%i]:", i);
    scanf("%i", &A[i]);
 }
}
