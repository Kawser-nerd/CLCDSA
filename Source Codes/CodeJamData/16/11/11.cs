using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace RoundOne
{
    public class A
    {
        public static void Run()
        {
            var number = 0;
            using (var sr = new StreamReader("A-large (1).in"))
            {
                using (var sw = new StreamWriter("output.txt"))
                {
                    while (!sr.EndOfStream)
                    {
                        var line = sr.ReadLine();
                        if (number == 0) number = int.Parse(line);
                        for (var c = 1; c <= number; c++)
                        {
                            line = sr.ReadLine();
                            string ans = line[0].ToString();
                            char start = line[0], end = line[0];
                            for (var i = 1; i < line.Length; i++)
                            {
                                if ((int)start <= (int)line[i])
                                {
                                    ans = line[i].ToString() + ans;
                                    start = line[i];
                                }
                                else {
                                    end = line[i];
                                    ans = ans + line[i].ToString();
                                }
                            }

                                sw.WriteLine(string.Format("Case #{0}: {1}", c, ans));
                        }
                    }
                }
            }
        }
    }
}
