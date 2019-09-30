using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string[] tosimiti = ReadLine().Split(' ');
        int tosi = 1+int.Parse(tosimiti[0]);
        int miti = int.Parse(tosimiti[1]);
        int[] honsu = new int[tosi];
        for(int i=0;i<miti;i++){
            string[] temp = ReadLine().Split(' ');
            int a = int.Parse(temp[0]);
            int b =int.Parse(temp[1]);
            honsu[a]++;
            honsu[b]++;
        }
        for(int i=1;i<tosi;i++){
            WriteLine(honsu[i]);
        }
    }
}