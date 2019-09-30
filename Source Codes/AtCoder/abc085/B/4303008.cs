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
            HashSet<string> moti = new HashSet<string>();
            for(int i=0; i<N; i++){
                moti.Add(Console.ReadLine());
            }
            Console.WriteLine(moti.Count());
        }
    }
}