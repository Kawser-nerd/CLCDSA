using System;

namespace HelloCSharp
{
    class Program
    {
        private static void Main(string[] args)
        {
            Solve();
        //    Console.ReadLine();
        }
        
        static void Solve()
        {
            int n = int.Parse(Console.ReadLine());
            n %= 30;
            int[] num = new int[] { 1,2,3,4,5,6 };
            int t,f;
            for (int i = 0; i < n; i++)
            {
                f = i % 5;
                t = num[i%5];
                num[i % 5] = num[i % 5 + 1];
                num[i % 5 + 1] = t;
            }
            foreach (var item in num)
            {
                Console.Write(item);
                
            }
            Console.WriteLine();

        }
    }
}