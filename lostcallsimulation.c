#include<stdio.h>
#include<stdbool.h>
#include<conio.h>
#include<stdlib.h>

int NTLine=8,MaxLinks=3,arrivaltime,MeanInterArrivalTime,MeanLength;
int callinProgress[7]={NULL};
int LengthofCallinProgress[3]={NULL};
int ArrivalofCall[3]={NULL};
indexing[6];
int Blocked,Busy,Processed,Completed;
int OriginCall,DestinationCall,LengthCall,SumofCallLength,sumofArrivalTime,ClosestArrivalTime=0;
bool StateofBusyCall=false,increaselengthcall=false;
int LinkInUse=0;
int Simulationtimer=0,nexttimer;
char clocktimerStop;
void main(){
    for(int i=1;i<=NTLine;i++){
        if(NTLine<(2*MaxLinks+2)){
            printf("Too Few Lines Specified. Simulation Abandoned.");
            exit (0);
        }else{
            ArrivalNow();
            printf("Simulation of Telephone System");
            printf("No. of Lines %d",NTLine);
            printf("No. of Maximum Links %d",MaxLinks);
            printf("No. of Links in Use %d",LinkInUse);
            printf("Mean Inter Arrival Time %d",MeanInterArrivalTime);
            printf("Mean Call Length %d",MeanLength);
            printf("Simulation clock Time %d",Simulationtimer);

            printf("Call Processed %d",Processed);
            printf("Call Completed  %d",Completed);
            printf("Busy Calls  %d",Busy);
            printf("Blocked calls %d",Blocked);

            ClosestArrivalTime= ArrivalofCall[0];
            for(int k=0;k<LinkInUse;k++){
                    if(ClosestArrivalTime<ArrivalofCall[k]){
                        ClosestArrivalTime = ArrivalofCall[k];
                    }}
            Simulationtimer = ClosestArrivalTime;
            if(increaselengthcall==true){
                LengthofCallinProgress[LinkInUse-1]= Simulationtimer + LengthCall;
                increaselengthcall=false;
            }
            printf("After Updated Simulation clock Time %d",Simulationtimer);
            Checkcounters();
            printf("Call Processed %d",Processed);
            printf("Call Completed %d",Completed);
            printf("Busy Calls %d",Busy);
            printf("Blocked calls %d",Blocked);

            }}
    getch();
}
void ArrivalNow(){
    printf("Enter the new Origin, Destination,Length and Arrival Time of the call");
    scanf("%d %d %d %d",&OriginCall,&DestinationCall,&LengthCall,&arrivaltime);
    if(LinkInUse>=MaxLinks){
            Blocked++;
            Processed = Processed + 1;
            printf("All links are in used. So blocked is increase now");
    }
    else{
        if((OriginCall>=0 && OriginCall <=7) && (DestinationCall>=0 && DestinationCall <=7)){
                if(callinProgress[OriginCall-1]!=1 && callinProgress[DestinationCall-1]!=1){
                    callinProgress[OriginCall-1]=1;
                    callinProgress[DestinationCall-1]=1;
                    }
                else{
                    StateofBusyCall=true;

                }
        }else{
            printf("Origin or Destination call entered is out of bounds");
            }

    if(StateofBusyCall==true){
        Busy++;
        StateofBusyCall = false;
    }
    if(callinProgress[OriginCall-1]==1 && callinProgress[DestinationCall-1]==1){
                    LinkInUse++;
                    increaselengthcall = true;
                    LengthofCallinProgress[LinkInUse-1]= Simulationtimer + LengthCall;
                    ArrivalofCall[LinkInUse-1] = arrivaltime + Simulationtimer;
                    for(int j=0;j<LinkInUse;j++){
                        SumofCallLength = LengthofCallinProgress[j] + SumofCallLength;
                        sumofArrivalTime = ArrivalofCall[j] + sumofArrivalTime;
                    }
                    MeanLength = SumofCallLength/LinkInUse;
                    MeanInterArrivalTime = sumofArrivalTime/LinkInUse;
    }}}
Checkcounters(){
    Processed++;
    for(int c=0;c<LinkInUse;c++){
        if(Simulationtimer>=LengthofCallinProgress[c]){
            LinkInUse--;
            Completed++;
        }}}
