using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem_A
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 1)
            {
                throw new NotSupportedException();
            }
            else
            {
                // read file
                string file = args[0];
                string outFile = file.Split('.')[0] + ".out";
                StreamReader stream = new StreamReader(@file);
                StreamWriter outStream = new StreamWriter(new FileStream(@outFile, FileMode.Create))
                {
                    AutoFlush = true
                };

                int testcases = Int32.Parse(stream.ReadLine());
                for (int i = 0; i < testcases; i++)
                {
                    string input = stream.ReadLine();
                    string name = input.Split(' ')[0];
                    int l = Int32.Parse(input.Split(' ')[1]);

                    int solution = solutionMethod(name, l);
                    outStream.Write("Case #" + (i + 1) + ": ");
                    outStream.WriteLine(solution);
                }
            }
        }

        private static int solutionMethod(string name, int l)
        {
            name = name.ToLower();
            string resultName = "";
            int substrings = 0;

            string mask = "";
            for (int i = 0; i < l; i++)
			{
			    mask += '0';
			}

            for (int i = 0; i < name.Length; i++)
            {
                if (name[i] != 'a' && name[i] != 'e' && name[i] != 'i' && name[i] != 'o' && name[i] != 'u')
                {
                    resultName += '0'; // 0 = consonant
                }
                else
                {
                    resultName += '1';
                }
            }
            String test = "";
            //HashSet<String> words = new HashSet<string>();
            for (int i = 0; i < resultName.Length - l + 1; i++)
			{
                for (int j = i+l; j <= resultName.Length; j++)
                {
			        test = resultName.Substring(i, j - i);
                    if (test.Contains(mask)) 
                    {
                        substrings++;
                    }
                    //else
                    //{
                    //    break;
                    //}
			    }
			 
			}

            return substrings;
        }


        private static string doubleToString(double d)
        {
            return String.Format("{0:0.000000000000}", d).Replace(',', '.');
        }
    }
}
