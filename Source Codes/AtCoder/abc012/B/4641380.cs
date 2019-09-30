using System;

namespace atcoderB
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            var time = new TimeSpan(0, 0, N);
            Console.WriteLine(time.ToString());
        }
    }
}