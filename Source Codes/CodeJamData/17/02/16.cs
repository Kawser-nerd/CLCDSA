using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace code_jam_2k17_q
{
    public class B
    {
        static int[] read_ints(int num)
        {
            return Console.ReadLine()
                .Split(' ')
                .Take(num)
                .Select(s => Convert.ToInt32(s))
                .ToArray();
        }

        public static void b()
        {
            int T, t, len, i, j;
            char[] num;

            T = read_ints(1)[0];

            for (t = 1; t < T + 1; ++t)
            {
                num = Console.ReadLine().Trim().ToArray();
                len = num.Length;

                while (true)
                {
                    /* Find index of first divide */
                    for (i = 1; i < len; ++i)
                    {
                        if (num[i] < num[i - 1])
                            break;
                    }

                    /* Decrement before; replace all after with 9s */
                    for (j = i; j < len; ++j)
                    {
                        num[j] = '9';
                    }

                    if (i != len)
                        --num[i - 1];
                    if (i == 1 || num[i - 2] <= num[i - 1])
                        break;

                    len = i + 1;
                }

                num = num.SkipWhile(c => c == '0').ToArray();

                Console.WriteLine("Case #" + t + ": " + new string(num));
            }
        }
    }
}
