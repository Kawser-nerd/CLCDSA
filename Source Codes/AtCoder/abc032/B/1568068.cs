using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace atcoder01
{
    class Program
    {
        static void Main(string[] args)
        {
            int outO = 0;

            string inS = Console.ReadLine();
            int inK = int.Parse(Console.ReadLine());

            if (inS.Length >= inK)
            {
                string[] arr1 = new string[inS.Length - inK + 1];

                for (int i = 0; i < inS.Length - inK + 1; i++)
                {
                    arr1[i] = inS.Substring(i, inK);
                }
                outO = arr1.Distinct().Count();
            }
            Console.WriteLine(outO);
        }
    }
}