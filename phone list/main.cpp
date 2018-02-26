#include <iostream>
#include<fstream>
#include<string>
#include<bitset>


using namespace std;
fstream binaryfile;

void toBinary (string s)
{
    int n;
    string binary;


   for(int i=0;i<s.size();i++)
   {
       if((s[i]-'0'<=9) && (s[i]-'0'>=0))
       {
           n=(s[i]-'0')+48;


       }
       else if((s[i]-'A'<=25) && (s[i]-'A'>=0))
       {
           n=(s[i]-'A')+65;
       }
       else if((s[i]-'a'<=25) && (s[i]-'a'>=0))
       {
            n=(s[i]-'a')+97;
       }
       else if (s[i]=='|')
       {
           n=124;
       }
       else if (s[i]==' ')
       {
           n=32;
       }

         binary = bitset<8>(n).to_string();
         //cout<<binary;
        binaryfile<<binary;

   }


}
/*int charToInt(char ch)
{
    return ch-'0';
}*/



int main()
{
    string line;
    string binary_line;

    int count0,count1;
    fstream myfile;
    myfile.open("id book .txt");
   binaryfile.open("binary_file.txt");


    while(!myfile.eof())
    {
     getline(myfile,line);
     toBinary(line);

     //cout<<line;


    }
     /*while(!binaryfile.eof())
     {


   getline(binaryfile,binary_line);
    //if (binary_line[0]==1)
      //  compression(binary_line,1);
      //int counter=0;

    //counter++;
        for(int i=0;i<binary_line.size();i++)
        {
            if(binary_line[i]=='0'){count0++; }
            else {count1++;}
        }
     }


    if(count0>count1){cout<<0;}
    else if(count1>count0){cout<<1;}
    else {cout<<"=";}*/



    myfile.close();
    binaryfile.close();








    return 0;

}

