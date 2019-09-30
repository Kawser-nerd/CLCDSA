using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            var imp = Console.ReadLine().Split(' ');
            int N = int.Parse(imp[0]);
            int L = int.Parse(imp[1]);
            string[] strs = new string[N];
            for (int i = 0; i < N; ++i)
            {
                strs[i] = Console.ReadLine();
            }
            Array.Sort(strs);
            //Console.Write(strs[0]);
            
            for (int j = 0; j < N; ++j)
            {
                Console.Write(strs[j]);
            }

    
            System.Threading.Thread.Sleep(1000);
        }
    }
}