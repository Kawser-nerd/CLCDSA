using System;

namespace AtCoder_20190218
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] str = Console.ReadLine().Split(' ');


            int N = int.Parse(str[0]);
            int A = int.Parse(str[1]);
            int B = int.Parse(str[2]);

            int Result = 0;

            for (int i = 1; i <= N; i++)
            {
                int keta1 = i % 10;
                int keta2 = (i / 10) % 10;
                int keta3 = (i / 100) % 10;
                int keta4 = (i / 1000) % 10;
                int keta5 = (i / 10000) % 10;

                int total = keta1 + keta2 + keta3 + keta4 + keta5;

                if(A<=total&&total<=B)
                {
                    Result += i;
                }
            }

            Console.WriteLine(Result);
        }
    }
}