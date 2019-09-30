using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');//Split???????????????????
		long q = long.Parse(input[0]);
		long h = long.Parse(input[1]);
    long s = long.Parse(input[2]);
		long d = long.Parse(input[3]);
		long n = long.Parse(Console.ReadLine());
    long answer = 0;
    long memo = 0;

    long memoQ = q*8;
    long memoH = h*4;
    long memoS = s*2;
    n *= 4;

    if(d > memoS) d = memoS;
    if(d > memoH) d = memoH;
    if(d > memoQ) d = memoQ;
    if(s > h*2) s = h*2;
    if(s > q*4) s = q*4;
    if(h > q*2) h = q*2;

    answer += n/8*d;
    n %= 8;
    //Console.WriteLine(answer);
    answer += n/4*s;
    n %= 4;
    //Console.WriteLine(answer);
    answer += n/2*h;
    n %= 2;
    //Console.WriteLine(answer);
    answer += n*q;
    
		Console.WriteLine(answer);
	}
}