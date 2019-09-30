using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace A
{
    class ProgramA
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
                string[] line = re.ReadLine().Split(' ');
                // On the first line we have the maximum number 
                // of letters to place on a key (P), the number 
                // of keys available (K) and the number of letters 
                // in our alphabet (L) all separated by single spaces.

                int P = int.Parse(line[0]); // the maximum number of letters to place on a key
                int K = int.Parse(line[1]); // the number of keys available 
                int L = int.Parse(line[2]); // the number of letters in our alphabet 

                // Read the longegers 
                line = re.ReadLine().Split(' '); 
                // The second line has L non-negative integers.
                // Each number represents the frequency of a certain letter.
                int[] FR = new int[L];
                for (int i = 0; i < L; i++) FR[i] = int.Parse(line[i]);



                //indicating the number of keypad presses to type the message for the optimal layout
                long count = 0;

                // If there is no possible solution, print "Impossible" instead of the number of keypad presses. 

                // Sort freqs
                int max, temp;

                for (int k = 0; k < L - 1; k++)
                {
                    max = k;

                    for (int j = k + 1; j < L; j++)
                    {
                        if (FR[j] > FR[max])
                        {
                            max = j;
                        }
                    }

                    temp = FR[k];
                    FR[k] = FR[max];
                    FR[max] = temp;
                }

                int level = 1;
                int levelAvail = K;
                bool impossible = false;
                for (int i = 0; i < L; i++)
                {
                    if(level > P){
                        impossible = true;
                        break;
                    }
                    count += level * FR[i];
                    levelAvail--;
                    if (levelAvail == 0)
                    {
                        level++;
                        levelAvail = K;                        
                    }
                }

                if(impossible)
                    Tex.WriteLine("Case #{0}: Impossible", cs + 1);
                else
                    Tex.WriteLine("Case #{0}: {1}", cs + 1, count);
            }

            re.Close();
            Tex.Close();
        }
    }
}
