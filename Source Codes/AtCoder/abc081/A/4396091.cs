using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string s = Console.ReadLine();
            int count = 0;
            for(int i = 0; i < 3; i++)
            {
                if (s[i] == '1')
                {
                    count += 1;
                }
            }
            Console.WriteLine(count);
        }
    }
}