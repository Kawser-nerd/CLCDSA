using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace BotTrust
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader("input.txt");
            StreamWriter writer = new StreamWriter("output.txt");
            int n = int.Parse(reader.ReadLine());
            for (int i = 1; i <= n; i++)
            {

                string line = reader.ReadLine();
                string[] parts = line.Split(' ');
                int segs = int.Parse(parts[0]);

                int time = 0;
                int po = 1, pb = 1;
                int io = 0, ib = 0;
                for (int j = 0; j < segs; j++)
                {
                    bool o = parts[2 * j + 1] == "O";
                    int dest = int.Parse(parts[2 * j + 2]);
                    if (o)
                    {
                        int dist = Math.Abs(po - dest);
                        po = dest;
                        if (io > dist)
                            io = 0;
                        else
                        {
                            dist -= io;
                            io = 0;
                            time += dist;
                            ib += dist;
                        }
                        time++;
                        ib++;
                    }
                    else
                    {
                        int dist = Math.Abs(pb - dest);
                        pb = dest;
                        if (ib > dist)
                            ib = 0;
                        else
                        {
                            dist -= ib;
                            ib = 0;
                            time += dist;
                            io += dist;
                        }
                        time++;
                        io++;
                    }
                }

                writer.WriteLine("Case #{0}: {1}", i, time);


            }
            reader.Close();
            writer.Close();
        }
    }
}
