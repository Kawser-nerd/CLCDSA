using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace code_jam_2k17_q
{
    public class A
    {
        static int[] read_ints(int num)
        {
            return Console.ReadLine()
                .Split(' ')
                .Take(num)
                .Select(s => Convert.ToInt32(s))
                .ToArray();
        }

        static int non_recursive_num_flips(string s, int K)
        {
            int flips, i, j, len, flipped_here;
            int[] flipped;
            bool flip_needed, was_up;

            flips = 0;
            len = s.Length;
            flipped = new int[len];
            flipped_here = 0;

            for (i = 0; i < len - K + 1; ++i)
            {
                /* Determine if current pancake needs flipped */
                if (i >= K)
                    flipped_here -= flipped[i - K];
                was_up = s[i] == '+';
                flip_needed = !(was_up ^ ((flipped_here & 1) > 0));

                /* Handle flip or no flip */
                flipped[i] = flip_needed ? 1 : 0;
                if (flip_needed)
                {
                    //Console.WriteLine("Flip needed at index " + i);
                    ++flipped_here;
                    ++flips;
                    flipped[i] = 1;
                }
            }

            for (i = len - K + 1; i < len; ++i)
            {
                if (i >= K)
                    flipped_here -= flipped[i - K];
                was_up = s[i] == '+';
                if (!(was_up ^ ((flipped_here & 1) > 0)))
                    return -1;
            }

            return flips;
        }

        static int num_flips(string s, int K, int start)
        {
            int num_cakes, result, best_result, i, j;
            string cpy;

            num_cakes = s.Length;
            if (s.All(c => c == '+'))
            {
                return 0;
            }

            best_result = int.MaxValue;
            for (i = start; i < num_cakes - K + 1; ++i)
            {
                cpy = new string(s.Take(i).ToArray()) /* Untouched before flip */
                    + new string(s.Skip(i).Take(K).Select(c => ((c == '+') ? '-' : '+')).ToArray()) /* Flip */
                    + new string(s.Skip(i + K).ToArray());

                /*
                for (j = 0; j < start; ++j)
                {
                    Console.Write(" ");
                }
                Console.WriteLine(cpy);
                */

                result = num_flips(cpy, K, i + 1) + 1;
                if (result > 0 && result < best_result)
                    best_result = result;
            }

            return best_result == int.MaxValue ? -1 : best_result;
        }

        public static void a()
        {
            int t, result;
            string[] line;
            string s;
            int T, K;
            
            T = read_ints(1)[0];
            for (t = 0; t < T; ++t)
            {
                line = Console.ReadLine().Split(' ');
                s = line[0];
                K = Convert.ToInt32(line[1]);
                result = non_recursive_num_flips(s, K);
                Console.WriteLine("Case #" + (t + 1) + ": " + ((result > -1) ? Convert.ToString(result) : "IMPOSSIBLE"));
            }
        }
    }
}
