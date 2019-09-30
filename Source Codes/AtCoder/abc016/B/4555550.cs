using System;
using System.Linq;

namespace ABC016B
{
    class Program
    {
        static void Main(string[] args)
        {
            var line = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            var A = line[0]; var B = line[1]; var C = line[2];
            int pflag = 0; int mflag = 0;

            if(A + B == C)
            {
                pflag = 1;
            }

            if(A - B == C)
            {
                mflag = 1;
            }

            if(pflag == 1 && mflag == 1)
            {
                Console.WriteLine('?');
            }
            else if(pflag == 1 && mflag == 0)
            {
                Console.WriteLine('+');
            }
            else if(pflag == 0 && mflag == 1)
            {
                Console.WriteLine('-');
            }
            else
            {
                Console.WriteLine('!');
            }
        }
    }
}