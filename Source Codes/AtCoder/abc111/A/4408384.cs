using System;
using System.Collections.Generic;

namespace CompetitiveProgramming
{
    class Program
    {
        static void Main(string[] args)
        {
            string text = Console.ReadLine();
            int newText = 0;
            if(text[0] == '1')
            {
                newText += 900;
            }else{
                newText += 100;
            }
            if (text[1] == '1')
            {
                newText += 90;
            }
            else
            {
                newText += 10;
            }
            if (text[2] == '1')
            {
                newText += 9;
            }
            else
            {
                newText += 1;
            }

            Console.WriteLine(newText);

        }
    }
}