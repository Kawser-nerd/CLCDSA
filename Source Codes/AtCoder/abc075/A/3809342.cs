using System;

namespace AtCoder
{
    class program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');

            int A = int.Parse(input[0]);int B = int.Parse(input[1]);int C = int.Parse(input[2]);

            if(B == C){
                Console.WriteLine(A);
            }else if (A == C){
                Console.WriteLine(B);
            }else{
                Console.WriteLine(C);
            }
        }
    }
}