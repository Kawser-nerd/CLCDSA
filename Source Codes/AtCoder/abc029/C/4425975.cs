using System;
using System.Linq;
public class Hello{
    static int N;
    public static void Main(){
        N = int.Parse(Console.ReadLine());
        Dive("",0);
    }
    static void Dive(string s,int i){
        if(i == N){
            Console.WriteLine(s);
        }else{
            foreach(var c in new char[]{'a','b','c'}){
                Dive(s + c.ToString(),i + 1);
            }
        }
            
    }
}