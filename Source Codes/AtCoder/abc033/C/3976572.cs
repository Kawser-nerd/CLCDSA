using System;
using System.Collections.Generic;
namespace suusiki
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string siki = Console.ReadLine();
            //string siki = "3*1+1*2";
            string[] wake = siki.Split('+');
            string Zero= "0";
            int Zerocount = 0;
            int count = 0;
            for (int i = 0; i < wake.Length; i++)
            {
                if (!wake[count].Contains(Zero))
                {
                    Zerocount++;
                    count++;
                }
                else
                {
                    count++;
                }
              
            }
            Console.WriteLine(Zerocount.ToString());

        }
    }
}