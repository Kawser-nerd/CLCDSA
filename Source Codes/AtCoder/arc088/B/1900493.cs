using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine();
            var len = s.Select(x=>0).ToArray();

            if(s.Length%2==0)
            {
                if (s[s.Length / 2 - 1] == s[s.Length / 2])
                {
                    var current = s.Length / 2 - 1;
                    int ans1 = 0;
                    for (int i = 1; ; i++)
                    {
                        if (current - i < 0 || s[current - i + 1] != s[current - i])
                        {
                            ans1 = s.Length / 2 + i;
                            break;
                        }
                    }
                    current = s.Length / 2;
                    int ans2 = 0;
                    for (int i = 1; ; i++)
                    {
                        if (current + i >= s.Length || s[current + i - 1] != s[current + i])
                        {
                            ans2 = s.Length / 2 + i;
                            break;
                        }
                    }
                    Console.WriteLine(Math.Min(ans1, ans2));
                }
                else
                {
                    Console.WriteLine(s.Length / 2);
                }
            }
            else
            {
                var current = s.Length / 2 ;
                int ans1 = 0;
                for (int i = 1; ; i++)
                {
                    if (current - i < 0 || s[current - i + 1] != s[current - i])
                    {
                        ans1 = s.Length / 2 + i ;
                        break;
                    }
                }
                current = s.Length / 2 ;
                int ans2 = 0;
                for (int i = 1; ; i++)
                {
                    if (current + i >= s.Length || s[current + i - 1] != s[current + i])
                    {
                        ans2 = s.Length / 2 + i;
                        break;
                    }
                }
                Console.WriteLine(Math.Min(ans1, ans2));
            }
            return;

        }
    }
}