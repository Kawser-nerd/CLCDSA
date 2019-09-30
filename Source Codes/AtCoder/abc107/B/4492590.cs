using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    //static List<string> str = new List<string>();
    static void Main(string[] args)
    {
        // ??
        string[] input = Console.ReadLine().Split(' ');
        int H = int.Parse(input[0]);
        int W = int.Parse(input[1]);

        List<string> board = new List<string>();
        for(int i = 0; i<H; i++)
        {
            board.Add(Console.ReadLine());
        }

        // .?????????
        List<string> comp = new List<string>();
        for(int i=0; i<H; i++)
        {
            string str1 = board[i];
            string str2 = str1.Replace("#", "");
            if(str1.CompareTo(str2) != 0)
            {
                comp.Add(str1);
            }
        }
        //Console.WriteLine("comped");
        // .??????????
        for(int i=0; i<W; i++)
        {
            // i??
            bool isWhite = true;
            for(int j=0; j<comp.Count; j++)
            {
                if (comp[j][i] != '.')
                    isWhite = false;
            }
            //Console.WriteLine(i + " : " + isWhite);

            if(isWhite)
            {
                for(int j=0; j<comp.Count; j++)
                {
                    comp[j] = (i==0 ? "" : comp[j].Substring(0, i)) + "d" + comp[j].Substring(i + 1);
                }
  
            }
        }

        // ??
        for(int i=0; i<comp.Count; i++)
        {
            Console.WriteLine(comp[i].Replace("d", ""));
        }
       
    }

}