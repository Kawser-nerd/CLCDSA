using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{ 

    class Program
    {

        
        static void Main(string[] args)
        {

            string S = Console.ReadLine();
            string N = Console.ReadLine();

            if(N.Length <= 3 && int.Parse(N) <= 100 && int.Parse(S[0].ToString()) == 1)
            {
                for(int i = 0; i < int.Parse(N); i++)
                {
                    if(int.Parse(S[i].ToString()) != 1)
                    {
                        Console.WriteLine(S[i]);
                        return;
                    }
                    if(i == int.Parse(N) - 1)
                    {
                        Console.WriteLine("1");
                        return;
                    }
                }
            }
            else
            {
                for(int i = 0; i < S.Length; i++)
                {
                    if(int.Parse(S[i].ToString()) != 1)
                    {
                        Console.WriteLine(S[i]);
                        return;
                    }
                }
            }

        }
    }
}