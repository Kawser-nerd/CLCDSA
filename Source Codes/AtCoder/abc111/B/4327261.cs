using System;
using System.Collections.Generic;
class Program
{
    //static List<string> str = new List<string>();
	static void Main(string[] args)
	{
		// ????t?F?[?Y
        //string[] input = Console.ReadLine().Split(' ');
        int N = int.Parse(Console.ReadLine());
        //int M = int.Parse(input[1]);
        
        int i = 0;
        while(true)
        {
            if(isFit(N + i))
            {
                Console.WriteLine((N+i) + "");
                break;
            }
            else
            {
                i++;
            }
        }

        //?o??
        //Console.WriteLine(ret);
    }

    static bool isFit(int N)
    {
        int a = N % 10;
        while(N>0)
        {
            if(N%10 == a)
            {
                N /= 10;
            }else
            {
                return false;
            }
        }
        return true;
    }

}