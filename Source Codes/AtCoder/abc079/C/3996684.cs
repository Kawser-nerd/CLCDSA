using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{
    
    class Program
    {

        static List<string> str;

        static void Me(int k, string strer)
        {
            if(k == 3)
            {
                str.Add(strer);
                return;
            }

            Me(k + 1, strer + "+");

            Me(k + 1, strer + "-");

        }


        static void Main(string[] args) 
        {
            str = new List<string>();

            Me(0, "");

            string s = Console.ReadLine();

            var data = new int[4];
            for(int i = 0; i < s.Length; i++)
            {
                data[i] = int.Parse(s[i].ToString());
            }

            
            for(int i = 0; i < str.Count; i++)
            {
                string ss = str[i];
                int sum = data[0];
                for(int j = 0; j < ss.Length; j++)
                {
                    if(ss[j] == '+')
                    {
                        sum += data[j + 1];
                    }
                    else
                    {
                        sum -= data[j + 1];
                    }
                }
                //Console.WriteLine($"{ss} : {sum}");
                if(sum == 7)
                {
                    Console.Write(data[0]);
                    for(int j = 0; j < 3; j++)
                    {
                        Console.Write($"{ss[j]}{data[j + 1]}");
                    }
                    Console.WriteLine("=7");
                    return;
                }
            }



        }
    }
}