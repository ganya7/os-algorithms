#include <iostream.h>
#include <conio.h>
// #include <stdio>
//using namespace std;
struct process
{
	int at;
	int bt;
	int et;
	int wt;
	int tat;
};
int main()
{
	process p[10];
	int n,i;
	clrscr();
	cout<<"\nEnter number of processes: ";
	cin>>n;
	float awt;
	float atat;
	for ( i = 0; i < n; i++)
	{
		/* code */
		cout<<"\nEnter arrival time of process"<<i<<": ";
		cin>>p[i].at;
		cout<<"\nEnter burst time of process"<<i<<": ";
		cin>>p[i].bt;
	}
	p[0].et=p[0].bt+p[0].at;
	p[0].wt=0;
	p[0].tat=p[0].wt+p[0].bt;
	for ( i = 1; i < n; i++)
	{
		/* code */
		p[i].et=p[i-1].et+p[i].bt;
		p[i].wt=p[i-1].et-p[i].at;
		p[i].tat=p[i].wt+p[i].bt;
	}
	for ( i = 0; i < n; i++)
	{
		/* code */

		awt+=p[i].wt;
		atat+=p[i].tat;
	}
	awt/=n;
	atat/=n;
	//cout<<"\nProcess\tArrival Time\tBurst Time\tEnd Time \tWaiting Time\tTurn Around Time";
	cout<<"\nP\tAT\tBT\tET\tWT\tTAT\n";
	for(i=0;i<n;i++)
	{
		cout<<"P"<<i<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].et<<"\t"<<p[i].wt<<"\t"<<p[i].tat<<"\n";
	}
	cout<<"\nAverage Waiting time: "<<awt;
	cout<<"\nAverage Turn Around time: "<<atat;
	getch();
	return 0;
}