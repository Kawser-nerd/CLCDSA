using System;
using System.Collections.Generic;

namespace atcoder
{
    class Program
    {
        static void Main(string[] args)
        {
            int A = int.Parse(Console.ReadLine());//500
            int B = int.Parse(Console.ReadLine());//100
            int C = int.Parse(Console.ReadLine());//50
            int X = int.Parse(Console.ReadLine());//sum
            int count = 0; 
            for(int i=0;i<=A;i++){
                for(int j=0;j<=B;j++){
                    for(int k=0;k<=C;k++){
                        if(500*i+100*j+50*k==X) count++;
                    }
                }
            }
            Console.WriteLine(count);
        }
    }
}