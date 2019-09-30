using System;
using System.Linq;
using System.Collections.Generic;

namespace Hello_World
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            List<int> a = new List<int>(), A = new List<int>(), B = new List<int>();
            string[] s = Console.ReadLine().Split(' ');
            for(int i=0; i<N; i++){
                a.Add(int.Parse(s[i]));
            }
            try{
                while(true){
                    A.Add(a.Max());
                    a.Remove(a.Max());
                    B.Add(a.Max());
                    a.Remove(a.Max());    
                }
            }
            catch(InvalidOperationException){
                Console.WriteLine(A.Sum()-B.Sum());
            }
        }
    }
}