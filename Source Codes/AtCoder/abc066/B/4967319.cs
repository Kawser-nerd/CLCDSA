using System;

namespace B___ss
{
    class Program
    {
        static void Main(string[] args)
        {
            var S = Console.ReadLine();

            while (true)
            {
                 S = S.Substring(0, S.Length - 1);
                if (S.Substring(0, S.Length / 2) == S.Substring(S.Length / 2, S.Length - S.Length / 2))
                    break;
            }

            Console.WriteLine(S.Length);
        }
    }
}