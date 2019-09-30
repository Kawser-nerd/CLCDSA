using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int A = input[0];
            int D = input[1];

            int A2 = (A + 1) * D; //???????????
            int D2 = (D + 1) * A; //???????????

            if (A2 > D2)
            {
                Console.WriteLine(A2);
            }
            else if (D2 > A2){
                Console.WriteLine(D2);
            }
            else{
                Console.WriteLine(A2);
            }
        }
    }
}