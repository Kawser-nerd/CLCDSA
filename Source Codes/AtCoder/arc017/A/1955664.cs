using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        Console.WriteLine(GeneratePrime(n).Last() == n ? "YES" : "NO");
    }
    public static List<int> GeneratePrime(int max)
    {
        System.Diagnostics.Debug.Assert(max >= 2);

        int prime;
        double sqrtMax = Math.Sqrt(max);
        var primeList = new List<int>();
        var searchList = Enumerable.Range(2, max - 1).ToList();

        do
        {
            prime = searchList.First();
            primeList.Add(prime);
            searchList.RemoveAll(n => n % prime == 0);
        } while (prime < sqrtMax);
        primeList.AddRange(searchList);

        return primeList;
    }
}