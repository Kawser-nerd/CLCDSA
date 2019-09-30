using System;
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var max = 0;
            var maxResult = 1;
            for(var i = 1;i<=N;i++)
            {
                var count = 0;
                var ii = i;
                while(true)
                {
                    if (ii % 2 != 0) break;
                    count++;
                    ii /= 2;
                }
                if (max < count)
                {
                    max = count;
                    maxResult = i;
                }
            }
            Console.WriteLine(maxResult);
        }
    }