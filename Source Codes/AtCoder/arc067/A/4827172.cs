using System;

    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var divisor = new int[N + 1];
            for(var i = 2;i<=N;i++)
            {
                var x = i;
                for(var j = 2;j<=N;j++)
                {
                    var k = 0;
                    if(x%j==0)
                    {
                        for (k = 0; x % j == 0; x /= j) k++;
                    }
                    divisor[j] += k;
                }
            }
            long count = 1;
            for(var i =2;i<=N;i++)
            {
                count *= divisor[i] + 1;
                count %= 1000000007;
            }
            Console.WriteLine(count);
        }
    }