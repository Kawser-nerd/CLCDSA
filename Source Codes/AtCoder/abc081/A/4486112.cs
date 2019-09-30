using System;
using System.IO;//StreamWriter??????
using System.Collections.Generic;//List?????????

namespace dotnetproj
{
    class Program
    {
        static void Main(string[] args)
        {
            int count=0;
            string input = Console.ReadLine();
            char[] chars = input.ToCharArray();
            foreach(char c in chars){
                if(c=='1') count++;
            }
            Console.WriteLine(count);
        }
    }
}