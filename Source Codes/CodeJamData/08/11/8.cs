using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            int T=int.Parse(Console.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                int n = int.Parse(Console.ReadLine());
                long wyn = 0;
                ArrayList a = new ArrayList();
                ArrayList b = new ArrayList();
                String s = Console.ReadLine();
                String[] tab=s.Split(' ');
                for(int j=0; j<n; j++)a.Add(int.Parse(tab[j]));
                s = Console.ReadLine();
                tab = s.Split(' ');
                for (int j = 0; j < n; j++) b.Add(int.Parse(tab[j]));
                a.Sort();
                b.Sort();
                for (int j = 0; j < n; j++) wyn += (int)a[j] * (int)b[n - j - 1];
                Console.WriteLine("Case #" + i.ToString() + ": " + wyn.ToString());
            }
        }
    }
}
