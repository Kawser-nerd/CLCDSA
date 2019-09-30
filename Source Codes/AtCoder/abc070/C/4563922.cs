using System;
using System.Collections.Generic;
using System.Numerics;

    class Program
    {
        static void Main(string[] args)
        {
            var N = BigInteger.Parse(Console.ReadLine());
            var Ts = new List<BigInteger>();
            for(var i = 0; i < N; i++)
            {
                Ts.Add(BigInteger.Parse(Console.ReadLine()));
            }
            if(N==1)
            {
                Console.WriteLine(Ts[0]);
                return;
            }

            Func<BigInteger, BigInteger, BigInteger> Euclidean = (a, b) =>
            {
                var mul = a * b;
                if (a < b)
                {
                    var tmp = a;
                    a = b;
                    b = tmp;
                }
                var r = a % b;
                while (r != 0)
                {
                    a = b;
                    b = r;
                    r = a % b;
                }
                return mul / b;
            };

            var answer = Euclidean(Ts[0],Ts[1]);
            for (int i=2;i<N;i++)
            {
                answer = Euclidean(answer, Ts[i]);
            }
            Console.WriteLine(answer);
        }
    }