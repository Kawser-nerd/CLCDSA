using System;

namespace ABC078
{
    public class Problem_B
    {
        public static void Main(string[] args)
        {
            var inputs = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int x = inputs[0], y = inputs[1], z = inputs[2];
            var ans = (x - z) / (y + z);
            Console.WriteLine($"{ans}");
        }
    }
}