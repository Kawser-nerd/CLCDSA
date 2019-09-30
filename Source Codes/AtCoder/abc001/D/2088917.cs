using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC
{
    class Program
    {
        static void Main(string[] args)
        {
            int inp1;
            int inp2;
            Dictionary<int, int> lst = new Dictionary<int, int>();

            int n;

            n = int.Parse(Console.ReadLine());

            for (int i = 0; i < n; ++i)
            {
                string[] s = Console.ReadLine().Split('-');
                inp1 = int.Parse(s[0]);
                inp2 = int.Parse(s[1]);

                inp1 = (inp1 / 10) * 10 + ((inp1 % 10) / 5) * 5;

                int min = inp2 % 100;
                int rem = min % 10;

                min = min / 10 * 10;
                if (rem > 5)
                {
                    min += 10;
                }
                else if ( rem <= 5 && rem != 0)
                {
                    min += 5;
                }

                inp2 = inp2 / 100 * 100;
                if (min != 60)
                {
                    inp2 += min;
                }
                else
                {
                    inp2 += 100;
                }

                if (lst.ContainsKey(inp1))
                {
                    int v = lst[inp1];
                    if ( inp2 > v )
                    {
                        lst[inp1] = inp2;
                    }
                }
                else
                {
                    lst.Add(inp1, inp2);
                }
            }

            var sorted = lst.OrderBy((x) => x.Key);
            
            int e = -1;
            foreach(var v in sorted)
            {
                if (e < v.Key)
                {
                    if (e != -1)
                    {
                        Console.WriteLine(String.Format("{0:D4}", e));
                    }
                    Console.Write(String.Format("{0:D4}-", v.Key));
                    e = v.Value;
                }
                else if (e < v.Value)
                {
                    e = v.Value;
                }
            }
            
            Console.WriteLine(String.Format("{0:D4}", e));

            return;
        }
    }
}