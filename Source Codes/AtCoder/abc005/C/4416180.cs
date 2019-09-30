using System;
using System.Linq;
using System.Collections.Generic;
using System.Text.RegularExpressions;

namespace Hello_World
{
    class Program
    {
        static void Main(string[] args){
            var T = int.Parse(Console.ReadLine());
            var N = int.Parse(Console.ReadLine());
            var s = Console.ReadLine().Split(' ');
            var A = new List<int>();
            for(int i=0; i<N; i++) A.Add(int.Parse(s[i]));
            var M = int.Parse(Console.ReadLine());            
            s = Console.ReadLine().Split(' ');
            var B = new List<int>();
            for(int i=0; i<M; i++) B.Add(int.Parse(s[i]));
            while(A.Count()>0 && B.Count()>0){
                if(A.Min()<=B.Min() && A.Min()+T>=B.Min())B.Remove(B.Min());
                A.Remove(A.Min());
            }
            Console.WriteLine(B.Count() == 0 ? "yes" : "no");
        }
    }   
}