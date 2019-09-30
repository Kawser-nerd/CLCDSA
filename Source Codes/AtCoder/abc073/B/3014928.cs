using System;

namespace Sample101
{
    class Program
    {
        static void Main(string[] args)
        {
            // ????
            int N = int.Parse(Console.ReadLine());
            // ??????????????????????????
            // ??????????
            int result = 0;     // ????
            for (int i = 0; i < N; ++i)
            {
                string[] s = Console.ReadLine().Split(' ');
                int start = int.Parse(s[0]);
                int end = int.Parse(s[1]);
                result += (end - start + 1);
            }
            Console.WriteLine(result);
        }
    }
}