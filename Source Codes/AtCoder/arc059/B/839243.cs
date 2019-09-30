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
        int b = -1, e = -1;
        for(int i = 1; i < s.Length; i++){
            if(s[i - 1] == s[i]){
                b = i;
                e = i + 1;
                break;
            }
            if(i + 1 < s.Length && s[i - 1] == s[i + 1]){
                b = i;
                e = i + 2;
                break;
            }
        }
        Console.WriteLine("{0} {1}", b, e);
    }
}