/* Hamming Project in C++ and a Hamming Code Checker - ARMAAN BINDRA 10/4/2013 */

#include <iostream>
#include <math.h>
using namespace std;

/*Function Converts the Binary Hamming Code into an Integer*/

int convInt(int array[],int size)//Function Converts the Binary Hamming Code into an Integer
{
    int ans=0;
    int i;
    int j=-1;
    for (i=(size-1); i>=0; i--) {
        j++;
        ans = ans + (array[i]*(pow(2.0,j)));
        //cout<<"i is"<<i<<endl;
    }
    
return ans;
}

/*Function parB1 takes in the 21 bit formatted array and assigns Parity Bit 1 its Correct Value and for the Checker it returns a bool indicating whether the parity bit is right*/

bool parB1(int arr[],int trn)
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
     if(trn==0){
    //cout<<"par is "<<par<<endl;
    if((par % 2)==0)
    {arr[0]=0;}
         else{arr[0]=1;/*cout<<"Parity Bit 1 is set to 1\n";*/}}
    else if(trn==1)
    {
        return (((par%2==0)&&arr[0]==0)||((par%2==1)&&arr[0]==1));
    }
}

/*Function parB2 takes in the 21 bit formatted array and assigns Parity Bit 1 its Correct Value and for the Checker it returns a bool indicating whether the parity bit is right*/

bool parB2(int arr[],int trn)
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
        if(trn==0){
    if((par%2)==0)
    {arr[1]=0;}
            else{arr[1]=1;/*cout<<"Parity Bit 2 is set to 1\n";*/}}
    else if(trn==1)
    {
        return (((par%2==0)&&arr[1]==0)||((par%2==1)&&arr[1]==1));
    }
}

/*Function parB4 takes in the 21 bit formatted array and assigns Parity Bit 1 its Correct Value  and for the Checker it returns a bool indicating whether the parity bit is right*/

bool parB4(int arr[],int trn)
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
    if(trn==0){
    if((par%2)==0)
    {arr[3]=0;}
        else{arr[3]=1;/*cout<<"Parity Bit 4 is set to 1\n";*/}}
    else if(trn==1)
    {
        return (((par%2==0)&&arr[3]==0)||((par%2==1)&&arr[3]==1));
    }
}

/*Function parB8 takes in the 21 bit formatted array and assigns Parity Bit 1 its Correct Value  and for the Checker it returns a bool indicating whether the parity bit is right*/

bool parB8(int arr[],int trn)
{
    int par=0;
    for(int i=7;i<14;i++)
    {
        if(arr[i]==1){par++;}//cout<<"i="<<i<<",par="<<par<<endl;
    }
    if(arr[14]==1){par++;};
    if(arr[7]==1){par--;}//make sure parity bit value not counted
    //cout<<"par is "<<par<<endl;
    if(trn==0){
    if((par%2)==0)
    {arr[7]=0;}
        else{arr[7]=1;/*cout<<"Parity Bit 8 is set to 1\n";*/}}
    else if(trn==1)
    {
        return (((par%2==0)&&arr[7]==0)||((par%2==1)&&arr[7]==1));
    }
}

/*Function parB16 takes in the 21 bit formatted array and assigns Parity Bit 1 its Correct Value  and for the Checker it returns a bool indicating whether the parity bit is right*/

bool parB16(int arr[],int trn)
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
    if(trn==0){
    if((par%2)==0)
    {arr[15]=0;}
        else{arr[15]=1;/*cout<<"Parity Bit 16 is set to 1\n";*/}}
    else if(trn==1)
    {
        return (((par%2==0)&&arr[15]==0)||((par%2==1)&&arr[15]==1));
    }
    
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
    //cout<<"\n";
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
        //cout<<"i is "<<i<<endl;
    }
    disp[20]=rev[i];
    parB1(disp,0);
    parB2(disp,0);
    parB4(disp,0);
    parB8(disp,0);
    parB16(disp,0);
    /*for(int f=0;f<=20;f++)
    {
        cout<<disp[f];
    }*/
    //cout<<"\nThe Hamming Code is "<<convInt(disp)<<endl;
    //cout<<"\n"<<convInt(disp)<<endl;
    int ans=convInt(disp,21);
    //cout<<"ans is "<<ans;
    return ans;
}

/*This function takes in an hexadecimal integer value and converts it to a Binary stored in an array containing 21 bits*/

int convertToBin(long int val,int arr[])
{
    int * initial;
    initial = new int [21];
    int n;
    int tmp;
    for(n=0;n<21;n++)
    {
        tmp = (val & (1 << n)) >>n;
        initial[n] = tmp;
        //cout<<tmp;
    }
    //cout<<"\n";
    int l;
    int j=0;
    for(l=20;l>=0;l--)
    {
        //cout<<disp[l];
        arr[j]=initial[l];
        j++;
    }
}

bool isPBit(int n)
{
    int arr[] = { 0, 1, 3, 7, 15};
    for (int i=0; i<6; i++) {
        if (arr[i]==n) {
            return true;}
    }
    return false;
}

int convTo16(int arr1[],int arr2[])//
{
    int j=0;
    for(int i=0;i<21;i++){
        if (!(isPBit(i))) {
            arr2[j]=arr1[i];
            //cout<<"i is "<<i<<"j is "<<j<<endl;
            j++;
        }
        
    }
    
}
/*This function takes the user input hex value and prints its hamming code*/
int HamcodeMaker()
{
  cin.setf(ios::hex, ios::basefield);
  cout.setf(ios::hex, ios::basefield);
  //cout<<"This seems to be working"<<endl;
  long int user_input;
    cout<<"Enter a four-digit hexadecimal value: ";cin>>user_input;
    //cout.setf(ios::hex, ios::basefield);
    cout<<"The hamming code is "<<hamming(user_input)<<endl;
}

/*This function runs the Hamming Code Checker Algortithm that Checks the User Provided Hamming Code*/
int HamcodeChecker()
{
    cin.setf(ios::hex, ios::basefield);
    cout.setf(ios::hex, ios::basefield);
    long int user_input;
    cout<<"Enter a hexadecimal value for a hamming code: ";cin>>user_input;
    int * start;
    start = new int[21];
    cout<<"Original Hamming Code in Binary: ";
    convertToBin(user_input,start);
    for (int i=0; i<21;i++) {
        cout<<start[i];
    }
    cout<<"\n";
    int check=0;
    if(!(parB1(start,1))){check=check+1;}//cout<<"pb1"<<endl;
    if(!(parB2(start,1))){check=check+2;}//cout<<"pb2"<<endl;
    if(!(parB4(start,1))){check=check+4;}//cout<<"pb4"<<endl;
    if(!(parB8(start,1))){check=check+8;}//cout<<"pb8"<<endl;
    if(!(parB16(start,1))){check=check+16;}//cout<<"pb16"<<endl;
    cout.setf(ios::dec, ios::basefield);
    if (check!=0) {
        cout<<"\nThe "<<check<<"th bit is wrong"<<endl;
        cout<<"Corrected Hamming Code in Binary: ";
        if(start[check-1]==1){start[check-1]=0;}else{start[check-1]=1;}
        for (int j=0; j<21;j++) {
            cout<<start[j];
        }
        cout.setf(ios::hex, ios::basefield);
        int result;
        result = convInt(start,21);
        cout<<"\nThe corrected Hamming Code is "<<result<<endl;
        int * final;
        final = new int[16];
        convTo16(start,final);
        result = convInt(final,16);
        cout<<"\nThe corresponding corrected 16 Bit Hexadecimal is "<<result;
    }
    else{cout<<"That Hamming Code is Already Correct"<<endl;}
}

/*This function runs the interface of the program one time through*/
int interface()
{
    int response=0;
    cout<<"Please Choose Between the Following Options:"<<endl;
    cout<<"1.Get the Hamming Code of a 16-bit (Hex Value)"<<endl;
    cout<<"2.Enter Hamming Code (Hex Value) to check for and repair a one bit error"<<endl;
    cout<<"3.Quit"<<endl;
    cout<<"\nEnter 1 or 2 or 3:";cin>>response;
    if(response==1){
        HamcodeMaker();return 1;}
    else if(response==2)
    {HamcodeChecker();return 1;}
    else if(response==3)
    {
        return 0;
    }
}

int main()
{
    //convTo16();
    cout<<"Welcome To Armaan's Hamming Project"<<endl;
    int a =1;
    while (a==1) {
        cout<<"\n";
        a=interface();
        cout<<"\n";
    }
    return 0;
}
