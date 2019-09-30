using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace arc_058_A
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int i = 0;
            for (i = n[0]; ; i++)
            {
                string a = i.ToString();
                string sd = a;
                for (int k = 0; k < n[1]; k++)
                {
                    string x = s[k].ToString();
                    sd = sd.Replace(x,"?");
                }
                if (a == sd)
                {
                    break;
                }
            }
            Console.WriteLine(i);Console.ReadLine();
        }
    }
}