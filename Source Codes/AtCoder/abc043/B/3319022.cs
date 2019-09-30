using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string str = ReadLine();
        int x = 0;
        do{
            x = str.IndexOf("B");
            if(x>0){
                str = str.Remove(x-1,2);
            }else if(x == 0){
                str = str.Remove(0,1);
            }
        }while(x>=0);
        WriteLine(str);
    }
}