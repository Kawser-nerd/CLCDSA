using System;
using System.IO;

class Solution
{
    //put any globals here
    //static string inputFilename = "test.in";
    static string inputFilename = "B-large.in";
    static string outputFilename = "large.out";
    static string workingDirectoryPath = "C:\\codejam\\2011\\R1B\\B\\";

    static string inputFile = workingDirectoryPath + inputFilename;
    static string outputFile = workingDirectoryPath + outputFilename;
    static StreamReader sr = new StreamReader(inputFile);

    public static void Main()
    {
        //call testHarness if required
        //testHarness();
        //reads one-time information from input file, especially number of test cases
        string line;
        line = sr.ReadLine();
        string[] values = line.Split(' ');
        int cases = int.Parse(values[0]);
        for (int c = 0; c < cases; c++)
        {
            //loop over all the cases
            runCase(c);
        }
    }

    private static void runCase(int c)
    {
        string answer = "Case #" + (c + 1).ToString() + ": ";

        //read input for this particular case
        string line;
        line = sr.ReadLine();
        string[] values = line.Split(' ');
        int C = int.Parse(values[0]);
        int D = int.Parse(values[1]);
        decimal dist = (decimal) D;
        int[] PP = new int[C];
        int[] VV = new int[C];
        int V = 0;
        for (int i = 0; i < C; i++)
        {
            line = sr.ReadLine();
            values = line.Split();
            
            PP[i] = int.Parse(values[0]);
            VV[i] = int.Parse(values[1]);
            V = V + VV[i];
 
        }
        int [] P = new int[V];
        int index = 0;
        for (int j = 0; j < C; j++)
        {
            for (int k = 0; k < VV[j]; k++)
            {
                P[index] = PP[j];
                index++;
            }
        }

        decimal lowguess = 0.0M;
        decimal highguess = 10000000000000000000000M; 
        decimal smallestvalue = 0.0000000001M;

        //do some stuff to solve the problem

        while (highguess - lowguess > smallestvalue)
        {
            int ok = 1;
            decimal time = (highguess + lowguess) /(decimal) 2.0;
            decimal mostleft = P[0] - time;
            for (int i = 1; i < V; i++)
            {
                if (P[i] + time < mostleft + dist) ok = 0;
                mostleft = Math.Max(mostleft+dist, P[i] - time);

            }
            if (ok == 1)
            {
                highguess = time;
            }
            else
            {
                lowguess = time;
            }
        }
        
        decimal rounded = Math.Round((highguess + lowguess) / (decimal)2.0, 9);
        answer = answer + rounded.ToString();

        //write the answer to the output file
        using (StreamWriter sw = new StreamWriter(outputFile, (c!=0)))
        {
            sw.WriteLine(answer);
        }
    }

    private static void testHarness()
    {
        //do whatever's needed to test things
    }

}
                    
                    



