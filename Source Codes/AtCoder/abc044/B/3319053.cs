using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string str = ReadLine();
        int leng = str.Length;
        if(leng%2 == 0){
            int check = 0;
            while(leng>0){
                string a = str[0].ToString();
//                WriteLine(a);
                str = str.Replace(a,"");
                leng = str.Length;
                if(leng %2 == 1){
                    check++;
                }
            }
            if(check == 0){
                WriteLine("Yes");
            }else{
                WriteLine("No");
            }
        }else{
            WriteLine("No");
        }
    }
}