using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int Sn = 0;
            string imp = Console.ReadLine();
            int L = imp.Length;
            int[] ary = new int[L];
            int N = int.Parse(imp);
            for(int i = 0; i < L; i++)
            {
                ary[i] = int.Parse(imp[i].ToString());
            }
            Sn = ary.Sum();
            if (N % Sn == 0)
            {
                Console.Write("Yes");
            }
            else
            {
                Console.Write("No");
            }
        }
    }
}