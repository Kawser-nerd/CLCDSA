using System;
class Program{
    static void Main(string[] args){
        string oneStr = Console.ReadLine();
        string twoStr = Console.ReadLine();
        char[] oneLine = new char[3];
        char[] twoLine = new char[3];
        for(int i=0;i<oneLine.Length;i++){
            oneLine[i] = oneStr[i];
        }
        for(int i=0;i<twoLine.Length;i++){
            twoLine[i] = twoStr[i];
        }
        Console.WriteLine(oneLine[0] == twoLine[2] && oneLine[1] == twoLine[1] && oneLine[2] == twoLine[0] ? "YES" : "NO");
    }
}