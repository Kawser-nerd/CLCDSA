using System;
using System.Collections;


namespace Dcs
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = int.Parse( Console.ReadLine() );
            var primes = new ArrayList();

            var x = 11;
            while ( primes.Count < n)
            {
                var max_ = (int)Math.Sqrt(x);
                bool is_prime = true;
                for(int i = 3; i <= max_; i += 2)
                {
                    if (x % i == 0)
                    {
                        is_prime = false;
                        break;
                    }
                }

                if (is_prime)
                    primes.Add(x);

                x += 10;
            }
            for (int i = 0; i < n - 1; ++i)
                Console.Write( primes[i] + " ");

            Console.WriteLine( primes[n-1] );
        }
    }
}