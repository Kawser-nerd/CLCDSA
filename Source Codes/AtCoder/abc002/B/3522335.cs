using System;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ??????1????
            string input = Console.ReadLine();

            // ???a,i,u,e,o????
            string output = input.Replace("a", "").Replace("i","").Replace("u","").Replace("e","").Replace("o","");

            // ???????
            Console.WriteLine(output);
        }
    }
}