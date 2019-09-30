using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;


namespace ConsoleApplication1
{
    class Class1
    {
        StreamReader sr;
        StreamWriter sw;

        public Class1(string infile, string outfile)
        {
            sr = new StreamReader(infile);
            sw = new StreamWriter(outfile);
        }
        /*
         Sample Input:
         * 
            4
            quartz 3
            straight 3
            gcj 2
            tsetse 2
         */
        public bool isConsonant(char c)
        {
            return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
        }
        public void Execute()
        {
            Int64 NumCases = Int64.Parse(sr.ReadLine());
            for (Int64 k = 0; k < NumCases; k++)
            {
                Int64 successCount = 0;
                string line = sr.ReadLine();

                string name = line.Split(' ')[0];
                Int64 nameLength = name.Length;
                Int64 n = Int64.Parse(line.Split(' ')[1]);
                List<Int64> nStringIndexes = new List<Int64>();
                
          //      Console.WriteLine(String.Format("Name = {0}, Length = {1}, n = {2}", name, nameLength, n));

                //first, find all substrings with at least n consecutive consonants. 
                Int64 currentConsLength = 0;
                for (Int64 i = 0; i < nameLength; i++)
                {
                    if (isConsonant(name[(int)i]))
                    {
                        currentConsLength++;
                    }
                    else
                    {
                        currentConsLength = 0;
                    }
                    if (currentConsLength >= n)
                    {
                        nStringIndexes.Add(i + 1 - n);    
                    }
                }
            /*    foreach (Int64 index in nStringIndexes)
                {
                    Console.WriteLine(String.Format("Found Index = {0}", index));
                }
                */
                for (Int64 i = 0; i < nStringIndexes.Count; i++)
                { 
                    //only count if this is a duplicate string, only count it for the first index
                    Int64 index = nStringIndexes.ElementAt((int)i);
                    Int64 prevIndex = -1;
                    if(i > 0)
                    {
                        prevIndex = nStringIndexes.ElementAt((int)(i - 1));
                    }
                    Int64 val1 = index - prevIndex;
                    Int64 val2 = nameLength - index - n + 1;
             //       Console.WriteLine(String.Format("adding {0} * {1} to success count", val1, val2));
                    successCount += val1 * val2;
                }

                sw.WriteLine(String.Format("Case #{0}: {1}", k + 1, successCount));
            }


            sw.Close();
            sr.Close();
        }
    }
}
