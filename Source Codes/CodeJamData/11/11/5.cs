using System;
using System.Text;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;


namespace AlienLang
{
    class Program
    {
        static void Main(string[] args)
        {

            StreamReader inFile = new StreamReader("dan.in");
            StreamWriter outFile = new StreamWriter("out.txt");
            
            int num_cases = Convert.ToInt32(inFile.ReadLine());
            Int64 n;
            int pd, pg;

            for (int c = 0; c < num_cases; c++)
            {
                string line = inFile.ReadLine();
                n = Convert.ToInt64(line.Split(' ')[0]);
                pd = Convert.ToInt32(line.Split(' ')[1]);
                pg = Convert.ToInt32(line.Split(' ')[2]);

                string possible = (IsPossible(n, pd, pg) ? "Possible" : "Broken");

                outFile.WriteLine("Case #" + (c + 1) + ": " + possible);
            }


            outFile.Flush();
            outFile.Close();
        }

        public static bool IsPossible(Int64 n, int pd, int pg)
        {
            if (pg == 100 && pd < 100)
                return false;
            if (pg == 0 && pd > 0)
                return false;

            if (n >= 100)
                return true;

            if (n >= 1 && pd%100 == 0)
                return true;
            if (n >= 2 && pd%50 == 0)
                return true;
            if (n >= 4 && pd%25 == 0)
                return true;
            if (n >= 5 && pd%20 == 0)
                return true;
            if (n >= 10 && pd%10 == 0)
                return true;
            if (n >= 20 && pd%5 == 0)
                return true;
            if (n >= 25 && pd%4 == 0)
                return true;
            if (n >= 50 && pd%2 == 0)
                return true;

            return false;
        }

    }
}
