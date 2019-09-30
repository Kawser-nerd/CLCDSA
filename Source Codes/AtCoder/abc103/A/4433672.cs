using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int A1 = input[0];
            int A2 = input[1];
            int A3 = input[2];
            int[] data = new int[3];
            data[0] = Math.Abs(A1 - A2);
            data[1] = Math.Abs(A2 - A3);
            data[2] = Math.Abs(A3 - A1);
            Array.Sort(data);
            Console.WriteLine(data[0] + data[1]);
        }
    }
}