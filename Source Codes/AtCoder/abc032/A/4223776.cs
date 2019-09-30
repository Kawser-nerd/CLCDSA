using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int a = int.Parse(Console.ReadLine());
            int b = int.Parse(Console.ReadLine());
            int n = int.Parse(Console.ReadLine());

            int ans = 0;
            for(int i = n; true; i++)
            {
                if (i % a == 0 && i % b == 0)
                {
                    ans = i;
                    break;
                }
            }
            Console.WriteLine(ans);
        }
    }
}