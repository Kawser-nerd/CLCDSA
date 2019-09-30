using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class Program
    {
        public static string Multiply(string a, string b)
        {
            string result = "0";
            string zeros = "";

            for (int i = b.Length - 1; i >= 0; i--)
            {
                int carrier = 0;
                int m1 = b[i] - '0';
                string r1 = "", r2 = "";

                for (int j = a.Length - 1; j >= 0; j--)
                {
                    carrier = carrier + m1 * (a[j] - '0');
                    r1 = (carrier % 10).ToString() + r1;

                    carrier = carrier / 10;
                }

                if (carrier != 0)
                {
                    r1 = carrier.ToString() + r1;
                }

                r1 = r1 + zeros;

                carrier = 0;

                for (int j = r1.Length - 1, jj = result.Length - 1; j >= 0 || jj >= 0; j--, jj--)
                {
                    if (j >= 0 && j < r1.Length)
                    {
                        carrier += (r1[j] - '0');
                    }

                    if (jj >= 0 && jj < result.Length)
                    {
                        carrier += (result[jj] - '0');
                    }

                    r2 = (carrier % 10).ToString() + r2;

                    carrier = carrier / 10;
                }

                if (carrier != 0)
                {
                    result = carrier.ToString();
                }
                else
                {
                    result = "";
                }

                result = result + r2;

                zeros += "0";
            }

            return result;
        }

        /// <summary>
        /// Compares the specified strings as numbers.
        /// </summary>
        /// <param name="str">The strings as numbers.</param>
        /// <returns></returns>
        public static int Compare(string str1, string str2)
        {
            if (str1.Length < str2.Length)
            {
                return -1;
            }
            else if (str1.Length > str2.Length)
            {
                return 1;
            }

            for (int i = 0; i < str1.Length; i++)
            {
                if (str1[i] < str2[i])
                {
                    return -1;
                }
                else if (str1[i] > str2[i])
                {
                    return 1;
                }
            }

            return 0;
        }

        /// <summary>
        /// Reverses the specified string.
        /// </summary>
        /// <param name="str">The string to reverse.</param>
        /// <returns></returns>
        static string Reverse(string str)
        {
            string reversed = "";

            for (int i = str.Length - 1; i >= 0; i--)
            {
                reversed += str[i].ToString();
            }

            return reversed;
        }

        /// <summary>
        /// Doubles to string.
        /// </summary>
        /// <param name="d">The d.</param>
        /// <returns></returns>
        static string DoubleToString(double d)
        {
            string str = d.ToString();
            var converted = new StringBuilder();

            for (int i = 0; i < str.Length; i++)
            {
                if (str[i] == '.')
                {
                    break;
                }

                converted.Append(str[i].ToString());
            }

            return converted.ToString();
        }

        /// <summary>
        /// Toes the binary.
        /// </summary>
        /// <param name="value">The value.</param>
        /// <param name="length">The length.</param>
        /// <returns></returns>
        static string ToBinary(int value, int length)
        {
            string result = "";

            if (length == 0)
            {
                return result;
            }

            for (int i = 0, j = 1; i < length; i++, j <<= 1)
            {
                if ((value & j) != 0)
                {
                    result = "1" + result;
                }
                else
                {
                    result = "0" + result;
                }
            }

            return result;
        }

        static void Main(string[] args)
        {
            var p = new List<string>();

            p.Add("1");
            p.Add("4");
            p.Add("9");
            p.Add("121");
            p.Add("484");

            //p.Add("10201");
            //p.Add("12321");
            //p.Add("14641");
            //p.Add("40804");
            //p.Add("44944");

            int length = 3;
            // double AA = Math.Pow(10, 100);
            string AA = "1";

            for (int i = 0; i < 100; i++)
            {
                AA += "0";
            }

            while (true)
            {
                DateTime start = DateTime.Now;

                //double prefix = Math.Pow(10, length / 2 - 1);
                //double border = Math.Pow(10, length / 2);
                int prefix = 0;
                int border = (1 << (length / 2 - 1));

                bool stop = false;
                //Console.WriteLine("-------------------------");

                for (; prefix <= border; prefix++)
                //for (; prefix < border; prefix++)
                {
                    string pre = "1" + ToBinary(prefix, length / 2 - 1);

                    if (prefix == border)
                    {
                        pre = "2" + ToBinary(prefix, length / 2 - 1);
                    }

                    if (pre.StartsWith("1111") && pre.Length > 4 && pre[pre.Length - 1] == '1')
                    {
                        prefix = border;
                        pre = "2" + ToBinary(prefix, length / 2 - 1);
                    }

                    if (pre.Replace("0", "").Length > 4)
                    {
                        continue;
                    }
                    //Console.WriteLine(pre);
                //    //string pre = DoubleToString(prefix);
                    string suf = Reverse(pre);

                    // even)
                    if (length % 2 == 0)
                    {
                        string square = Multiply(pre + suf, pre + suf);

                        if (Compare(square, AA) == 1)
                        {
                            stop = true;
                            break;
                        }

                        if (square == Reverse(square))
                        {
                            p.Add(square);
                        }
                    }
                    else
                    {
                        for (int i = 0; i < 3; i++)
                        {
                            string square = Multiply(pre + i.ToString() + suf, pre + i.ToString() + suf);

                            if (Compare(square, AA) == 1)
                            {
                                stop = true;
                                break;
                            }

                            if (square == Reverse(square))
                            {
                                p.Add(square);
                            }
                        }
                    }

                    if (stop) break;
                }

                if (stop) break;

                Console.WriteLine("l: {0} calculated: {1}", length, DateTime.Now - start);
                length++;
            }

            string[] lines = File.ReadAllLines(@"C-large2.in");
            int cases = Int32.Parse(lines[0]);
            var sb = new StringBuilder();

            for (int c = 0; c < cases; c++)
            {
                var str = lines[c + 1].Split(new char[] { ' ' });
                long count = 0;

                for (int i = 0; i < p.Count; i++)
                {
                    if (Compare(p[i], str[0]) >= 0 && Compare(p[i], str[1]) <= 0)
                    {
                        count++;
                    }

                    if (Compare(p[i], str[1]) > 0)
                    {
                        break;
                    }
                }

                string str1 = String.Format("Case #{0}: {1}", c + 1, count);
                Console.WriteLine(str1);

                sb.AppendLine(str1);
            }

            string result = sb.ToString();
            Console.ReadLine();
        }
    }
}