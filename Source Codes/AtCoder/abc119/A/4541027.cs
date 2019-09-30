using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            DateTime S = DateTime.Parse(Console.ReadLine());
            Console.WriteLine(S <= new DateTime(2019,4,30) ? "Heisei" : "TBD");
        }
    }
}