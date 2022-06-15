#include<iostream>
#include<fstream>
#include<cmath>
#include<map>
using namespace std;
int main(){
     ifstream fin;    
    ofstream fout;   
    string line;
    string word = "";
    double x1 = 0.0;
    double y1 = 0.0;
    double x2, y2;
    char ch;
    double distance;
    map<double, string> m;
    string inputfile;
    string outputfile;
    cout<<endl<<"Enter complete path to read record from file : ";
    getline(cin, inputfile);
    cout<<endl<<"Enter complete path to write the record from file : ";
    getline(cin, outputfile);
    outputfile +="\\output.txt";
    fin.open("points.txt");
    fout.open("output.txt");
    if(fin.is_open()){
        while(getline(fin, line)){
            word.clear();
            for(int i=0;i<=line.length();i++){
                if(line[i]==' '){
                    x2 = stod(word);
                    word.clear();
                }else if(i==line.length()){
                    y2 = stod(word);
                    word.clear();
                }
                else{
                    word += line[i];
                }
            }
            
            distance = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
            m[distance] = line;
        }

        fin.close();
    }else{
        cout<<endl<<"File cann't be read due to some technical problems..";
    }

    // write the output in output.txt file
    if(fout.is_open()){
        map<double, string>::iterator itr = m.begin();
        while(itr!=m.end()){
            fout<<itr->first<<"<==>"<<itr->second<<'\n';
            itr++;
        }
        fout.close();
        cout<<endl<<"Record stored in text file successfully...";
    }else{
        cout<<endl<<"file cann't be open for writting record due to some problem..";
    }
    return 0;
}