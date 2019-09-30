using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace arc068_B
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            Array.Sort(a);
            // for (int i = 0; i < n; i++) { Console.Write(a[i] + " "); }
            int ans = 0;
            int bef=0;
            HashSet < int >hash=new HashSet<int>{ };
            
            for (int i = 0; i < a.Length; i++)
            {
                hash.Add(a[i]);
            }
            Console.WriteLine( hash.Count() % 2 == 1 ? hash.Count() :hash.Count() - 1);
            Console.ReadLine();
        }
    }
}