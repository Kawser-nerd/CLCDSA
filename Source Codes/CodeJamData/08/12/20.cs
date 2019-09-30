using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace CodeJam2008
{
    public class Program
    {
        public static void Main(string[] args)
        {
            if (args.Length < 2)
            {
                Console.WriteLine("Usage: CodeJam2008 <INPUT> <OUTPUT>");
                return;
            }
            string inputfile = args[0];
            string outputfile = args[1];
            MilkShakes an = new MilkShakes();
            an.shake(inputfile, outputfile);
    
        }
    }
}
