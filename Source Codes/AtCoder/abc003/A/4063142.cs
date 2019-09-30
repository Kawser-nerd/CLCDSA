using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int sum = 0;

            for(int i=1;i<=N;i++){
                sum += i;
            }
            int ans = sum * 10000 / N;
            Console.WriteLine(ans);
        }
    }
}