#include<stdio.h>
#include<stdlib.h>
#define max 20

typedef struct node
{
    float profit, weight, p_w;
}knapsack;

int main()
{
    int n, i,j;
    float capacity,profit=0.0,mul;
    printf("Enter the number of items in the knapsack: ");
    scanf("%d",&n);
    knapsack knap[n], knap1[n];
    for(i=0;i<n;i++)
    {
        scanf("%f %f",&knap[i].weight,&knap[i].profit);
        knap[i].p_w = knap[i].profit/knap[i].weight;
    }
    printf("Enter capacity: ");
    scanf("%f",&capacity);
    printf("Before Sorting\n");
    for(i=0;i<n;i++)
    {
        printf("%f %f %f\n",knap[i].profit,knap[i].weight, knap[i].p_w);
    }
    knapsack temp;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(knap[j].p_w>knap[j+1].p_w){
                temp = knap[j];
                knap[j] = knap[j+1];
                knap[j+1] = temp;
            }
        }
    }
    printf("After Sorting\n");
    for(i=0;i<n;i++)
    {
        printf("%f %f %f\n",knap[i].profit,knap[i].weight, knap[i].p_w);
    }
    int k=0;
    for(i=n-1;i>=0;i--)
    {
        knap1[k] = knap[i];
        k++;
    }
    for(i=0;i<n;i++){
        knap[i] = knap1[i];
    }
     printf("After Sorting\n");
    for(i=0;i<n;i++)
    {
        printf("%f %f %f\n",knap[i].profit,knap[i].weight, knap[i].p_w);
    }
    k=0;
    while(capacity != 0)
    {
        if(knap[k].weight < capacity)
        {
            capacity = (float) capacity - knap[k].weight;
            profit = profit + knap[k].profit;
            k++;
        }
        else
        {
            mul = (float)capacity/knap[k].weight;
            knap[k].weight = mul*knap[k].weight;
            knap[k].profit = mul*knap[k].profit;
            capacity = (float)capacity - knap[k].weight;
            profit = profit + knap[k].profit;
            k++;
        }
    }
    printf("%f",profit);
    return 0;
}
