using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        int total = int.Parse(ReadLine());
        int roop = total/4;
        int aaa = 0;
        for(int i=0;i<=roop;i++){
            for(int j=0;j<=roop;j++){
                int kei = (i*7) + (j*4);
                if(kei == total){
                    aaa++;
                    break;
                }
            }
        }
        if(aaa>0){
            WriteLine("Yes");
        }else{
            WriteLine("No");
        }
    }
}