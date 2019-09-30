using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
	static void Main()
	{
  bool[] isPrimes = makePrimeList(100000);//i-1???????
  int[] trueCount = new int[100000];//i-1?????????????

    int nowTrueCount = 0;
    for(int i=0; i<trueCount.Length; i+=2)//1??i????????
    {
      if(isPrimes[i] && isPrimes[(i+1)/2]) nowTrueCount++;
      trueCount[i] = nowTrueCount;
    }
  
    int q = int.Parse(Console.ReadLine());
    for(int i = 0; i < q; i++)//q?????????
    {
      int[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
      int answer = trueCount[nums[1]-1];
      if(nums[0]-3 >= 0) answer -= trueCount[nums[0]-3];//????0????????-2???-2
      Console.WriteLine(answer);
    }

	}

  static bool[] makePrimeList(int maxPrime)//??max???????????????????????????
  {
    bool[] isPrimes = new bool[maxPrime];//?????
    isPrimes[0] = false;
    for(int i = 1; i < maxPrime; i++) isPrimes[i] = true;
    
    for(int i = 2; i < Math.Sqrt(maxPrime); i++)
    {
      if(isPrimes[i-1])
      {
        for (int j = i*2; j <= maxPrime; j+=i)
        {
          isPrimes[j-1] = false;
        }
      }
    }

    return isPrimes;
  }
  
}