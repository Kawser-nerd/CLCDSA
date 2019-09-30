using System;
using System.Collections.Generic;

namespace ConsoleApplication1
{

    class Program
    {

        static void Main(string[] args)
        {


            string str = Console.ReadLine();

            string alf = "abcdefghijklmnopqrstuvwxyz";

            bool[] f = new bool[alf.Length];

            for(int i = 0; i < str.Length; i++)
            {
                f[alf.IndexOf(str[i])] = true;
            }

            for(int i = 0; i < alf.Length; i++)
            {
                if (!f[i])
                {
                    Console.WriteLine(alf[i]);
                    break;
                }
                if(i == alf.Length - 1)
                {
                    Console.WriteLine("None");
                }
            }


        }
    }
}