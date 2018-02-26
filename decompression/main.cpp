#include <iostream>
#include<fstream>
#include<string>

using namespace std;
fstream compressedfile;
fstream decompressedfile;

int main()
{
    string compress_line;
    string fourbitcompress;
    string reversed4bit;
    compressedfile.open("compressed_file.txt");
    decompressedfile.open("decompressed_file.txt");
    int counter=0;
    while(!compressedfile.eof())
    {
        getline(compressedfile,compress_line);
        for(int i=0;i<compress_line.size();i++)
        {
            if(counter==4)
            {
               /* for(int k=fourbitcompress.size()-1;k>=0;k--)
               {
                  reversed4bit+=fourbitcompress[k];
               }*/
               cout<<fourbitcompress<<"   ";
               counter=0;
               fourbitcompress=" ";
            }
            else
            {fourbitcompress+=compress_line[i];
            counter++;}
        }

       /* for(int i=0;i<compress_line.size();i+=4)



            for(int j=i+3;j>=i;j--)
               {
                   fourbitcompress+=compress_line[j];

               }

            for(int k=fourbitcompress.size()-1;k>=0;k--)
               {
                  reversed4bit+=fourbitcompress[k];
               }
               cout<<reversed4bit<<"  ";*/
           //binaryToDecimal(reversed4bit);

    }
    compressedfile.close();
    return 0;
}
