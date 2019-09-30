using System;

    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var K = int.Parse(Console.ReadLine());
            var sum = 1;
            for(var i = 0;i<N;i++)
            {
                if(sum<K)
                {
                    sum *= 2;
                    continue;
                }
                sum += K;
            }
            Console.WriteLine(sum);
        }
    }