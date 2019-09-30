using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Milkshakes
{
    class Program
    {
        static void Main(string[] args)
        {
            FileStream inStream = File.OpenRead(args[0]);
            FileStream outStream = File.Create("milkshakes.out");

            StreamReader reader = new StreamReader(inStream);
            StreamWriter writer = new StreamWriter(outStream);

            try
            {
                int nCases = Int32.Parse(reader.ReadLine());

                for (int c = 1; c <= nCases; c++)
                {
                    int n = Int32.Parse(reader.ReadLine());
                    int m = Int32.Parse(reader.ReadLine());

                    List<CustPref>[] cust = new List<CustPref>[m];
                    for (int i = 0; i < m; i++)
                    {
                        string[] parts = reader.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                        int t = Int32.Parse(parts[0]);
                        cust[i] = new List<CustPref>(t);
                        for (int j = 0; j < t; j++)
                        {
                            CustPref cp = new CustPref();
                            cp.number = Int32.Parse(parts[2 * j + 1]) - 1;
                            cp.mated = (parts[2 * j + 2] == "1");
                            cust[i].Add(cp);
                        }
                    }

                    bool[] myShakes = new bool[n];
                    bool possible = true;
                    while (possible)
                    {
                        //Find unsatisfied customer
                        int cNumber = -1;
                        for (int i = 0; i < m; i++)
                        {
                            bool good = false;
                            for (int j = 0; j < cust[i].Count; j++)
                            {
                                if (myShakes[cust[i][j].number] == cust[i][j].mated)
                                {
                                    good = true;
                                    break;
                                }
                            }
                            if (!good)
                            {
                                cNumber = i;
                                break;
                            }
                        }
                        if (cNumber < 0) { break; }
                        //Try to satisfy by switching to malted
                        bool satisfied = false;
                        for (int j = 0; j < cust[cNumber].Count; j++) 
                        {
                            CustPref cp = cust[cNumber][j];
                            if (cp.mated) 
                            {
                                if (myShakes[cp.number])
                                {
                                    possible = false;
                                    break;
                                }
                                else
                                {
                                    myShakes[cp.number] = true;
                                    satisfied = true;
                                    break;
                                }
                            }
                        }
                        if (!satisfied)
                        {
                            possible = false;
                            break;
                        }
                    }
                    if (possible)
                    {
                        writer.Write("Case #{0}: ", c);
                        for (int i = 0; i < n; i++) 
                        {
                            writer.Write(myShakes[i] ? "1 " : "0 ");
                        }
                        writer.WriteLine();
                    }
                    else
                        writer.WriteLine("Case #{0}: IMPOSSIBLE", c);
                }
            }
            finally
            {
                reader.Close();
                writer.Close();
            }
        }
    }
    public class CustPref 
    {
        public int number;
        public bool mated;
    }
}
