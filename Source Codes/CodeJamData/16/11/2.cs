using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            using (FileStream fileInputStream = new FileStream("A-large.in", FileMode.Open, FileAccess.Read))
            using (TextReader fileInputReader = new StreamReader(fileInputStream))
            using (FileStream fileOutputStream = new FileStream("output.txt", FileMode.Create, FileAccess.Write))
            using (TextWriter fileOutputWriter = new StreamWriter(fileOutputStream))
            {
                int caseNumber = int.Parse(fileInputReader.ReadLine());

                for (int caseCounter = 1; caseCounter <= caseNumber; ++caseCounter)
                {
                    string s = fileInputReader.ReadLine().Trim();
                    int n = s.Length;
                    char[] sBuf = s.ToArray();

                    string resultString = string.Empty;
                    resultString += sBuf[0];
                    for (int i = 1; i < n; ++i)
                    {
                        if (sBuf[i] < resultString[0])
                        {
                            resultString += sBuf[i];
                        }
                        else
                        {
                            resultString = sBuf[i] + resultString;
                        }
                    }

                    fileOutputWriter.WriteLine(string.Format("Case #{0}: {1}", caseCounter, resultString));
                }

                fileOutputWriter.Close();
                fileOutputStream.Close();

                fileInputReader.Close();
                fileInputStream.Close();
            }
        }
    }
}
