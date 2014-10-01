/* Hamming Project in C++ - ARMAAN BINDRA 10/4/2013 */

#include <iostream>
#include <math.h>
using namespace std;

/*Function Converts the Binary Hamming Code into an Integer*/

int convInt(int array[])
{
    int ans=0;
    int i;
    int j=-1;
    for (i=20; i>=0; i--) {
        j++;
        ans = ans + (array[i]*(pow(2.0,j)));
        //cout<<"i is"<<i<<endl;
    }
    
    return ans;
}

/*Function parB1 takes in the 21 bit formatted array and assigns Parity Bit 1 its Correct Value*/

int parB1(int arr[])
{
    int i=0;
    int par=0;
    while (i<20) {
        if(arr[i]==1)
        {par++;}
        i=i+2;
    }
    if(arr[i]==1){par++;}
    if(arr[0]==1){par--;}//make sure parity bit value not counted
        //cout<<"par is "<<par<<endl;
        if((par % 2)==0)
        {arr[0]=0;}
        else{arr[0]=1;/*cout<<"Parity Bit 1 is set to 1\n";*/}
}

/*Function parB2 takes in the 21 bit formatted array and assigns Parity Bit 1 its Correct Value*/

int parB2(int arr[])
{
    int i=1;
    int par=0;
    while (i<20) {
        if(arr[i]==1)
        {par++;}
        if(arr[i+1]==1)
        {par++;}
        i=i+4;
    }
    //cout<<"par is "<<par<<endl;
    //if(arr[0]==1){par--;}
    if(arr[1]==1){par--;}//make sure parity bit value not counted
        if((par%2)==0)
        {arr[1]=0;}
        else{arr[1]=1;/*cout<<"Parity Bit 2 is set to 1\n";*/}
}

/*Function parB4 takes in the 21 bit formatted array and assigns Parity Bit 1 its Correct Value*/

int parB4(int arr[])
{
    int i=3;
    int par=0;
    while (i<20) {
        for(int j=0;j<4;j++)
        {
            if(arr[i]==1)
            {par++;i++;}
            else{i++;}
        }
        if(i==7){i=11;}
        else if(i==15){i=19;}
    }
    //cout<<"par is "<<par<<endl;
    if(arr[3]==1){par--;}//make sure parity bit value not counted
        if((par%2)==0)
        {arr[3]=0;}
        else{arr[3]=1;/*cout<<"Parity Bit 4 is set to 1\n";*/}
}

/*Function parB8 takes in the 21 bit formatted array and assigns Parity Bit 1 its Correct Value*/

int parB8(int arr[])
{
    int par=0;
    for(int i=7;i<14;i++)
    {
        if(arr[i]==1){par++;}//cout<<"i="<<i<<",par="<<par<<endl;
    }
    if(arr[14]==1){par++;};
    if(arr[7]==1){par--;}//make sure parity bit value not counted
    //cout<<"par is "<<par<<endl;
        if((par%2)==0)
        {arr[7]=0;}
        else{arr[7]=1;/*cout<<"Parity Bit 8 is set to 1\n";*/}
}

/*Function parB16 takes in the 21 bit formatted array and assigns Parity Bit 1 its Correct Value*/

int parB16(int arr[])
{
    int par=0;
    for(int i=15;i<20;i++)
    {
        if(arr[i]==1){par++;}
        //cout<<"i is "<<i<<endl;
    }
    if(arr[20]==1){par++;}
    //cout<<"par is "<<par<<endl;
    if(arr[15]==1){par--;}//make sure parity bit value not counted
        if((par%2)==0)
        {arr[15]=0;}
    else{arr[15]=1;/*cout<<"Parity Bit 16 is set to 1\n";*/}
    
}

/* This hamming function takes in a hexadecimal 16 bit integer as an argument and returns a hexadecimal 21 bit Hamming Code*/

int hamming(long int val)
{
    int * disp;
    disp = new int [21];
    //setupDisp(val,disp);
    int * initial;
    int * rev;
    initial = new int [16];
    rev = new int [16];
    int n;
    int tmp;
    for(n=0;n<16;n++)
    {
        tmp = (val & (1 << n)) >>n;
        initial[n] = tmp;
        //cout<<tmp;
    }
    int l;
    int j=0;
    for(l=15;l>=0;l--)
    {
        //cout<<disp[l];
        rev[j]=initial[l];
        j++;
    }
    int i =1;
    int b;
    int c;
    int d;
    disp[0]=0;//1
    disp[1]=0;//2
    disp[2]=rev[0];//3
    disp[3]=0;//4
    for(b=4;b<7;b++)
    {
        disp[b]=rev[i];
        i++;
    }
    disp[7]=0;
    for(c=8;c<15;c++)
    {
        disp[c]=rev[i];
        i++;
    }
    disp[15]=0;
    for(d=16;d<20;d++)
    {
        disp[d]=rev[i];
        i++;
    }
    disp[20]=rev[i];
    parB1(disp);
    parB2(disp);
    parB4(disp);
    parB8(disp);
    parB16(disp);
    int ans=convInt(disp);
    //cout<<"ans is "<<ans;
    return ans;
}

/*The Interface Function Runs the Program One Time Through*/
int interface()
{
        cin.setf(ios::hex, ios::basefield);
        cout.setf(ios::hex, ios::basefield);
        //cout<<"This seems to be working"<<endl;
        long int user_input;
        cout<<"Enter a four-digit hexadecimal value: ";cin>>user_input;
        //cout.setf(ios::hex, ios::basefield);
        cout<<"The hamming code is "<<hamming(user_input)<<endl;

}

int main()
{
    int a =1;
    while (a==1) {
        interface();
    }
    return 0;
}