using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;

namespace CodeJam2017
{
 
    class Stable
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines("input.txt");
            StringWriter output = new StringWriter();

            int n = int.Parse(lines[0]);
            int at = 1;
            for(int i=0;i<n;i++)
            {
                string[] line2 = lines[at++].Split();
                int N = int.Parse(line2[0]);
                int R = int.Parse(line2[1]);
                int O = int.Parse(line2[2]);
                int Y = int.Parse(line2[3]);
                int G = int.Parse(line2[4]);
                int B = int.Parse(line2[5]);
                int V = int.Parse(line2[6]);

                char[] colors = new char[] { 'R', 'O', 'Y', 'G', 'B', 'V' };
                int[] counts = new int[6];
                for(int j=0;j<6;j++)
                {
                    counts[j] = int.Parse(line2[j + 1]);
                }
                int bi = 0;
                int ni1 = 0, ni2 = 0;
                if(R >= Y && R >= B)
                {
                    bi = 0;
                    if (Y >= B)
                    {
                        ni1 = 2;
                        ni2 = 4;
                    }
                    else
                    {
                        ni1 = 4;
                        ni2 = 2;
                    }
                }
                else if(Y >= R && Y >= B)
                {
                    bi = 2;
                    if (R > B)
                    {
                        ni1 = 0;
                        ni2 = 4;
                    }
                    else
                    {
                        ni1 = 4;
                        ni2 = 0;
                    }
                }
                else
                {
                    bi = 4;
                    if(R > Y)
                    {
                        ni1 = 0;
                        ni2 = 2;
                    }
                    else
                    {
                        ni1 = 2;
                        ni2 = 0;
                    }
                }
                
                
                string res = "";
                if (counts[bi] > counts[ni1] + counts[ni2])
                {
                    res = "IMPOSSIBLE";
                }
                else
                {
                    int how = counts[ni1] + counts[ni2] - counts[bi];
                    int skip = counts[ni1] - how;
                    int c = counts[ni1];
                    StringBuilder o = new StringBuilder();
                    for (int j = 0; j < counts[bi];j++)
                    {
                        o.Append(colors[bi]);
                        if (c > 0)
                        {
                            o.Append(colors[ni1]);
                            c--;
                        }
                        
                        skip--;
                        if(skip < 0)
                        {
                            o.Append(colors[ni2]);
                        }
                    }
                    res = o.ToString();
                }
                

                
                output.WriteLine("Case #" + (i + 1) + ": " + res);
            }
            File.WriteAllText("output.txt", output.ToString());
            Console.WriteLine(output.ToString());
        }
    }
}
