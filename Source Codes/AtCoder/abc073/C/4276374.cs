using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        HashSet<string> t = new HashSet<string>();
        for(int i=0; i<N; i++){
            string s = Console.ReadLine();
            if(t.Contains(s)){
                t.Remove(s);
            }else{
                t.Add(s);
            }
        }
        Console.WriteLine("{0}",t.Count);
    }
}