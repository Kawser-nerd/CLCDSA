using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        //int[] hm = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = int.Parse(Console.ReadLine());
        n = n * (n + 1) / 2;
        //string s = Console.ReadLine();
        Console.WriteLine(GeneratePrime(n).Last() == n ? "WANWAN" : "BOWWOW");

    }
    public static List<int> GeneratePrime(int max)
    {
        if (max == 1) return new List<int> { 0 };

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