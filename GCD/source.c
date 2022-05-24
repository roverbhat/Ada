#include<stdio.h>
#include<stdlib.h>
#define x 10
#define y 200
void gcd(int choice){
        FILE *inp;
        FILE *out;
        int check=0,max,min,a,b,tm,tn,tcount,r,tmin,m,n,u,v,temp;
        if(choice==1||choice==2||choice==3){
            printf("enter 1 for best case of gcd\n");
            printf("Enter 2 for worst case of gcd\n");
            scanf("%d",&check);
        }
        else{
            return;
        }
        for(int i=x;i<200;i=i+10){
            max=0;min=99999;
            for(int a=1;a<i;a++){
                for(int b=1;b<i;b++){
                    tm=a;
                    tn=b;
                    u=a;
                    v=b;
                    tcount=0;
                    if(choice==1){
                       while(tn!=0){
                           tcount++;
                            r=tm%tn;
                            tm=tn;
                            tn=r;
                       } 
                    }
                    else if(choice==2){
                        tmin=(tm<tn)?tm:tn;
                        while(tmin!=1){
                            tcount++;
                            if(tm%tmin==0 && tn%tmin==0){
                                break;
                            }
                            tmin--;
                        }
                    }
                    else{
                           while(tn>0){
                               tcount++;
                               if (tm<tn){
                                   temp=tn;
                                   tn=tm;
                                   tm=temp;
                               }
                               tm=tm-tn;
                           }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
                    }
                    if(check==1){
                        if(tcount<min){
                            min=tcount;
                            m=a;
                            n=b;
                        }
                    }
                    else{
                        if(tcount>max){
                            max=tcount;
                            m=a;n=b;
                        }
                    }

                }
            }
            if(choice==1){
                if(check==1){
                    inp=fopen("ubi.txt","a");
                    fprintf(inp,"%d  and %d\n",u,v);
                    out=fopen("ubr.txt","a");
                    fprintf(out,"%d\t%d\n",i,min);
                }
                else{
                    inp=fopen("uwi.txt","a");
                    fprintf(inp,"%d  and %d\n",u,v);
                    out=fopen("uwr.txt","a");
                    fprintf(out,"%d\t%d\n",i,max);
                }
            }
            else if(choice==2){
                if(check==1){
                    inp=fopen("cbi.txt","a");
                    fprintf(inp,"%d  and %d\n",u,v);
                    out=fopen("cbr.txt","a");
                    fprintf(out,"%d\t%d\n",i,min);
                }
                else{
                    inp=fopen("cwi.txt","a");
                    fprintf(inp,"%d  and %d\n",u,v);
                    out=fopen("cwr.txt","a");
                    fprintf(out,"%d\t%d\n",i,max);
                }
            }
            else{
                if(check==1){
                    inp=fopen("mubi.txt","a");
                    fprintf(inp,"%d  and %d\n",u,v);
                    out=fopen("mubr.txt","a");
                    fprintf(out,"%d\t%d\n",i,min);
                }else{
                    inp=fopen("muwi.txt","a");
                    fprintf(inp,"%d  and %d\n",u,v);
                    out=fopen("muwr.txt","a");
                    fprintf(out,"%d\t%d\n",i,max);
                }
            }
            fclose(inp);
            fclose(out); 
        }

}
int main(){
    int lp=1;
    int choice;
    system("rm -r  cbr.txt  cwr.txt   mubr.txt  muwr.txt  ubi.txt  uwi.txt cbi.txt  cwi.txt  mubi.txt  muwi.txt ubr.txt  uwr.txt");
    while(lp){
        printf("press 1 for uclid\n");
        printf("press 2 for conosi\n");
        printf("press 3 for modified\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            case 2:
            case 3:
                gcd(choice);
                break;
            case 4:
                lp=0;
        }
    }
}