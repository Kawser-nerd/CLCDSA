using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam2012
{
    class Round1A_SpeakingInTongues
    {
        public Round1A_SpeakingInTongues()
        {
            StreamReader reader = new StreamReader("A-small-attempt0.in");
            StreamWriter writer = File.CreateText("A-small-attempt0.out");

            string s = reader.ReadLine();
            int n = Int32.Parse(s);
            int i;
            for (i = 1; i <= n; i++)
            {
                s = Decode(reader.ReadLine());
                writer.WriteLine("Case #" + i + ": " + s);
            }
            reader.Close();
            writer.Close();
        }

        public string Decode(string s)
        {
            string result = s;
            result = result.Replace('a', 'Y');
            result = result.Replace('b', 'H');
            result = result.Replace('c', 'E');
            result = result.Replace('d', 'S');
            result = result.Replace('e', 'O');
            result = result.Replace('f', 'C');
            result = result.Replace('g', 'V');
            result = result.Replace('h', 'X');
            result = result.Replace('i', 'D');
            result = result.Replace('j', 'U');
            result = result.Replace('k', 'I');
            result = result.Replace('l', 'G');
            result = result.Replace('m', 'L');
            result = result.Replace('n', 'B');
            result = result.Replace('o', 'K');
            result = result.Replace('p', 'R');
            result = result.Replace('q', 'Z');
            result = result.Replace('r', 'T');
            result = result.Replace('s', 'N');
            result = result.Replace('t', 'W');
            result = result.Replace('u', 'J');
            result = result.Replace('v', 'P');
            result = result.Replace('w', 'F');
            result = result.Replace('x', 'M');
            result = result.Replace('y', 'A');
            result = result.Replace('z', 'Q');
            result = result.ToLower();
            return result;
        }
    }
}
