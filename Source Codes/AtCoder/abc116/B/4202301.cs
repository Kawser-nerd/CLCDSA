using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		// ??????
				int s = int.Parse(Console.ReadLine());
        int m = 0;
        List<int> arr = new List<int>(){s};

        while(m <= 1000000)
        {
            // ???????
            int next = 0;
            int n = arr[m];
            if(n % 2 == 0)
            {
              // even
              next = n / 2;
            }else
            {
              // odd
              next = n * 3 + 1;
            }
            //Console.WriteLine(" next " + next);
            if(arr.Contains(next))
            {
              // ??
              break;
            }else
            {
              arr.Add(next);
            }
            m++;
        }
        Console.WriteLine(m + 2);
    }
}