using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1C_1
{
    class Program
    {
        static void Main(string[] args)
        {
            var file = new StreamReader(@"C:\Users\Administrator\Documents\CodeJam\r1_1_3.txt");
            var outFile = new StreamWriter(@"C:\Users\Administrator\Documents\CodeJam\r1_1_3Out.txt");
            var total = long.Parse(file.ReadLine());

            for (long i = 1; i <= total; i++)
            {
                var lineSplit = file.ReadLine().Split('/');

                var P = long.Parse(lineSplit[0]);
                var Q = long.Parse(lineSplit[1]);

                var newP = P;
                var newQ = Q;
                while (newP % 2 == 0)
                {
                    newP /= 2;
                    if (newQ % 2 != 0)
                    {
                        newQ = 0;
                        break;
                    }
                    newQ /= 2;
                }

                
                if (newQ == 0)
                {
                    outFile.WriteLine(string.Format("Case #{0}: impossible", i));
                    continue;
                }


                
                long result = 1;
                while (newQ % 2 == 0)
                {
                    newQ /= 2;
                    result *= 2;
                }

                if (newP % newQ != 0)
                {
                    outFile.WriteLine(string.Format("Case #{0}: impossible", i));
                    continue;
                }

                newP /= newQ;
                long ancestors = 0;
                while (result > newP)
                {
                    result /= 2;
                    ancestors++;
                }

                outFile.WriteLine(string.Format("Case #{0}: {1}", i, ancestors));

            }

            file.Close();
            outFile.Close();
        }
    }
}
