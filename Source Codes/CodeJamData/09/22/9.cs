using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace B
{
    class Program2
    {
        static void Main(string[] args)
        {
            StreamReader re = File.OpenText("input.txt");
            FileInfo t = new FileInfo("output.txt");
            StreamWriter Tex = t.CreateText();

            int T = int.Parse(re.ReadLine());
            for (int i = 0; i < T; i++)
            {
                string N = re.ReadLine(); // Up to 20
                char[] line = N.ToCharArray();
                bool found = false;
                for (int k = N.Length - 2; k >= 0; k-- )
                {
                    // find min to replace
                    int min = -1;
                    for (int l = k + 1; l < N.Length; l++)
                    {
                        if (N[l] > N[k])// replacement is possible
                        {
                            if (min == -1 || N[l] < N[min]) min = l;
                        }
                    }
                    if (min != -1)
                    {
                        found = true;
                        line[min] = N[k];
                        line[k] = N[min];
                        // Order the rest from k to N.Length
                        for (int h = k+1; h < line.Length-1; h++)
                        {
                            min = h;
                            for (int p = h + 1; p < line.Length; p++)
                            {
                                if (line[min] > line[p]) min = p;
                            }
                            char mt = line[h];
                            line[h] = line[min];
                            line[min] = mt;
                        }
                        break;
                    }
                }
                if (found)
                {
                    N = new string(line);
                }
                else
                {
                    line = (N+"0").ToCharArray();                    
                    int min = -1;
                    for (int l = 0; l < line.Length; l++)
                    {
                        if(line[l] != '0')
                            if (min == -1 || line[l] < line[min]) min = l;
                    }
                    char tp;
                    tp = line[0];
                    line[0] = line[min];
                    line[min] = tp;

                    // Order the rest from k to 
                    for (int h = 1; h < line.Length - 1; h++)
                    {
                        min = h;
                        for (int p = h + 1; p < line.Length; p++)
                        {
                            if (line[min] > line[p]) min = p;
                        }
                        char mt = line[h];
                        line[h] = line[min];
                        line[min] = mt;
                    }

                    N = new string(line);
                }                
          
                // Output
                Tex.WriteLine("Case #{0}: {1}", i+1, N);
            }

            re.Close();
            Tex.Close();
        }
    }
}
