using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Round1CB
{
    class Program
    {
        static void Main(string[] args)
        {
            new Program().solve();//attempt(-36,-27);
            Console.ReadLine();
        }

        string attempt(int x, int y)
        {
            int jump = 1;
            int curx = 0;
            int cury = 0;
            string answer = "";
            while (curx != x || cury != y)
            {
                if (curx + jump <= x)
                {
                    answer += "E";
                    curx += jump;
                }
                else if(curx - jump >= x)
                {
                    answer += "W";
                    curx -= jump;
                }
                else if (cury + jump <= y)
                {
                    answer += "N";
                    cury += jump;
                }
                else if (cury - jump >= y)
                {
                    answer += "S";
                    cury -= jump;
                }
                else if (curx < x)
                {
                    answer += "WE";
                    curx += 1;
                    jump++;
                }
                else if (curx > x)
                {
                    answer += "EW";
                    curx -= 1;
                    jump++;
                }
                else if (cury < y)
                {
                    answer += "SN";
                    cury += 1;
                    jump++;
                }
                else if (cury > y)
                {
                    answer += "NS";
                    cury -= 1;
                    jump++;
                }
                //else
                //{
                    //Console.WriteLine("curx=" + curx);
                    //Console.WriteLine("cury=" + cury);
                    //Console.WriteLine("x=" + x);
                    //Console.WriteLine("y=" + y);
                //}
                jump++;
            }
            //Console.WriteLine("curx=" + curx);
            //Console.WriteLine("cury=" + cury);
            //Console.WriteLine("x=" + x);
            //Console.WriteLine("y=" + y);
            //Console.WriteLine(answer);
            return answer;
        }

        string Ask(string question)
        {
            Console.WriteLine(question);
            return Console.ReadLine();
        }

        void printToFile(List<String> lines, string filename)
        {
            using (StreamWriter file =
            new StreamWriter(filename))
            {
                foreach (string line in lines)
                {
                    file.WriteLine(line);
                    //Console.WriteLine(line);
                }
            }
        }

        void solve()
        {
            string filename = Ask("Filename??");
            string[] lines = readFile(filename + ".in");
            List<string> results = new List<string>();
            int numberOfCases = Int32.Parse(lines[0]);
            for (int i = 0; i < numberOfCases; i++)//For each case
            {
                string[] dataline1 = lines[i + 1].Split(' ');
                string answer = attempt(Int32.Parse(dataline1[0]), Int32.Parse(dataline1[1]));
                //long answer = solvebadly2(dataline1[0], Int64.Parse(dataline1[1]));
                results.Add("Case #" + (i + 1) + ": " + answer);
                Console.WriteLine("Case #" + (i + 1) + ": " + answer);
            }
            printToFile(results, filename + ".out");
        }

        string[] readFile(string filename)
        {
            return System.IO.File.ReadAllLines(filename);
        }
    }
}
