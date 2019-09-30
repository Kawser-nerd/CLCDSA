using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace arc_014_B
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string[] a = new string[n]; bool hantei = false;
            int keka = 0;// 0?????1???2??
            for (int i = 0; i < n; i++)
            {
                string s = Console.ReadLine();
                if (!hantei)
                {
                    if (i != 0)
                    {
                        if (0 <= Array.IndexOf(a, s))
                        {
                            hantei = true;
                            if (i % 2 ==1) { keka = 1; } else { keka = 2; }
                        }
                        if (s[0] == a[i - 1][a[i - 1].Length - 1]) { }
                        else
                        {
                            hantei = true;
                            if (i % 2 ==1) { keka = 1; } else { keka = 2; }
                        }
                    }
                }
                a[i] = s;
            }
            if (keka == 1) { Console.WriteLine("WIN"); }
            else if (keka == 0) { Console.WriteLine("DRAW"); }

            else { Console.WriteLine("LOSE"); }
            Console.ReadLine();
        }
    }
}