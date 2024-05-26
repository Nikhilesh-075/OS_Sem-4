#include <stdio.h>
#include <limits.h>
struct P{
    int pid,at,bt,rt,wt,tat,ct;
};
int findMinRTProcess(struct P p[],int n,int curTime){
    int minIndex=-1,minRT=INT_MAX;
    for(int i=0;i<n;i++){
        if(p[i].at<=curTime && p[i].rt>0 && p[i].rt<minRT){
            minRT=p[i].rt;
            minIndex=i;
        }
    }
    return minIndex;
}
void calcTimes(struct P p[],int n){
    int totalWT=0,totalTAT=0,curTime=0,completed=0;
    while (completed<n){
        int minIndex=findMinRTProcess(p,n,curTime);
        if(minIndex==-1){
            curTime++;
            continue;
        }
        p[minIndex].rt--;
        curTime++;
        if(p[minIndex].rt==0){
            completed++;
            p[minIndex].ct=curTime;
            p[minIndex].tat=p[minIndex].ct-p[minIndex].at;
            p[minIndex].wt=p[minIndex].tat-p[minIndex].bt;
            totalWT+=p[minIndex].wt;
            totalTAT+=p[minIndex].tat;
        }
    }
    printf("\nAvg WT: %.2f", (float)totalWT / n);
    printf("\nAvg TAT: %.2f\n", (float)totalTAT / n);
}
int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    struct P p[n];
    for (int i=0;i<n;i++){
        p[i].pid=i+1;
        printf("Enter AT and BT for P%d: ", p[i].pid);
        scanf("%d %d",&p[i].at,&p[i].bt);
        p[i].rt=p[i].bt;
    }
    calcTimes(p,n);
    return 0;
}
