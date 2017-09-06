#include <iostream.h>
#include <conio.h>

struct process
{
	int at;
	int bt;
	int tat;
	int wt;
	int rt; //remaining time
	
};

int main()
{
	process *p;
	/*int n,i,flag=0;
	int time,remain;*/
	int i,j,n,time,remain,flag=0,qt;
	float awt=0,atat=0;
	/*int count,j,n,time,remain,flag=0,time_quantum; 
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10]; */
	cout<<"\nEnter number of processes: ";
	cin>>n;
	cout<<"\nEnter time quantum: ";
	cin>>qt;
	p = new process[n];
	remain=n;
	for (i = 0; i < n; ++i)
	{
		/* code */
		cout<<"\nEnter arrival time of process "<<i<<": ";
		cin>>p[i].at;
		cout<<"\nEnter burst time of process "<<i<<": ";
		cin>>p[i].bt;
		p[i].rt=p[i].bt;
	}
	cout<<"\n\tP\tWT\tTAT";
	for(time=0,i=0;remain!=0;)
	{
		if(p[i].rt<=qt && p[i].rt>0)
		{
			time+=p[i].rt;
			p[i].rt=0;
			flag=1;
		}
		else if(p[i].rt>0)
		{
			p[i].rt-=qt;
			time+=qt;
		}
		if(p[i].rt==0 && flag==1)
		{
			remain--;
			cout<<"\n\t"<<i<<"\t"<<time-p[i].at-p[i].bt<<"\t"<<time-p[i].at;
			p[i].wt+=time-p[i].at-p[i].bt;
			p[i].tat+=time-p[i].at;
			awt+=p[i].wt;
			atat+=p[i].tat;
			flag=0;
		}
		if(i==n-1)
			i=0;
		else if(p[i+1].at<=time)
			i++;
		else
			i=0;
	}
	cout<<"\nAverage waiting time: "<<awt/n;
	cout<<"\nAverage turn around time: "<<atat/n;
	getch();
	clrscr();
	return 0;
}