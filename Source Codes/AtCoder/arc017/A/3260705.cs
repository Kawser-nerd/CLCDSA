using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
	bool[] isPrimes = makePrimeList(1000001);//i-1???????
  long a = int.Parse(Console.ReadLine());
  if(isPrimes[a-1]) Console.WriteLine("YES");//WriteLine?Write?????????????
  else Console.WriteLine("NO");
	}

  static bool[] makePrimeList(long maxPrime)//??max??????????????????????
  {
    bool[] isPrimes = new bool[maxPrime];//?????
    isPrimes[0] = false;//1????????false
    for(long i = 1; i < maxPrime; i++) isPrimes[i] = true;//???????true
    
    for(long i = 2; i < Math.Sqrt(maxPrime); i++)
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