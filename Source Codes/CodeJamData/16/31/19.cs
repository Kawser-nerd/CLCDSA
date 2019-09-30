using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace CodeJam2016Library
{
    public class Problem1C_A
    {
        public static string Run(string input)
        {
            StringBuilder output = new StringBuilder();
            string[] lines = input.Split('\n');

            int i = 0;
            int cases = int.Parse(lines[i++]);

            for (int c = 0; c < cases; c++)
            {
                int caseinput = int.Parse(lines[i++]);
                string[] senators = lines[i++].Split(' ');
                string caseoutput = RunCase(caseinput, senators);
                output.AppendLine("Case #" + (c + 1) + ": " + caseoutput);
            }

            return output.ToString();
        }

        private static string RunCase(int n, string[] data)
        {
            string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            string output = "";


            List<int> senators = new List<int>();
            //Fill
            for (int i=0; i < data.Length; i++)
            {
                senators.Add(int.Parse(data[i]));
            }

            bool exit = false;
            do
            {
                int max = 0;
                int selected = -1;

                int count = 0;
                List<int> notempty = new List<int>();
                for (int i = 0; i < senators.Count(); i++)
                {
                    if (senators[i] > max)
                    {
                        max = senators[i];
                        selected = i;
                    }
                    if (senators[i] > 0)
                    {
                        count += senators[i];
                        notempty.Add(i);
                    }

                    
                }
                if (notempty.Count == 2)
                {
                    output += "" + abc[notempty[0]] + abc[notempty[1]];
                    senators[notempty[0]]--;
                    senators[notempty[1]]--;

                    if (count == 2)
                        exit = true;
                    else
                        output += " ";
                }
                else
                {
                    output += abc[selected] + " ";
                    senators[selected]--;
                }

            } while (!exit);

            return output;
        }
        
        

    }

}
