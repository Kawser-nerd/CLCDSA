using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;

class Program{
    static void Main(){
        string s = Console.ReadLine();
        int b = 0;
        int e = b + 1;
        bool found = false;
        while(!found && b < s.Length){
            for(int i = 1; i <= 2; i++){
                e = b + i;  
                if(e < s.Length && Unbalance(s.Substring(b, i + 1))){
                    found = true;
                    b++;
                    e++;
                    break;
                }
            }
            if(found) break;
            else b++;
        }
        if(!found){
            b = -1;
            e = -1;
        }
        Console.WriteLine("{0} {1}", b, e);
    }

    static bool Unbalance(string str){
        int[] cnt = new int[30];
        for(int i = 0; i < str.Length; i++){
            cnt[str[i] - 'a']++;
        }
        if(cnt.Max() > str.Length / 2) return true;
        else return false;
    }
}