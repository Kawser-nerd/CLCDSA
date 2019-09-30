using System;

namespace ABC065B
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = Int32.Parse(Console.ReadLine());
            int[] next = new int[N + 1];
            bool[] visited = new bool[N + 1];

            for (int i = 1; i <= N; i++)
            {
                next[i] = Int32.Parse(Console.ReadLine());
            }

            int cur = 1;
            int res = 0;

            while (cur != 2)
            {
                if (visited[cur])
                {
                    res = -1;
                    break;
                }
                res++;
                visited[cur] = true;
                cur = next[cur];
            }

 
            Console.WriteLine(res);
        }
    }
}