using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    class Program
    {
        static bool isPush(int[] dp,int value)
        {
            if (value >= 41) return false;
            if (dp[value] != int.MaxValue) return false;
            return true;
        }

        static void Main(string[] args)
        {
            string[] param = Console.ReadLine().Split(' ');
            int A = int.Parse(param[0]);
            int B = int.Parse(param[1]);

            int diff = Math.Abs(A - B);
            int[] dp = Enumerable.Repeat(int.MaxValue,41).ToArray();
            dp[0] = 0;
            Queue<int> queue = new Queue<int>();
            queue.Enqueue(0);
            while (true)
            {
                var current = queue.Dequeue();
                if (current == diff) break;
                int next = Math.Abs(current - 1);
                //?????
                if (isPush(dp, next))
                {
                    dp[next] = dp[current] + 1;
                    queue.Enqueue(next);
                }
                next = Math.Abs(current + 1);
                //?????
                if (isPush(dp, next))
                {
                    dp[next] = dp[current] + 1;
                    queue.Enqueue(next);
                }
                next = Math.Abs(current - 5);
                //5????
                if (isPush(dp, next))
                {
                    dp[next] = dp[current] + 1;
                    queue.Enqueue(next);
                }
                next = Math.Abs(current + 5);
                //5????
                if (isPush(dp, next))
                {
                    dp[next] = dp[current] + 1;
                    queue.Enqueue(next);
                }
                next = Math.Abs(current - 10);
                //10????
                if (isPush(dp, next))
                {
                    dp[next] = dp[current] + 1;
                    queue.Enqueue(next);
                }
                next = Math.Abs(current + 10);
                //10????
                if (isPush(dp, next))
                {
                    dp[next] = dp[current] + 1;
                    queue.Enqueue(next);
                }
            }
            
            Console.WriteLine(dp[diff]);
        }
    }
}