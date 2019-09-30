using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

public class Program
{
    static void Main()
    {
        int n = Int32.Parse(Console.ReadLine());

        for (int c = 0; c < n; ++c)
        {
            int T = Int32.Parse(Console.ReadLine());
            string[] nanb = Console.ReadLine().Split(' ');
            int NA = Int32.Parse(nanb[0]);
            int NB = Int32.Parse(nanb[1]);

            int[] sa = new int[60 * 24 + T];
            int[] sb = new int[60 * 24 + T];
            for (int i = 0; i < NA; ++i)
            {
                string[] t1 = Console.ReadLine().Split(' ');
                string[] t2 = t1[0].Split(':');
                string[] t3 = t1[1].Split(':');
                int depart = Int32.Parse(t2[0]) * 60 + Int32.Parse(t2[1]);
                int arrive = Int32.Parse(t3[0]) * 60 + Int32.Parse(t3[1]) + T;
                for (int j = depart; j < sa.Length; ++j)
                    --sa[j];
                for (int j = arrive; j < sb.Length; ++j)
                    ++sb[j];
            }

            for (int i = 0; i < NB; ++i)
            {
                string[] t1 = Console.ReadLine().Split(' ');
                string[] t2 = t1[0].Split(':');
                string[] t3 = t1[1].Split(':');
                int depart = Int32.Parse(t2[0]) * 60 + Int32.Parse(t2[1]);
                int arrive = Int32.Parse(t3[0]) * 60 + Int32.Parse(t3[1]) + T;
                for (int j = depart; j < sb.Length; ++j)
                    --sb[j];
                for (int j = arrive; j < sa.Length; ++j)
                    ++sa[j];
            }

            int minA = 0;
            int minB = 0;
            foreach (int x in sa)
                minA = Math.Min(x, minA);
            foreach (int x in sb)
                minB = Math.Min(x, minB);

            Console.WriteLine("Case #{0}: {1} {2}", c+1, -minA, -minB);
        }
    }
}
