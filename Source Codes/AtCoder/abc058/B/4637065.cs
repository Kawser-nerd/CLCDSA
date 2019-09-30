using System;
class Program{
    static void Main(string[] args){
        string oneLine = Console.ReadLine();
        string twoLine = Console.ReadLine();
        char[] oneChar = new char[oneLine.Length];
        char[] twoChar = new char[twoLine.Length];
        for(int i=0;i<oneLine.Length;i++){
            oneChar[i] = oneLine[i];
        }
        for(int i=0;i<twoLine.Length;i++){
            twoChar[i] = twoLine[i];
        }
        string str = "";
        for(int i=0;i<oneChar.Length;i++){
            str += oneChar[i].ToString();
            if(i >= twoChar.Length){continue;}
            str += twoChar[i].ToString();
        }
        Console.WriteLine(str);
    }
}