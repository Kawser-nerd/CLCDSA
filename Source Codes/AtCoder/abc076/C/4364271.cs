using System;
using System.Linq;
using System.Collections.Generic;

namespace Hello_World
{
    class Program
    {
        static void Main(string[] args){
            var S = Console.ReadLine();
            var T = Console.ReadLine();
            var res = "UNRESTORABLE";
            for(int i=S.Length-T.Length; i>=0; i--){
                var s = S.Substring(i, T.Length);
                var judge = true;
                for(int j=0; j<T.Length; j++){
                    if(s[j] != T[j] && s[j] != '?'){judge=false; break;}
                }
                if(judge){
                    var t = S.Remove(i,T.Length);
                    res = t.Replace("?", "a").Insert(i, T);
                    break;
                }
            }
            Console.WriteLine(res);
        }
    }   
}