using System;
using System.IO;

class Solution
{
    //put any globals here
    //static string inputFilename = "test.in";
    static string inputFilename = "A-large.in";
    static string outputFilename = "large.out";
    static string workingDirectoryPath = "C:\\codejam\\2011\\R1B\\A\\";

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
        int N = int.Parse(values[0]);
        int[,] results = new int[N, N];
        decimal[] WP = new decimal[N];
        decimal[] OWP = new decimal[N];
        decimal[] OOWP = new decimal[N];
        decimal[] RPI = new decimal[N];
        int[] played = new int[N];
        int[] won = new int[N];
        for (int i = 0; i < N; i++)
        {
            line = sr.ReadLine();
            for (int j = 0; j < N; j++)
            {
                if (line.Substring(j, 1) == ".") results[i, j] = -1;
                if (line.Substring(j, 1) == "0") results[i, j] = 0;
                if (line.Substring(j, 1) == "1") results[i, j] = 1;
            }
        }
        for (int ii = 0; ii < N; ii++)
        {
            played[ii] = 0;
            won[ii] = 0;
            for (int jj = 0; jj < N; jj++)
            {
                if (results[ii, jj] > -1) played[ii]++;
                if (results[ii, jj] == 1) won[ii]++;
            }
            WP[ii] = (decimal)won[ii] / (decimal)played[ii];
        }
        for (int ii2 = 0; ii2 < N; ii2++)
        {
            decimal wptot = 0.0M;
            for (int jj2 = 0; jj2 < N; jj2++)
            {
                if (results[ii2, jj2] == 0)
                {
                    int p = played[jj2] - 1;
                    int w = won[jj2] - 1;
                    wptot = wptot + (decimal)w / (decimal)p;
                }
                if (results[ii2, jj2] == 1)
                {
                    int p = played[jj2] - 1;
                    int w = won[jj2];
                    wptot = wptot + (decimal)w / (decimal)p;
                }
            }
           OWP[ii2] = wptot/(decimal)played[ii2];

        }
        for (int ii3 =0; ii3 < N; ii3++)
        {
            decimal owptot=0.0M;
            for (int jj3 = 0; jj3 < N; jj3++)
            {
                if(results[ii3, jj3] > -1) owptot = owptot + OWP[jj3];
            }
            OOWP[ii3] = owptot/(decimal)played[ii3];

        }
        for (int k = 0; k < N; k++)
        {
            RPI[k] = 0.25M*WP[k] + 0.5M*OWP[k] + 0.25M*OOWP[k];
        }


        //write the answer to the output file
        using (StreamWriter sw = new StreamWriter(outputFile, (c!=0)))
        {
            sw.WriteLine(answer);
            for (int l = 0; l < N; l++)
            {
                sw.WriteLine(RPI[l].ToString());
            }
        }
    }

    private static void testHarness()
    {
        //do whatever's needed to test things
    }

}
                    
                    



