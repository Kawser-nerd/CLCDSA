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
        static ulong gcd(ulong a, ulong b)
        {
            if (b == 0)
                return a;
            return gcd(b, a % b);
        }

        static bool IsTwoPowers(ulong a)
        {
            if (a == 0 || a == 1)
                return true;
            if (a % 2 != 0)
                return false;
            return IsTwoPowers(a / 2);
        }

        static ulong IntegerLg(ulong a)
        {
            if (a <= 1)
                return 0;
            return IntegerLg(a / 2) + 1;
        }

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
                    string[] lineTokens = fileInputReader.ReadLine().Split('/');
                    ulong p = ulong.Parse(lineTokens[0]);
                    ulong q = ulong.Parse(lineTokens[1]);

                    ulong divisor = gcd(p, q);
                    ulong pp = p / divisor;
                    ulong qq = q / divisor;

                    if (!IsTwoPowers(qq))
                    {
                        fileOutputWriter.WriteLine(string.Format("Case #{0}: impossible", caseCounter));
                        continue;
                    }

                    ulong qlg = IntegerLg(qq);
                    if (qlg > 40)
                    {
                        fileOutputWriter.WriteLine(string.Format("Case #{0}: impossible", caseCounter));
                        continue;
                    }

                    ulong plg = IntegerLg(pp);
                    fileOutputWriter.WriteLine(string.Format("Case #{0}: {1}", caseCounter, qlg - plg));
                }

                fileOutputWriter.Close();
                fileOutputStream.Close();

                fileInputReader.Close();
                fileInputStream.Close();
            }
        }
    }
}
