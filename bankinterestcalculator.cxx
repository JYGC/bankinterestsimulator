#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
using namespace std;

int main()
{
    cout<<"___________________________________________________\n\n";
    cout<<"BANK INTEREST CALCULATOR\n\nWritten by JunYing Chen\n";
    cout<<"___________________________________________________";

    cout<<"\n\n\n\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
            cout<<"@                                               @\n";
            cout<<"@  WARNING!!                                    @\n";
            cout<<"@                                               @\n";
            cout<<"@  DO NOT ENTER LETTERS IN AS THIS WOULD CAUSE  @\n";
            cout<<"@  THE PROGRAM TO ENTER AN INFINITE LOOP.       @\n";
            cout<<"@                                               @\n";
            cout<<"@  IF THE PROGRAM ENTERS AN INFINITE LOOP,      @\n";
            cout<<"@  PRESS 'CTRL'+'C' TO EXIT THE PROGRAM         @\n";
            cout<<"@                                               @\n";
            cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";

    while(1){

    int daylim;
    int day=0;
    float interest;
    float oamount;
    float amount1;
    float amount2;
    float gain;
    float acgain;
    float intax;
    float tax;
    float actax=0;
    float tacgain;

    cout<<"\n\n\n\nBank interest rate per year (%): "; cin>>interest;
    fstream pr;
    pr.open("bankintreset_log.txt", fstream::out);
    pr<<"\n\n\n\n"<<"---"<<time(0)<<"---";
    pr.flush();

    pr<<"\n\n\nBank interest rate per year: "<<interest<<"%";
    pr.flush();

    cout<<"\n\nInvestment (Enter -1 to reset): $"; cin>>oamount;
    if(oamount==-1) cout<<"-------RESET-------";
    else{
        pr<<"\n\nInvestment: $"<<oamount;
        pr.flush();

        cout<<"\n\nIncome tax (Enter -1 to reset) (%): "; cin>>intax;
        if(intax==-1) cout<<"-------RESET-------";
        else{
            pr<<"\n\nIncome tax (%): "<<intax;
            pr.flush();

            cout<<"\n\nDuration in days (Enter -1 to reset): "; cin>>daylim;
            if(daylim==-1) cout<<"-------RESET-------";
            else{
                pr<<"\n\nDuration in days: "<<daylim;
                pr.flush();

                for(day=0; day<=daylim; day++)
                    {
                    if(day==0){amount1=oamount;}
                    else{amount1=oamount*pow(1+(0.01*interest/365),day-1);}

                    amount2=oamount*pow(1+(0.01*interest/365),day);
                    gain=amount2-amount1;
                    tax=gain*intax*0.01;
                    acgain=amount2-oamount;
                    actax=actax+tax;
                    tacgain=acgain-actax;

                    cout<<"\n\nDay: "<<day<<" -Amount: $"<<amount2<<endl;
                    cout<<"        "<<"-Interest/day: $"<<gain<<endl;
                    cout<<"        "<<"-Accumulated Interest: $"<<acgain<<endl;
                    cout<<"        "<<"-Tax/day: $"<<tax<<endl;
                    cout<<"        "<<"-Accumulated Tax: $"<<actax<<endl;
                    cout<<"        "<<"-Accumulated interest after tax: $"<<tacgain<<endl;

                    pr<<"\n\nDay: "<<day<<" -Amount: $"<<amount2<<endl;
                    pr.flush();
                    pr<<"        "<<"-Interest/day: $"<<gain<<endl;
                    pr.flush();
                    pr<<"        "<<"-Accumulated Interest: $"<<acgain<<endl;
                    pr.flush();
                    pr<<"        "<<"-Tax/day: $"<<tax<<endl;
                    pr.flush();
                    pr<<"        "<<"-Accumulated Tax: $"<<actax<<endl;
                    pr.flush();
                    pr<<"        "<<"-Accumulated interest after tax: $"<<tacgain<<endl;
                    pr.flush();
                    }
                pr.close();
                }
            }
        }
    }
}
