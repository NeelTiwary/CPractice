#include<stdio.h>
#include<limits.h>
int n;
// void printParen(int s[][n],int i,int j){
//   if(i==j){
//     printf("A%d ", i);
//   }
//   else{
//     printf("( ");
//     printParen(s, i, s[i][j]);
//     printParen(s, s[i][j] + 1, j);
//     printf(") ");
//   }
// }
int matrixChain(int arr[]){
  int m[n][n];
  int s[n][n];
  for (int i = 0; i < n;i++){
      m[i][i] = 0;
    }
  for (int j = 0; j < n;j++){
    s[j][j] = 0;
  }
  int j, q;
  for (int l = 2; l < n; l++)
  {
    for (int i = 1; i < n - l+1; i++)
    {
     j = i + l-1;
     m[i][j] = INT_MAX;
    for (int k = i; k <= j-1; k++)
    {
       q = m[i][k] + m[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
      if (q < m[i][j])
      {
        m[i][j] = q;
        s[i][j] = k;
      }
    }
    }
    }
    // for (int i = 0; i < n;i++){
    // for (int k = 0; k < n;k++){
    // printf("%d ", m[i][k]);
    // }
    // printf("\n");
    // }
    // printParen(s, 1, n);
    return m[1][n-1];
}
int main(){
  
  printf("Enter number of dimensions: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter dimensions: ");
  for (int i = 0; i < n;i++){
    scanf("%d", &arr[i]);
  }
  printf("Minimum multiplications required: %d ", matrixChain(arr));
}