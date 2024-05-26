#include <stdio.h>

struct P{
    int pid,bt,rt,wt,tat,at;
};

void calcTimes(struct P p[],int n,int q){
    int totalWT=0,totalTAT=0,curTime=0,completed=0;
    for (int i=0;i<n;i++)
        p[i].rt=p[i].bt;
    while (completed<n){
        int executed=0;
        for (int i=0;i<n;i++){
            if(p[i].rt>0 && p[i].at<=curTime){
                int ts=(p[i].rt>q)?q:p[i].rt;
                curTime+=ts;
                p[i].rt-=ts;
                if(p[i].rt==0){
                    completed++;
                    p[i].tat=curTime-p[i].at;
                    p[i].wt=p[i].tat-p[i].bt;
                    totalWT+=p[i].wt;
                    totalTAT+=p[i].tat;
                }
                executed=1;
            }
        }
        if(!executed)
            curTime++;
    }
    printf("\nAvg WT: %.2f",(float)totalWT/n);
    printf("\nAvg TAT: %.2f\n",(float)totalTAT/n);
}

int main(){
    int n,q;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    struct P p[n];
    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        printf("Enter BT and AT for P%d: ",p[i].pid);
        scanf("%d %d",&p[i].bt,&p[i].at);
    }
    printf("Enter the time quantum: ");
    scanf("%d",&q);
    calcTimes(p,n,q);
    return 0;
}
