using System;
    using System.Linq;
    using System.Collections.Generic;

    public class Program
    {
        public static void Main(string[] args)
        {
            List<int> inputAB= Console.ReadLine().Split(' ').Select(int.Parse).ToList();
            List<string> input = Console.ReadLine().Split('-').ToList();

            Console.WriteLine(input[0].Length == inputAB[0] && input[1].Length == inputAB[1] ? "Yes":" No");
        }
    }