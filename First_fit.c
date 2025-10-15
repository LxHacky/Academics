#include<stdio.h>
void First_fit(int p_size[],int n,int m,int m_size[])
{
    printf("\nFIRST FIT\n");
    int i,j;
    for(i=0;i<n;i++)
    {
        int flag = 0;
        for(j=0;j<m;j++)
        {
            if(m_size[j] >= p_size[i])
            {
                printf("\nprocess of size %d allocated in memory block of size %d",p_size[i],m_size[j]);
                 m_size[j] -= p_size[i];
                printf("\n=> %d space remaining in memory block\n",m_size[j]);
                flag = 1;
                break;
               
            }
        }
        if(flag == 0)
        {
            printf("\nprocess of size %d cannot be allocated\n",p_size[i]);
        }
    }

}
int main()
{
    int i,n,m;
    int p_size[100],m_size[100];
    printf("\nEnter the number of process : ");
    scanf("%d",&n);
    
    printf("\nEnter the memory allocated to each process\n");
    for(i=0;i<n;i++)
    {
        printf("\nprocess %d : ",i+1);
        scanf("%d",&p_size[i]);
    }
    printf("\nEnter the number of memory block : ");
    scanf("%d",&m);
    printf("\nEnter the size of each memory block\n");
    for(i=0;i<m;i++)
    {
        printf("\nBlock %d : ",i+1);
        scanf("%d",&m_size[i]);
    }
    First_fit(p_size,n,m,m_size);
}
