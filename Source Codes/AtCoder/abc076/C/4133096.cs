using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{

    class Program
    {


        static void Main(string[] args)
        {
            char[] ss = Console.ReadLine().ToCharArray();
            char[] t = Console.ReadLine().ToCharArray();

            int sslen = ss.Length;
            int tlen = t.Length;
            bool flag = false;
           
            for (int i = sslen - tlen; i >= 0; i--)
            {
                
                for(int j = 0; j < tlen; j++)
                {
                    if (ss[i + j] == '?')
                    {
                        if (j == tlen - 1) flag = true;
                        else continue;
                    }
                    else if (ss[i + j] == t[j])
                    {
                        if (j == tlen - 1) flag = true;
                        else continue;
                    }
                    else break;
                }

                if (flag)
                {
                    for(int j = 0; j < tlen; j++)
                    {
                        if (ss[i + j] == '?') ss[i + j] = t[j];
                    }
                    for(int j = 0; j < sslen; j++)
                    {
                        if (ss[j] == '?') ss[j] = 'a';
                    }
                    break;
                }

            }


            if (flag)
            {
                Console.WriteLine(String.Join("", ss));
            }
            else
            {
                Console.WriteLine("UNRESTORABLE");
            }
            
        }
    }
}