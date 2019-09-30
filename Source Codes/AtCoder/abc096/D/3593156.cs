using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
  static void Main()
  {
    long n = long.Parse(Console.ReadLine());
    bool[] isPrimes = makePrimeList(55555);//i-1???????
    long[] answers = new long[n];
    long memo = 0;
    for(int i = 0; i < 55555; i++)
    {
      if(isPrimes[i] && (i+1)%5==1)
      {
        answers[memo] = i+1;
        memo++;
        if(memo == n) break;
      }
    }
    Console.WriteLine(string.Join(" ", answers));
  }


  static bool[] makePrimeList(long maxPrime)//???1???max??????????????????????
  {
    bool[] isPrimes = new bool[maxPrime];//?????
    isPrimes[0] = false;//1????????false
    for(long i = 1; i < maxPrime; i++) isPrimes[i] = true;//???????true
  
    for(long i = 2; i <= Math.Sqrt(maxPrime); i++)
    {
      if(isPrimes[i-1])
      {
        for (long j = i*2; j <= maxPrime; j+=i)
        {
          isPrimes[j-1] = false;//???????false
        }
      }
    }

    return isPrimes;
  }
}