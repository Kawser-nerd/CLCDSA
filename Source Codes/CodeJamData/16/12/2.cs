using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            using (FileStream fileInputStream = new FileStream("B-large.in", FileMode.Open, FileAccess.Read))
            using (TextReader fileInputReader = new StreamReader(fileInputStream))
            using (FileStream fileOutputStream = new FileStream("output.txt", FileMode.Create, FileAccess.Write))
            using (TextWriter fileOutputWriter = new StreamWriter(fileOutputStream))
            {
                int caseNumber = int.Parse(fileInputReader.ReadLine());

                for (int caseCounter = 1; caseCounter <= caseNumber; ++caseCounter)
                {
                    int n = int.Parse(fileInputReader.ReadLine());
                    int[] hCount = new int[2501];
                    for (int i = 0; i < 2501; ++i)
                    {
                        hCount[i] = 0;
                    }
                    for (int i = 0; i < n * 2 - 1; ++i)
                    {
                        string[] lineBuf = fileInputReader.ReadLine().Trim().Split(' ');
                        for (int j = 0; j < n; ++j)
                        {
                            ++hCount[int.Parse(lineBuf[j])];
                        }
                    }

                    List<int> missings = new List<int>();
                    for (int i = 0; i < 2501; ++i)
                    {
                        if (hCount[i] % 2 == 1)
                        {
                            missings.Add(i);
                        }
                    }
                    
                    bool isResultFirst = true;
                    StringBuilder resultBuilder = new StringBuilder();
                    for (int i = 0; i < n; ++i)
                    {
                        if (isResultFirst)
                        {
                            isResultFirst = false;
                        }
                        else
                        {
                            resultBuilder.Append(' ');
                        }
                        resultBuilder.Append(missings[i]);
                    }
                    fileOutputWriter.WriteLine(string.Format("Case #{0}: {1}", caseCounter, resultBuilder.ToString()));
                }

                fileOutputWriter.Close();
                fileOutputStream.Close();

                fileInputReader.Close();
                fileInputStream.Close();
            }
        }
    }
}
