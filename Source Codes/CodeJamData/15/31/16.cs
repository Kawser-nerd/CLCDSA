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
                    string[] caseBuffer = fileInputReader.ReadLine().Split(' ');
                    int r = int.Parse(caseBuffer[0]);
                    int c = int.Parse(caseBuffer[1]);
                    int w = int.Parse(caseBuffer[2]);

                    int cOverW = c / w;
                    int solution = (r - 1) * cOverW + cOverW + (w - 1) + (c % w == 0 ? 0 : 1);

                    fileOutputWriter.WriteLine(string.Format("Case #{0}: {1}", caseCounter, solution));
                }

                fileOutputWriter.Close();
                fileOutputStream.Close();

                fileInputReader.Close();
                fileInputStream.Close();
            }
        }
    }
}
