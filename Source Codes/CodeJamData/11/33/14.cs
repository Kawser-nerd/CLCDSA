using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _1C
{
    class C
    {
        static void Main(string[] args)
        {
            int tests = int.Parse(Console.ReadLine());
            for (int t = 1; t <= tests; t++)
            {
                string[] s = Console.ReadLine().Split(' ');
                int n = int.Parse(s[0]), l = int.Parse(s[1]), h = int.Parse(s[2]);
                s = Console.ReadLine().Split(' ');
                int[] o = new int[n];
                for (int i = 0; i < n; i++)
                {
                    o[i] = int.Parse(s[i]);
                }                
                Array.Sort(o);                
                int odp = 0;
                for(odp =l; odp<=h;odp++)
                {
                    int j;
                    for(j= 0; j < n; j++)
                        if(odp % o[j] != 0 && o[j] % odp != 0)
                        break;
                    if (j == n) break;
                }
                string res;
                if (odp > h)
                    res = "NO";
                else
                    res = odp.ToString();
               

                Console.WriteLine("Case #{0}: {1}", t, res);


            }
        }
    }
}
