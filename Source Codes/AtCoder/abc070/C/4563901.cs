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

            BigInteger answer = 0;
            if(N==1)
            {
                Console.WriteLine(Ts[0]);
                return;
            }

            for (int i = 0; i < 1; i++)
            {
                var a = Ts[i];
                var b = Ts[i + 1];
                BigInteger mul = a * b;
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
                answer = mul / b;
            }

            for (int i=2;i<N;i++)
            {
                var a = Ts[i];
                var b = answer;
                var mul = a*b;
                if(a<b)
                {
                    var tmp = a;
                    a = b;
                    b = tmp;
                }

                var r = a % b;
                while(r!=0)
                {
                    a = b;
                    b = r;
                    r = a % b;
                }
                answer = mul / b;
            }

            Console.WriteLine(answer);
        }
    }