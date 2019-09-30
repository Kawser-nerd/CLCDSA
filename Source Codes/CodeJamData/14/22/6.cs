using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace small
{
    class Program
    {
        static void Main(string[] args)
        {
            int tc = Convert.ToInt32(Console.ReadLine());
            for (int cc = 1; cc <= tc; ++cc)
            {
                String[] s = Console.ReadLine().Split();
                int a = Convert.ToInt32(s[0]);
                int b = Convert.ToInt32(s[1]);
                int k = Convert.ToInt32(s[2]);
                int r = 0;
                for (int i = 0; i < a; ++i)
                {
                    for (int j = 0; j < b; ++j)
                    {
                        if ((i & j) < k)
                        {
                            ++r;
                        }
                    }
                }
                Console.WriteLine("Case #{0}: {1}", cc, r);
            }
        }
    }
}
