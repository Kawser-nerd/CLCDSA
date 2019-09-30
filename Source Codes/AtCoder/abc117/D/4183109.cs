using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		// ?????
		//int N = int.Parse(Console.ReadLine());
		// ?????????????
		string[] input = Console.ReadLine().Split(' ');
        int N = int.Parse(input[0]);
        long K = long.Parse(input[1]);
 
		// N???????
        string[] nums = Console.ReadLine().Split(' '); 
 
		// ??????
		//string s = Console.ReadLine();
 
        // K?2???????
        string strK = Convert.ToString(K, 2);
        // K?2????????int[]???
        int[] xor = new int[strK.Length];
        for (int i = 0; i < strK.Length; i++)
        {
            xor[i] = 0;
        }
        // N?????2?????i???1????????
        for (int i = 0; i < N; i++)
        {
            string strAi = Convert.ToString(long.Parse(nums[i]), 2);
            for (int j = strAi.Length - 1, k=strK.Length -1; j>=0 && k>=0; j--, k--)
            {
                if (strAi[j] == '1')
                {
                    xor[k] += 1;
                }
            }
        }
        bool smallerFlg = false; // K???????????????
        string strX = "";
        // N???????????????f(x)?????????x????
        for (int i = 0; i < xor.Length; i++)
        {
            if (xor[i] <= N / 2)
            {
                if (strK[i] == '1' || smallerFlg)
                {
                    strX =  strX + "1";
                }
                else
                {
                    strX = strX + "0";
                }
            }
            else
            {
                if (strK[i] == '1')
                    smallerFlg = true;
                strX = strX + "0";
            }
        }
        // f(x)???
        long ret = 0;
        long X = Convert.ToInt64(strX, 2);
        for (int i = 0; i < N; i++)
        {
            //int a = Convert.ToInt32(int.Parse(nums[i]) ^ X);
            //Console.WriteLine(nums[i] + "^" + X + "=" + a);
            ret += long.Parse(nums[i]) ^ X;
        }
            //??
        Console.WriteLine(ret + "");
	    }
}