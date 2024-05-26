#include <stdio.h>
#include <stdlib.h>

struct P{
    int at,bt,wt,tat;
};

float avgWT(struct P p[],int n);
float avgTAT(struct P p[],int n);

int main(){
    int n,comp=0;
    float avg_wt,avg_tat;
    printf("Enter number of processes:\n");
    scanf("%d",&n);
    struct P p[n];
    printf("Enter arrival and burst times for all processes:\n");
    for(int i=0;i<n;i++){
        printf("Arrival time for P%d:\n",i+1);
        scanf("%d",&p[i].at);
        printf("Burst time for P%d:\n",i+1);
        scanf("%d",&p[i].bt);
        comp+=p[i].bt;
        p[i].tat=comp-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
    }
    avg_wt=avgWT(p,n);
    printf("\nAvg WT: %.2f\n",avg_wt);
    avg_tat=avgTAT(p, n);
    printf("\nAvg TAT: %.2f\n",avg_tat);
    return 0;
}
float avgWT(struct P p[],int n){
    int wt=0;
    for (int i=0;i<n;i++){
        wt+=p[i].wt;
    }
    return (float)wt/n;
}
float avgTAT(struct P p[],int n){
    int tat=0;
    for(int i=0;i<n;i++){
        tat+=p[i].tat;
    }
    return (float)tat/n;
}
