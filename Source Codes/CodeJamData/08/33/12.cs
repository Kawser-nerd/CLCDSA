using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace C
{
    class ProgramC
    {
        static void Main(string[] args)
        {
            StreamReader re = File.OpenText("input.txt");
            FileInfo t = new FileInfo("output.txt");
            StreamWriter Tex = t.CreateText();

            long CAS = long.Parse(re.ReadLine());
            for (long cs = 0; cs < CAS; cs++)
            {
                // Turnaround time                
                // Read the longegers 
                // n, m, X, Y and Z each separated by a space
                string[] line = re.ReadLine().Split(' ');

                int n = int.Parse(line[0]); // the length of the sequence of speed limits
                int m = int.Parse(line[1]); // the length of the generating array A
                long X = int.Parse(line[2]); 
                long Y = int.Parse(line[3]);
                long Z = int.Parse(line[4]);

                //The next m lines will contain the m elements of A, one integer per line (from A[0] to A[m-1]).

                int[] A = new int[m];
                for (int i = 0; i < m; i++) A[i] = int.Parse(re.ReadLine());

                // Using A, X, Y and Z, the following pseudocode will print the speed limit sequence in order.
                int [] Speeds = new int[n];
                long [] Counts = new long[n];
                for(int i = 0; i< n; i++){
                    Speeds[i] = A[i % m];
                    Counts[i] = 1;                    
                    A[i % m] = (int)((X * A[i % m] + Y * (i + 1)) % Z);
                }

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < i; j++)
                    {
                        if (Speeds[i] > Speeds[j])
                        {
                            Counts[i] += Counts[j]; // It creates set with each
                            Counts[i] %= 1000000007;
                        }
                    }
                    
                }

                long S = 0; //S is the number of non-empty increasing subsequences mod 1 000 000 007

                for (int i = 0; i < n; i++)
                {
                    S = (S + Counts[i]) % 1000000007;
                }

                Tex.WriteLine("Case #{0}: {1}", cs + 1, S);
            }

            re.Close();
            Tex.Close();
        }
    }
}
