using System;
using System.Collections.Generic;
using System.Linq;

namespace Beginner002B
{
    class Program
    {
        static void Main(string[] args)
        {
            var vowel = new List<char> { 'a', 'i', 'u', 'e', 'o' };

            var takenWord = Console.ReadLine().Where(c => !vowel.Exists(v => v == c));
            Console.WriteLine(string.Join(string.Empty, takenWord));
        }
    }
}