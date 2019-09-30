using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Math;


namespace _20180502_pra
{
    class Program
    {
        static void Main(string[] args)
        {
            var w = Console.ReadLine();
            var result = "Yes";
            

            for (int i = 0; i < w.Length; i++)
            {
                int count = 0;
                foreach (var item in w)
                {
                    if (item == w[i]) count++;
                }
                if (count % 2 != 0)
                {
                    result = "No";
                    break;
                }
            }
            Console.WriteLine(result);

        }
    }
}