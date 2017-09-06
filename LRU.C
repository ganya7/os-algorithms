#include <stdio.h>

void LRU()
{
    int frame[3]={-1,-1,-1},used[3]={-1,-1,-1},cnt=0,ref[20],i,j,flag,no,index,value;
    float ratio,hitcnt=0;
    int miss=0;
    printf("\n\tEnter number of pages: ");
    scanf("%d",&no);
    printf("\n\tEnter the page sequence: \n\t");
    for(i=0;i<no;i++)
        scanf("%d",&ref[i]);
    //printf("\n\tExecution is started here ");
    for(i=0;i<no;i++)
    {
       flag=0;
       for(j=0;j<3;j++)
           if(frame[j]==ref[i])
           {
               printf("\n\tPage Hit ");
               hitcnt++;
               flag=1;
               used[j]=cnt;
               break;
           }
           if(flag==0)
           {
               printf("\n\tPage Miss");
               printf("\tBefore :");
               for(j=0;j<3;j++)
                   printf(" %d",frame[j]);
	    //selection of victim for replacement
               index=0;
               value=used[0];
               if(cnt!=0)  {
                   for(j=0;j<3;j++)
                       if(value>used[j]&&value!=used[j])
                       {
                          index=j;
                          value=used[j];
                      }
                  }
	//printf("\tVictim is %d ",index);
                  frame[index]=ref[i];
                  used[index]=cnt;
                  printf("\tAfter :");
                  for(j=0;j<3;j++)
                   printf(" %d",frame[j]);
               miss++;
           }
           cnt++;
       }
       printf("\nHit count: %f",hitcnt);
       printf("\nMiss count: %d",miss);
       ratio=hitcnt/no;
       printf("\n\n\tHit ratio = %f ",ratio);
       printf("\nMiss ratio = %f",(float)miss/no);
   }

   void main()
   {
    LRU();
    getch();
    clrscr();
   }
