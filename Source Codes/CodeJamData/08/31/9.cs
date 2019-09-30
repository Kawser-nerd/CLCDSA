using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Text_Messaging_Outrage
{
    class Program
    {
        static void process()
        {
            string[] s;

            int p, k, l;
            s = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            p = Int32.Parse(s[0]);
            k = Int32.Parse(s[1]);
            l = Int32.Parse(s[2]);
            if (p * k < l)
            {
                Console.WriteLine("Impossible");
                return;
            }
            List<int> c = new List<int>();
            foreach (string i in Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries))
                c.Add(Int32.Parse(i));
            c.Sort(); c.Reverse();
            int idx = 0;
            long ret = 0;
            for (int i = 0; i < p; i++)
            {
                for (int j = 0; j < k; j++)
                {
                    ret += (long)c[idx++] * (i + 1);
                    if (idx == l) break;
                }
                if (idx == l) break;
            }

            Console.WriteLine(ret);
        }
        static void Main(string[] args)
        {
            int t = Int32.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                Console.Write("Case #{0}: ", i + 1);
                process();
            }
        }
    }
}
