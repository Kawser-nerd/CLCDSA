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
            int j;
            bool flag=false;
            bool nflag=false;
            var x=new string[2];
            for (int i = 0; i < 2; i++)
            {
                x[i] = Console.ReadLine();
            }
            var y=new List<char>();
            var z=new List<char>();
            for (int i = 0; i < x[1].Length; i++)
            {
                z.Add(x[1][i]);
            }
            for (int i = 0; i < x[0].Length; i++)
            {
                y.Add(x[0][i]);
            }
            y.Sort();
            z.Sort();
            z.Reverse();
            for (j = 0; j < y.Count&& j < z.Count; j++)
            {
                 if (y[j] == z[j]) continue;
                 else if (y[j] < z[j])
                 {
                     flag = true;
                     break;
                 }
                    else { nflag = true; }
            }
            if (flag)
            {
                Console.WriteLine("Yes");
            }
            else if (nflag)
            {
                Console.WriteLine("No");
            }
            else
            {
                if (y.Count<z.Count) {
                    Console.WriteLine("Yes"); flag = true;
                }
                else  Console.WriteLine("No");
            }
        }
    }
}