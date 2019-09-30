using System;

    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            int res = N;

            for(int i=0;i<=N;i++)
            {
                var count = 0;
                var t = i;
                while(t>0)
                {
                    count += t % 6;
                    t /= 6;
                }
                t = N - i;
                while (t > 0)
                {
                    count += t % 9;
                    t /= 9;
                }
                if (res > count) res = count;
            }
            Console.WriteLine(res);
        }
    }