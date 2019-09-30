using System;

namespace abc001_4
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] a = new int[2000];
            for (int i = 0; i < n; i++)
            {
                string[] s = Console.ReadLine().Split('-');
                int[] x = new int[2];
                x[0] = int.Parse(s[0].Substring(0,2)) * 60 + int.Parse(s[0].Substring(2,2));
                x[0] = x[0] / 5 * 5;
                x[1] = int.Parse(s[1].Substring(0,2)) * 60 + int.Parse(s[1].Substring(2,2));
                x[1] = (x[1] + 4) / 5 * 5;
                a[x[0]]++; a[x[1]]--;
            }
            int sum = 0;
            for (int i = 0; i < 2000; i++)
            {
                sum += a[i];
                if (sum > 0)
                {
                    if (i / 60 < 10) Console.Write(0);
                    Console.Write((i / 60).ToString());
                    if (i % 60 < 10) Console.Write(0);
                    Console.Write((i % 60).ToString() + "-");
                    while (sum > 0)
                    {
                        i++;
                        sum += a[i];
                    }
                    if (i / 60 < 10) Console.Write(0);
                    Console.Write((i / 60).ToString());
                    if (i % 60 < 10) Console.Write(0);
                    Console.WriteLine((i % 60).ToString());
                }
            }
        }
    }
}