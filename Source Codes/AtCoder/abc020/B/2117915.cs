using System;
namespace Atcoder
{
    class AtCoderContest
    {
        static void Main()
        {
            string input = Console.ReadLine();
            string[] inputa = input.Split(' ');
            string added = inputa[0] + inputa[1];
            int before = Convert.ToInt32(added);
            int ans = before * 2;
            Console.WriteLine(ans);
        }
    }
}