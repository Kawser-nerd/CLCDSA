using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace A
{
    class Program
    {

        static bool isHappy(int num, int num_base)
        {
            HashSet<int> ch = new HashSet<int>();
            ch.Add(num);
            while (num > 1)
            {
                int tmp = 0;
                while (num > 0)
                {
                    tmp += (num % num_base) * (num % num_base);
                    num /= num_base;
                }
                num = tmp;
                if (ch.Contains(num)) return false;
                else ch.Add(num);
            }
            return true;
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                string[] s = Console.ReadLine().Split(' ');
                int[] tab = new int[s.Length];
                for (int j = 0; j < s.Length; j++) tab[j] = int.Parse(s[j]);

                int num = 2;
                do
                {
                    bool ok=true;
                    for(int j=0; j<tab.Length; j++)
                        if (!isHappy(num, tab[j]))
                        {
                            ok = false;
                            break;
                        }
                    if (ok)
                    {
                        Console.WriteLine("Case #"+i+": "+num);
                        break;
                    }
                    num++;
                } while (true);
            }
        }
    }
}
