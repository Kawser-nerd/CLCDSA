using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace CsProgramSpace
{
    public partial class Pencil
    {

        partial class Program
        {
            static void Main(string[] args)
            {
                char[] c = Console.ReadLine().ToCharArray();
                Console.WriteLine(int.Parse(c[0].ToString())+int.Parse(c[1].ToString()));
            }
        }
    }
}