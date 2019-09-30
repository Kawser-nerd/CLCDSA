using System;

class Program{
    static void Main(){
        string s = Console.ReadLine();
        int i;
        int bc=0;
        long ret=0;
        for (i = 0; i < s.Length; i++){
            if (s[i] == 'W'){
                ret += bc;
            }else{
            bc++;
            }
        }
        Console.WriteLine(ret);
    }
}