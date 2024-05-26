#include <stdio.h>
struct P{
    int pid,at,bt,wt,tat,ct;
};
void sortP(struct P p[],int n){
    struct P temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].at>p[j].at || (p[i].at==p[j].at && p[i].bt>p[j].bt)){
                temp=p[i];  p[i]=p[j];  p[j]=temp;
            }
        }
    }
}
void calcTimes(struct P p[],int n){
    int totalWT=0,totalTAT=0,curTime=0;
    for(int i=0;i<n;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(p[j].at<=curTime && p[j].bt<p[minIndex].bt){
                minIndex=j;
            }
        }
        struct P temp=p[i];
        p[i]=p[minIndex];
        p[minIndex]=temp;
        if (curTime<p[i].at){
            curTime=p[i].at;
        }
        p[i].ct=curTime+p[i].bt;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        curTime+=p[i].bt; totalWT+=p[i].wt;
        totalTAT+=p[i].tat;
    }
    printf("\nAvg WT: %.2f",(float)totalWT/n);
    printf("\nAvg TAT: %.2f\n",(float)totalTAT/n);
}
int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    struct P p[n];
    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        printf("Enter AT and BT for P%d: ",p[i].pid);
        scanf("%d %d",&p[i].at,&p[i].bt);
    }
    sortP(p,n); calcTimes(p,n); return 0;
}
