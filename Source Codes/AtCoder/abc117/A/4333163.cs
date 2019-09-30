using System;
 
namespace AtCoder
{
    class ABC117A
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' '); 
            float t = int.Parse(input[0]);
            float x = int.Parse(input[1]);
 
            Console.WriteLine(t / x);
        }      
    }
}