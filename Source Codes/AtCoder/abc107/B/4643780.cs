using System;
using System.Collections.Generic;
using System.Linq;

namespace CompetitiveProgramming
{
    class Program
    {
        static void Main(string[] args)
        {
            MainStream();
        }

        static void MainStream()
        {
            //?????
            var sheet = new List<List<char>>();
            string[] h_w = Console.ReadLine().Split();
            int h = int.Parse(h_w[0]);
            int w = int.Parse(h_w[1]);
            int decrease_h = 0;
            for(var i=0;i<h;i++)
            {
                string tmp = Console.ReadLine();
                char[] input = tmp.ToCharArray();
                //??????????????sheet??????
                if(!(input.Contains('#')))
                {
                    decrease_h += 1;
                    continue;
                }
                List<char> line = new List<char>(input);
                sheet.Add(line);
            }
            h -= decrease_h;

             //?????
            for(var j=0;j<w;j++)
            {
                var row = new List<char>();
                for(var i = 0; i<h;i++)
                {
                    row.Add(sheet[i][j]);
                }
                if (!(row.Contains('#')))
                {
                    for(var l=0; l<h; l++)
                    {
                        sheet[l].RemoveAt(j);
                    }
                    w -= 1;
                    j -= 1;
                }
            }
            PrintSheet(sheet);

            


        }
        static void PrintSheet(List<List<char>> sheet)
        {
            foreach(var row in sheet)
            {
                foreach(var rec in row)
                {
                    Console.Write(rec);
                }
                Console.WriteLine("");
            }
        }



    }
}