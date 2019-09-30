using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<int> list = new List<int>();
        for (int i = 0; i < n; i++)
            list.Add(int.Parse(Console.ReadLine()));
        list.Sort();
        if (n == 1)
        {
            Console.WriteLine(1);
        }
        else
        {
            int ans = 0;
            int tmp = list[0];
            bool even = false;
            for (int i = 1; i < n; i++)
            {
                if (i == n - 1)
                {
                    if (tmp == list[i])
                    {
                        if (even) ans++;
                    }
                    else if (even) ans++;
                    else ans += 2;
                }
                else
                {
                    if (tmp == list[i])
                    {
                        even = !even;
                    }
                    else
                    {
                        if (even) even = false;
                        else ans++;
                        tmp = list[i];
                    }

                }
            }
            Console.WriteLine(ans);
        }
    }
}