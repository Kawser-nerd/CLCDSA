using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var S = Console.ReadLine();
            var abc = S.ToCharArray();
            Array.Sort(abc);
            Console.WriteLine(abc[0] == 'a' && abc[1] == 'b' && abc[2] == 'c' ? "Yes" : "No");
        }
    }
}