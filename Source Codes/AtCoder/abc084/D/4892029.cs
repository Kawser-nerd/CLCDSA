using System;
using System.Linq;

    class Program
    {
        static void Main(string[] args)
        {
            var Q = int.Parse(Console.ReadLine());
            var primes = new bool[100001];
            primes[2] = true;
            for (var i = 3;i<primes.Length;i=i+2)
            {
                primes[i] = true;
            }
            for(var i = 3;i<primes.Length;)
            {
                for (var k = i; k < primes.Length; k = k + i)
                {
                    if (!primes[k]) continue;
                    if(k%i==0&&i!=k)
                    {
                        primes[k] = false;
                    }
                }
                for(i++; i<primes.Length; i++)
                {
                    if (primes[i]) break;
                }
            }

            var nearNum = new int[100002];
            for (var i = 3; i < primes.Length;i++)
            {
                nearNum[i] = primes[i]&& primes[(i+1)/2] ? nearNum[i - 1] + 1 : nearNum[i - 1];
            }

            for(var i =0;i<Q;i++)
            {
                var lr = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToList();
                var l = lr[0];
                var r = lr[1];
                Console.WriteLine(nearNum[r] - nearNum[l-1]);
            }
        }
    }