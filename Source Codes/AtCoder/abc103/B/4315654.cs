using System;
using System.Linq;

namespace B.String_Rotation
{
    class Program
    {
        static void Main(string[] args)
        {
            var S = Console.ReadLine();
            var T = Console.ReadLine();
            bool ans = false;

            for (int i = 0; i < S.Length; i++)
            {
                S = string.Concat(S.Last(), S);
                S = S.Remove(S.Length - 1);

                if (S==T)
                {
                    ans = true;
                    break;
                }
            }

            Console.WriteLine(ans ? "Yes" : "No");
        }
    }
}