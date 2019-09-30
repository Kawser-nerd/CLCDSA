// This file is a "Hello, world!" in C# language by Mono for wandbox.
using System;
namespace Wandbox
{
    class Program
    {
        static void Main(string[] args)
        {
            var imp = Console.ReadLine();
            char N = char.Parse(imp);
            switch(N)
                {
                case'A':
                    Console.Write('T');
                    break;
                case'T':
                    Console.Write('A');
                    break;
                case'C':
                    Console.Write('G');
                    break;
                case'G':
                    Console.Write('C');
                    break;
                    }
        }
    }
}
       

// Mono references:
//   http://www.mono-project.com/

// C# language references:
//   https://msdn.microsoft.com/library/618ayhy6.aspx