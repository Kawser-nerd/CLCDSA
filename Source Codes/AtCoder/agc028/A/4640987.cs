using System;
class Program
    {
    	static void Main(string[] args)
    	{
    		// ?????
    		string[] input = Console.ReadLine().Split(' ');
            long[] a = {long.Parse(input[0]), long.Parse(input[1])};

    		string s = Console.ReadLine();
            string t = Console.ReadLine();

    		//??
            long n = Math.Max(a[0], a[1]), m = Math.Min(a[0], a[1]);
            long big = n; long small = m;
    		while (big % small > 0)
            {
                long buf = big % small;
                big = small;
                small = buf;
            }
            long gcc = small;
            long ret = n * m / gcc;
            for (long i = 0; i < gcc; i++)
            {
                if (s[(int)(a[0] / gcc * i)] != t[(int)(a[1] / gcc * i)])
                {
                    ret = -1;
                    break;
                }
            }
            Console.WriteLine(ret);
        }
    }
    //mcs Main.cs
    //mono Main.exe