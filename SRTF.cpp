#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter How many process:";
    cin>>n;

    int process[10],arrival[10],Bursttime[10],Ctime[10],Ttime[10],Wtime[10],x[10];
    int temp=0,min,totalwait=0,time,count=0,a;

    for (int i=0; i<n; i++)
    {
        cout << "Enter Process Sequence:";
        cin>> process[i];
    }
    for (int i=0; i<n; i++)
    {
        cout << "Enter Arrival Time:";
        cin>> arrival[i];
    }
    for (int i=0; i<n; i++)
    {
        cout << "Enter Burst Time:";
        cin>> Bursttime[i];
    }

    for(int i=0; i<n; i++)
    {
        x[i]=Bursttime[i];
    }


    cout<< "\nScheduling sequence using SRTF :"<<endl;
    Bursttime[n]=88999;
    for(time=0; count!=n; time++)
    {
        min=n;
        for(int i=0; i<n; i++)
        {
            if(arrival[i]<=time && Bursttime[i]<Bursttime[min] && Bursttime[i]>0 )
                min=i;
        }
        cout<< "P"<<process[min]<<"->";

        Bursttime[min]--;

        if(Bursttime[min]==0)
        {
            count++;
            a=time+1;
            Ctime[min] = a;
            Wtime[min] = a - arrival[min] - x[min];
            Ttime[min] = a - arrival[min];
        }
    }
    cout<<endl;


    for (int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(Ctime[i]>Ctime[j])
            {
                temp=process[i];
                process[i]=process[j];
                process[j]=temp;

                temp=arrival[i];
                arrival[i]=arrival[j];
                arrival[j]=temp;

                temp=x[i];
                x[i]=x[j];
                x[j]=temp;

                temp=Ctime[i];
                Ctime[i]=Ctime[j];
                Ctime[j]=temp;

                temp=Ttime[i];
                Ttime[i]=Ttime[j];
                Ttime[j]=temp;

                temp=Wtime[i];
                Wtime[i]=Wtime[j];
                Wtime[j]=temp;
            }
        }
    }




    cout<< "\nProcess\tArrival\ttBrusttime\tCtime\tTurnAroundTime\t\tWaitingtime"<<endl;

    for(int i=0; i<n; i++)
    {

        cout<<"P"<<process[i]<<"\t"<<arrival[i]<<"\t\t"<<x[i]<<"\t"<<Ctime[i]<<"\t\t"<<Ttime[i]<<"\t\t"<<Wtime[i]<<endl;
        totalwait += Wtime[i];
    }
    cout<< "Total Waiting Time ="<<totalwait<<endl;
    float avgwait = totalwait /float (n);
    cout<< "Avg Waiting Time ="<<avgwait;

    return 0;

}

