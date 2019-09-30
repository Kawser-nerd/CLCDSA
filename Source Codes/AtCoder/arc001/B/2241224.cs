using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication7
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            String s = Console.ReadLine();
            int[] ans = new int[4];
            for(int i = 0; i < n; i++)
            {
                ans[int.Parse(s.ElementAt(i).ToString())-1]++;
            }
            Console.WriteLine("{0} {1}", ans.Max(), ans.Min());
        }
    }
}