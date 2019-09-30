using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
	long n = long.Parse(Console.ReadLine());
  long[,] vertexes = new long[n,4];
  bool answer = true;
    for(long i = 0; i < n; i++)
    {
    long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
    vertexes[i,0] = nums[0];
    vertexes[i,1] = nums[1];
    vertexes[i,2] = nums[2];
    vertexes[i,3] = nums[3];
    }

    for(long i = 0; i < n; i++)
    {
    long a = vertexes[i,0];
    long b = vertexes[i,1];
    long c = vertexes[i,2];
    long d = vertexes[i,3];
      if(a < b) answer = false;
      else if(d < b) answer = false;
      else if(b-1 < c+1) answer = true;
      else
      {
        answer = true;
        long gcd = Gcd(b, d);
        long memo = (c+1-a)%gcd;
        long memoSub = (b-1-a)%gcd;
        if(memo == 0) answer = false;
        else if(memoSub < memo) answer = false;
        else if(b-c-2 >= gcd-1) answer = false;
      }
      Console.WriteLine(answer ? "Yes" : "No");
    
    }
  }

  static long Gcd(long a, long b) 
    {//??a,b?????????
         if (a < b)
             return Gcd(b, a);//????
         while (b != 0) 
         {
             long changeTo = a % b;
             a = b;
             b = changeTo;
         }
         return a;
     }

    
}