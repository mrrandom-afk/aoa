#include <stdio.h>
int main()
{
int a[100], n, i, j, temp, k;
printf("Enter number of elements: ");
scanf("%d", &n);
printf("Enter elements:\n");

for(i = 0; i < n; i++)
{
scanf("%d", &a[i]);
}
printf("\nInitial Array: ");
for(i = 0; i < n; i++)
{
printf("%d ", a[i]);
}
printf("\n");
for(i = 1; i < n; i++)
{
temp = a[i];
j = i - 1;
while(j >= 0 && a[j] > temp)
{
a[j + 1] = a[j];
j--;
}
a[j + 1] = temp;
printf("Pass %d: ", i);
for(k = 0; k < n; k++)
{
printf("%d ", a[k]);
}
printf("\n");
}
printf("\nSorted Array: ");
for(i = 0; i < n; i++)
{
printf("%d ", a[i]);
}
return 0;
}