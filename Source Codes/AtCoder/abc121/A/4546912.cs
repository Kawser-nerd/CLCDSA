using System;


namespace _121_ABC
{
    class Program01
    {
        static void Main(string[] args)
        {
            string[] input1 = Console.ReadLine().Split(' ');
            int H = int.Parse(input1[0]);
            int W = int.Parse(input1[1]);

            string[] input2 = Console.ReadLine().Split(' ');
            int h = int.Parse(input2[0]);
            int w = int.Parse(input2[1]);

            int Ans = (H - h) * (W - w);

            Console.WriteLine(Ans);

        }
    }
}