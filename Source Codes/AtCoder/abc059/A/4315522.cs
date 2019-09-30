using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            var s1 = input[0].Substring(0, 1);
            var s2 = input[1].Substring(0, 1);
            var s3 = input[2].Substring(0, 1);
            var ans = s1 + s2 + s3;
            Console.WriteLine(ans.ToUpper());
        }
    }
}