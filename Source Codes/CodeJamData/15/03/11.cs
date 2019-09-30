using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace RoundQ_C
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader infile = new StreamReader("input.txt");
            StreamWriter outfile = new StreamWriter("output.txt");
            string line = infile.ReadLine();
            int T = int.Parse(line); // case num
            for (int i = 0; i < T; i++)
            {
                line = infile.ReadLine();
                string[] lines = line.Split(' '); // total number of d
                long L = long.Parse(lines[0]);
                long X = long.Parse(lines[1]);
                string S = infile.ReadLine();
                string result = solve(L, X, S);
                outfile.WriteLine(String.Format("Case #{0}: {1}", i + 1, result));
            }
            infile.Close();
            outfile.Close();
        }

        static string solve(long L, long X, string s)
        {
            long length = X % 4;
            if (X >= 4)
                length += 4;
            Quaternion value = new Quaternion(1, "1");
            String S = s;
            for (int i = 0; i < length - 1; i++)
            {
                S += s;
            }
            for(int i=0; i<S.Length; i++)
            {
                Quaternion q = new Quaternion(1, S[i].ToString());
                value = multiply(value, q);
            }

            bool ok = value.sign == -1 && value.value == "1";
            if(ok)
            {
                Quaternion a = new Quaternion(1, "1");
                int p1 = -1;
                for(int i=0; i<S.Length; i++)
                {
                    a = multiply(a, new Quaternion(1, S[i].ToString()));
                    if(a.sign == 1 && a.value == "i")
                    {
                        p1 = i;
                        break;
                    }
                }

                Quaternion b = new Quaternion(1, "1");
                int p2 = -1;
                for(int i=S.Length-1; i>=0; i--)
                {
                    b = multiply(new Quaternion(1, S[i].ToString()), b);
                    if(b.sign == 1 && b.value == "k")
                    {
                        p2 = i;
                        break;
                    }
                }

                if(p1 != -1 && p2 != -1 && p1 < p2 + (X * L - S.Length))
                    return "YES";
            }
            return "NO";
        }

        static Quaternion multiply(Quaternion a, Quaternion b)
        {
            int s1 = a.sign;
            int s2 = b.sign;
            string v1 = a.value;
            string v2 = b.value;
            Quaternion result = new Quaternion(s1 * s2, "1");
            result.sign = s1 * s2;
            result.value = v1 + v2;
            if (v1 == "1")
                result.value = v2;
            else if (v2 == "1")
                result.value = v1;
            else if (v1 == v2)
            {
                result.sign *= -1;
                result.value = "1";
            }
            else if (v1 == "i" && v2 == "j")
                result.value = "k";
            else if (v1 == "i" && v2 == "k")
            {
                result.sign *= -1;
                result.value = "j";
            }
            else if (v1 == "j" && v2 == "i")
            {
                result.sign *= -1;
                result.value = "k";
            }
            else if (v1 == "j" && v2 == "k")
                result.value = "i";
            else if (v1 == "k" && v2 == "i")
                result.value = "j";
            else if (v1 == "k" && v2 == "j")
            {
                result.sign *= -1;
                result.value = "i";
            }
            return result;
        }
    }

    class Quaternion
    {
        public int sign;
        public string value;

        public Quaternion(int s, string v)
        {
            sign = s;
            value = v;
        }
    }
}
