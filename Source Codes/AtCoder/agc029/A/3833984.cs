using System;

namespace AGC029A
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = "";
            int whiteCount = 0;
            long swapCount = 0;

            s = Console.ReadLine();

            for(int i = 0; i < s.Length; ++i)
            {
                if(s[i] == 'W')
                {
                    swapCount += i - whiteCount;
                    ++whiteCount;
                }
            }

            Console.WriteLine(swapCount);
        }
    }
}