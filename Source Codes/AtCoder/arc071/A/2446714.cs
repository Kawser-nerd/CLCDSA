using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC71_C
{
    class Program
    {
        static void Main(string[] args)
        {

            var n = int.Parse(Console.ReadLine());
            var s = new char[n][];
            for (int i = 0; i < n; i++)
            {

                s[i] = Console.ReadLine().ToCharArray();
            }

            for (int i = 0; i < n; i++)
            {
                Array.Sort(s[i]);
            }
            bool f = true;
            var ans = new List<char>();
            var c = new char[n];
            var sc = new int[n];
            for (int i = 0; i < n; i++)
            {
                c[i] = s[i][0];
                sc[i] = 0;
            }
            while(true){

                if (c.All(x => x == c[0]))
                {
                    ans.Add(c[0]);
                    for (int i = 0; i < n; i++) sc[i]++;
                }
                else
                {
                    var cmin = c.Min();
                    for (int i = 0; i < n; i++)
                    {
                        if (c[i] == cmin)
                        {
                            sc[i]++;
                        }
                    }

                }
                for (int i = 0; i < n; i++)
                {
                    if (sc[i] >= s[i].Length)
                    {
                        goto last;
                    }
                    c[i] = s[i][sc[i]];
                }
            }
            last:
            Console.WriteLine(new String(ans.ToArray()));
        }
    }
}