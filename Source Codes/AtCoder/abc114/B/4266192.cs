using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		// ??????
		string S = Console.ReadLine();
        int N = S.Length;
        int fav = 753;
        int min = 1000;
        for (int i = 0; i <= N - 3; i++ )
        {
            // i?????3??X?????
            int X = int.Parse(S.Substring(i, 3));
            if (Math.Abs(753-X) < min) min = Math.Abs(753-X);
        }
        //??
        Console.WriteLine(min);
    }

}