using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C044
{
    class C105
    {
        static void Main(string[] args)
        {
            long N =int.Parse( Console.ReadLine());
            long x = N;
            char[] c = null;
            while (x != 0)
            {

                int i = 0;
                long s = 0, t = 0;
                while (true)
                {
                    long k = (long)Math.Pow(-2, i);
                    if (k < 0) s += k;
                    else t += k;
                    i++;

                    if(s <= x && x <= t)
                    {
                        x -= k;
                        if (c == null)
                        {
                            c = Enumerable.Repeat('0', i).ToArray();
                        }
                        c[c.Length-i] = '1';
                        break;
                    }
                }
            }
            if (c == null) c = new char[] { '0' };
            string str = new string(c);
            Console.WriteLine(str);
        }

    }
}