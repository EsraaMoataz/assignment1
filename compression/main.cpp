#include <iostream>
#include<fstream>
#include<string>



using namespace std;
fstream binaryfile;
fstream compressedfile;

void fitTo4(int c)
{
    int rep;
    string temp,reverse_temp;
    int cnt=0;
    if(c<=15)
    {
        while(c!=0)
        {
            if(c%2==0)
                { temp+='0';
                  cnt++;
                }
            else
            {
                temp+='1';
                cnt++;
            }
            c=c/2;
        }
        int y=4-cnt;
        while(y--)
        {
            compressedfile<<"0";

        }
        for(int i=temp.size()-1;i>=0;i--)
        {
            reverse_temp+=temp[i];
        }
        compressedfile<<reverse_temp;
       /* for(int i=0;i<cnt;i++)
        {
            //compressedfile<<charToInt(temp[i]);
            cout<<charToInt(temp[i]);
        }*/
    }
    else
    {
        rep=c/15;
        while(rep!=0)
        {
            compressedfile<<"1111";
        }
        fitTo4(c%15);

    }
}


int main()
{
    int counter=0;


    int count0=0;
    int count1=0;
    double afterCompression=0;
    double beforeCompression=0;
    double compressionRatio;

    string binary_line;
    binaryfile.open("binary_file.txt");
   compressedfile.open("compressed_file.txt");
  // fitTo4(2);

    while(!binaryfile.eof())
    {

        getline(binaryfile,binary_line);




    for(int i=0;i<binary_line.size();i++)
    {

        if(binary_line[i]=='0'){

                counter++;}
        else{


        fitTo4(counter);
            counter=0;
        }

    }

    }
        binaryfile.close();
        compressedfile.close();

    binaryfile.open("binary_file.txt");
    while(!binaryfile.eof())
    {


    getline(binaryfile,binary_line);
    for(int i=0;i<binary_line.size();i++)
        {
           beforeCompression++;
        }

    }
    cout<<beforeCompression<<endl;
    compressedfile.open("compressed_file.txt");
    while(!compressedfile.eof())
    {
        getline(compressedfile,binary_line);
        for(int i=0;i<binary_line.size();i++)
        {
           afterCompression++;
        }
    }
    cout<<afterCompression<<endl;
    compressionRatio=afterCompression/beforeCompression;
    cout<<compressionRatio;
//    cout<<"count0 is "<<count0<<endl;
//        cout<<"count1 is "<<count1<<endl;


    /*if(count0>count1){cout<<0;}
    else if(count1>count0){cout<<1;}
    else {cout<<"=";}*/
    ///////////////////////////////////////////////////////////////

   /* if(flag==0 && s[0]==1)
    {
        //compressedfile<<0000;
        cout<<"0000"<<endl;

    for(int i=1;i<s.size();i++)
    {
      if(s[i]==0){counter++;}

    else{fitTo4(counter);
    counter=0;}
    }
    }
    else
    {
        for(int i=0;i<s.size();i++)
        {
           if(s[i]==0){counter++;}
           else{
                fitTo4(counter);
                counter=0;
               }
        }
    }*/


    binaryfile.close();
    compressedfile.close();


    return 0;
}
