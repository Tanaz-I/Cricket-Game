#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>

//this structure stores information about team players

typedef struct
{
    char player[50];
    int player_no;
    int wckt;
    int bowl_ball;
    int runs;
    int score;
    int ball;
}team;

//this structure stores information regarding innings

typedef struct
{
    int score;
    int wckt;
}innings;

//this strcuture stores highest stat info

typedef struct
{
    char player_bat[50];
    int max_run;
    float strike_rate;
    char player_ball[50];
    int wickets;
    float economy_rate;
}sum;
innings o[2];
team a[5],b[5];
team a1[10],b1[10];
sum s[3];
float str_rate[5];
float eco_rate[5];

void getdata(team a[],int n);
void match1(FILE *A);
void match2(FILE *B);
void input_file(FILE *C,team a[],team b[]);
void summary(FILE *C,int,team a1[],team b1[]);
void overall_stats();
void scorecard(FILE *C,int,team a1[],team b1[]);
int isname(char[]);
int main()
{
    system("COLOR b0");
    int i,choice;
    FILE *A,*B;
    A=fopen("TEAM_A.txt","w");
    B=fopen("TEAM_B.txt","w");
    printf("\n**************************************************************************************************************\n\n");
    printf("\t\t\t\tWELCOME TO CRICKET GAME\n");
    printf("\n**************************************************************************************************************\n\n");
    printf("INSTRUCTIONS\n\n");
    printf("There are 2 teams.\nEach team has 5 players\nTotal number of overs:10\n");
    printf("0-no run\n1-1run\n2-2runs\n3-3runs\n4-4 runs\n5-5runs\n6-6runs\n7-wide\n8-wicket\n9-no ball\n");
    printf("note:wide-1 extra ball and 1 run\n no ball-free hit(if wicket is taken in that ball it will not be considered)\n");
    printf("\n**************************************************************************************************************\n\n");
    printf("\t\t\t\tTHE GAME BEGINS\n");
    printf("Enter name of players of team1:\n");
    getdata(a,0);
    printf("Enter name of players of team2:\n");
    getdata(b,5);
    printf("\n**************************************************************************************************************\n\n");
    printf("INNINGS 1\n TEAM 1 BAT\tTEAM 2 BOWL\n");
    match1(A);
    printf("\n**************************************************************************************************************\n\n");
    printf("INNINGS 2\n TEAM 2 BAT\nTEAM 1 BOWL\n");
    match2(B);
    printf("\n**************************************************************************************************************\n\n");
    if(o[0].score>o[1].score)
    {
        printf("TEAM 1 WON BY %d RUNS",o[0].score-o[1].score);
        printf("\n**************************************************************************************************************\n\n");
    }
    if(o[0].score==o[1].score)
    {
        printf("MATCH DRAW\n");
        printf("\n**************************************************************************************************************\n\n");
    }
    A=fopen("TEAM_A.txt","r");
    B=fopen("TEAM_B.txt","r");
    char ch;
    do
    {
        printf("\nCHOOSE THE OPTIONS\n");
        printf("1.SCORECARD \n2.STATS\n");
        scanf(" %d",&choice);
        switch(choice)
        {
            case 1:
                scorecard(A,1,a1,b1);
                printf("\n**************************************************************************************************************\n\n");
                scorecard(B,2,b1,a1);
                break;
            case 2:
                summary(A,0,a1,b1);
                printf("\n**************************************************************************************************************\n\n");
                summary(B,1,b1,a1);
                printf("\n**************************************************************************************************************\n\n");
                overall_stats();
                break;
            default:
                printf("SORRY!!!INVALID OPTION NUMBER\n");
                break;
        }
        printf("\n**************************************************************************************************************\n\n");
        printf("Enter y to continue\nDo you want to continue???  ");
        scanf(" %c",&ch);
        printf("\n**************************************************************************************************************\n\n");
    }while(ch=='y'||ch=='Y');
    fclose(A);
    fclose(B);
}

//Function to validate player name

int isname(char name[])
{
        int n,k=0,i;
        n=strlen(name);
        for(i=0;i<n;i++)
        {
                if(isalpha(name[i]))
                        k=1;
                else
                {
                        k=0;
                        break;
                }
        }
        return(k);
}

//function to get player data

void getdata(team a[],int n)
{
    int i;
    for(i=1;i<=5;i++)
    {
        do
        {
        printf("PLAYER %d NAME\n",i+n);
        scanf(" %s",a[i-1].player);
        if(isname(a[i-1].player))
                break;
        else
                printf("Enter a valid name\n");
        }
        while(1);
        a[i-1].player_no=i+n;
    }
}

//Function for innings1

void match1(FILE *A)
{
    int i,j,k=0,run;
    int wckt=0;
    int t;
    int bowl;
    int score=0;
    int tot_score=0;
    for(i=1;i<=10;i++)
    {
        do
        {
        printf("CHOOSE PLAYER NUMBER TO BOWL FROM TEAM 2:");
        scanf("%d",&bowl);
        if(bowl>=6&&bowl<=10)
            break;
        else
            printf("Enter valid team 2 player number\n");
        }while(1);
        for(j=0;j<5;j++)
        {
            if(bowl==b[j].player_no)
            {
                t=j;

            }
        }
        printf("OVER %d\n",i);
        for(j=1;j<=6;j++)
        {
            do
            {
                printf("Enter run: ");
                scanf("%d",&run);
                if(run<=9&&run>=0)
                {
                    break;
                }
                else
                    printf("enter valid run\n");
            }while(1);
                    if(run<=6)
                    {
                        score=score+run;
                        a[k].score=a[k].score+run;
                        a[k].ball+=1;
                        b[t].bowl_ball+=1;
                    }
                    if(run==8)
                    {
                        printf("Wicket\n");
                        wckt=wckt+1;
                        a[k].ball+=1;
                        b[t].wckt+=1;
                        k+=1;
                        b[t].bowl_ball+=1;
                        if(wckt==5)
                            break;
                    }
                    if(run==7)
                    {
                        printf("Wide\n");
                        score+=1;
                        a[k].ball+=1;
                        b[t].bowl_ball+=1;
                        j--;
                    }
                    if(run==9)
                    {
                            b[t].bowl_ball+=1;
                            printf("no ball...you get a Free hit\n");
                            printf("Enter run: ");
                            scanf("%d",&run);
                            if(run==7)
                            {
                                printf("wide\n");
                                b[t].bowl_ball+=1;
                                score+=1;
                                a[k].ball+=1;
                                j--;
                            }
                            if(run<=6)
                            {
                                b[t].bowl_ball+=1;
                                score=score+run;
                                a[k].score=a[k].score+run;
                                a[k].ball+=1;
                            }
                    }
        }
        b[t].runs=b[t].runs+score;
        tot_score=tot_score+score;
        score=0;
        printf("AFTER THE END OF OVER %d: %d|%d\n",i,tot_score,wckt);
        if(wckt==5)
        {
            printf("ALL OUT\n");
            break;
        }
   }

    o[0].score=tot_score;
    o[0].wckt=wckt;
    printf("TEAM 1 TOTAL SCORE: %d|%d\n",o[0].score,o[0].wckt);

    //nested function to pass input to file

    input_file(A,a,b);

}

//function for innings2

void match2(FILE *B)
{
    int t;
    int i,j,k=0,run;
    int wckt=0;
    int bowl;
    int score=0;
    int tot_score=0;
    b[0].score=0;
    b[0].ball=0;
    for(i=1;i<=10;i++)
    {
        do
        {
        printf("CHOOSE PLAYER NUMBER TO BOWL FROM TEAM 1:");
        scanf("%d",&bowl);
        if(bowl>=1&&bowl<=5)
            break;
        else
            printf("Enter valid team 1 player number\n");
        }while(1);
        for(j=0;j<5;j++)
        {
            if(bowl==a[j].player_no)
                t=j;

        }
        printf("OVER %d\n",i);
        for(j=1;j<=6;j++)
        {
            do
            {
            printf("Enter run: ");
            scanf("%d",&run);
            if(run<=9&&run>=0)
            {
            break;
            }
            else
            {
                printf("enter valid run\n");
            }
            }while(1);
            if(run<=6)
            {
                score=score+run;
                b[k].score=b[k].score+run;
                b[k].ball+=1;
                a[t].bowl_ball+=1;
            }
            if(run==8)
            {
                printf("wicket\n");
                wckt=wckt+1;
                a[t].bowl_ball+=1;
                b[k].ball+=1;
                a[t].wckt+=1;
                k+=1;
                b[k].score=0;
                b[k].ball=0;
                if(wckt==5)
                    break;
            }
            if(run==7)
            {
                printf("wide\n");
                score+=1;
                b[k].ball+=1;
                a[t].bowl_ball+=1;
                j--;
            }
            if(run==9)
            {
                    a[t].bowl_ball+=1;
                    printf("noball...you get a free hit\n");
                    printf("Enter run: ");
                    scanf("%d",&run);
                    if(run<=6)
                    {
                        score=score+run;
                        b[k].score=b[k].score+run;
                        b[k].ball+=1;
                        b[t].bowl_ball+=1;

                    }
                    if(run==7)
                    {
                        printf("wide\n");
                        score+=1;
                        b[k].ball+=1;
                        b[t].bowl_ball+=1;
                        j--;

                    }

            }
            if(tot_score+score>o[0].score)
            {
                printf("\n**************************************************************************************************************\n\n");
                printf("TEAM 2  WON BY %d WICKETS\n",5-wckt);
                break;
            }

        }
        a[t].runs=a[t].runs+score;
        tot_score=tot_score+score;
        score=0;
        if(tot_score>o[0].score)
        {
            break;
        }
        if(wckt==5)
        {
            printf("ALL OUT\n");
            break;
        }
        printf("AFTER THE END OF OVER %d: %d|%d\n",i,tot_score,wckt);
        printf("%d RUNS FOR TEAM 2 TO WIN\n",o[0].score-tot_score);
        }
    //nested function to pass input to file
    input_file(B,b,a);
    o[1].wckt=wckt;
    o[1].score=tot_score;
    printf("TEAM 2 TOTAL SCORE: %d|%d\n",o[1].score,o[1].wckt);
}

//function to input the data to file

void input_file(FILE *C,team a[],team b[])
{
    int i;
    float strike_rate=0;
    float economy_rate=0;
    for(i=0;i<5;i++)
    {
        if(a[i].ball>0)
         {
                strike_rate=((float)a[i].score)/((float)a[i].ball);
                fprintf(C,"%s %d %d %f",a[i].player,a[i].score,a[i].ball,strike_rate);
         }
        else
        {
                strike_rate=0;
                fprintf(C,"%s %d %d %f",a[i].player,a[i].score,a[i].ball,strike_rate);
        }
    }

    for(i=0;i<5;i++)
    {
        if(b[i].bowl_ball>0)
         {
                economy_rate=((float) b[i].runs)/((float)b[i].bowl_ball);
                fprintf(C,"%s %d %d %d %f",b[i].player,b[i].wckt,b[i].runs,b[i].bowl_ball,economy_rate);
         }
        else
        {
                economy_rate=0;
                fprintf(C,"%s %d %d %d %f",b[i].player,b[i].wckt,b[i].runs,b[i].bowl_ball,economy_rate);
        }

    }
    fclose(C);
}

//function to view the scorecard

void scorecard(FILE *C,int n,team a1[],team b1[])
{
    int i=0;
    rewind(C);
    while(!feof(C))
     {
        if(i<5)
         {
           fscanf(C,"%s %d %d %f",a1[i].player,&a1[i].score,&a1[i].ball,&str_rate[i]);
           i++;
         }
        else
         {
            fscanf(C,"%s %d %d %d %f",b1[i].player,&b1[i].wckt,&b1[i].runs,&b1[i].bowl_ball,&eco_rate[i]);
            i++;
         }
     }

   printf("\nSCORECARD FOR INNINGS %d\n",n);
   printf("BATTING\n");
   printf("PLAYER_NAME\t   SCORES\t\tBALL_FACED\t   STRIKE_RATE\n");
   for(i=0;i<5;i++)
    {
          printf("%-20s %-20d %-20d %-20.2f\n",a1[i].player,a1[i].score,a1[i].ball,str_rate[i]);
    }
   printf("BOWLING\n");
   printf("PLAYER_NAME\t WICKETS\t    RUNS_GAVE\t    BALLS_THROWN\t    ECONOMY_RATE\n");
   for(i=5;i<10;i++)
    {
          printf("%-20s %-20d %-20d %-20d %-20.2f\n",b1[i].player,b1[i].wckt,b1[i].runs,b1[i].bowl_ball,eco_rate[i]);
    }
}

//function to view the summary

void summary(FILE *C,int n,team a1[],team b1[])
{
    int i=0;
    float max_wkt=0;
    float max_score=0;

    char ch;

    i=0;
    while(!feof(C))
     {
        if(i<5)
         {
           fscanf(C,"%s %d %d %f",a1[i].player,&a1[i].score,&a1[i].ball,&str_rate[i]);
           i++;
         }
        else
         {
            fscanf(C," %s %d %d %d %f",b1[i].player,&b1[i].wckt,&b1[i].runs,&b1[i].bowl_ball,&eco_rate[i]);
            i++;
         }

     }
    for(i=0;i<10;i++)
    {
        if(i<5)
          {
           if(max_score<a1[i].score)
                {
                    max_score=a1[i].score;
                    strcpy(s[n].player_bat,a1[i].player);
                    s[n].max_run=a1[i].score;
                    s[n].strike_rate=str_rate[i];
                }
         }
        else
         {
           if(max_wkt<b1[i].wckt)
            {
                max_wkt=b1[i].wckt;
                strcpy(s[n].player_ball,b1[i].player);
                s[n].wickets=b1[i].wckt;
                s[n].economy_rate=eco_rate[i];
            }
         }

    }




    printf("\n\nINNINGS %d\n",n+1);
    printf("HIGHEST SCORER:%12s\n",s[n].player_bat);
    printf("SCORE:%21d\n",s[n].max_run);
    printf("STRIKE RATE:%15.2f\n\n",s[n].strike_rate);
    printf("HIGHEST WICKET TAKER: %5s\n",s[n].player_ball);
    printf("NUMBER OF WICKETS:%8d\n",s[n].wickets);
    printf("ECONOMY RATE:%14.2f\n",s[n].economy_rate);
}

//function to view overall stats

void overall_stats()
{
        int n=2;

        if(s[0].max_run<s[1].max_run)
                 {
                        s[n].max_run=s[1].max_run;
                        strcpy(s[n].player_bat,s[1].player_bat);
                        s[n].strike_rate=s[1].strike_rate;
                 }
        else
                 {
                        s[n].max_run=s[0].max_run;
                        strcpy(s[n].player_bat,s[0].player_bat);
                        s[n].strike_rate=s[0].strike_rate;
                 }
        if(s[0].wickets<s[1].wickets)
                 {
                        strcpy(s[n].player_ball,s[1].player_ball);
                        s[n].wickets=s[1].wickets;
                        s[n].economy_rate=s[1].economy_rate;
                 }
        else
                 {
                        strcpy(s[n].player_ball,s[0].player_ball);
                        s[n].wickets=s[0].wickets;
                        s[n].economy_rate=s[0].economy_rate;
                 }

        printf("\nOVERALL STATS\n");
        printf("HIGHEST SCORER%12s\n",s[n].player_bat);
        printf("SCORE%21d\n",s[n].max_run);
        printf("STRIKE RATE%15.2f\n\n",s[n].strike_rate);
        printf("HIGHEST WICKET TAKER%5s\n",s[n].player_ball);
        printf("NUMBER OF WICKETS%8d\n",s[n].wickets);
        printf("ECONOMY RATE%14.2f\n",s[n].economy_rate);
}

