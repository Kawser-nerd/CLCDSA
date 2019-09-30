using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Round1CA
{
    class Program
    {
        static void Main(string[] args)
        {
            //Console.Write(new Program().attempt("zjvieiwadioiipiysibecujbqamfoagvaoveioubiicseuuvomcellwekokfwowsjokgzddrwoowiiecueqjw", 4));
            new Program().solve();
            Console.ReadLine();
        }


        long solvebadly2(string s, long n)
        {
            long value = 0;
            for (int i = 0; i < s.Length; i++)
            {
                for (int j = i+1; j < s.Length; j++)
                {
                    int count = 0;
                    for (int k = i; k <=j; k++)
                    {
                        char c = s.ToCharArray(k, 1)[0];
                        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                        {
                            count = 0;
                        }
                        else
                        {
                            count++;
                            if (count == n)
                            {
                                value += 1;
                                break;
                            }
                        }
                    }
                }
            }
            return value;
        }

        long solvebadly(string s, long n)
        {
            int count = 0;
            long value = 0;
            for (int i = 0; i < s.Length; i++)
            {
                char c = s.ToCharArray(i,1)[0];
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                {
                    count = 0;
                }
                else
                {
                    count++;
                    if (count == n)
                    {
                        value = 1;
                        break;
                    }
                }
            }
            if (s.Length > n)
            {
                value += solvebadly(s.Substring(1), n);
                value += solvebadly(s.Substring(0,s.Length-1), n);
            }
            return value;
        }

        long attempt(string s, long n)
        {
            List<long> cases = new List<long>();
            int current = -1;
            bool constantent = false;
            bool firstconst = false;
            foreach (char c in s)
            {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                {
                    if(current==-1){
                        current = 1;
                        constantent = false;
                        firstconst = false;
                    } else {
                        if (constantent)
                        {
                            //Console.Write(current + ",");
                            cases.Add(current);
                            current = 1;
                            constantent = false;
                        }
                        else
                        {
                            current++;
                        }
                    }
                }
                else
                {
                    if (current == -1)
                    {
                        current = 1;
                        constantent = true;
                        firstconst = true;
                    }
                    else
                    {
                        if (!constantent)
                        {
                            //Console.Write(current + ",");
                            cases.Add(current);
                            current = 1;
                            constantent = true;
                        }
                        else
                        {
                            current++;
                        }
                    }
                }
            }
            if (current > 0)
            {
                //Console.Write(current + ",");
                cases.Add(current);
            }
            //Console.WriteLine();
            long[] cases2 = cases.ToArray();
            /*for (int j = 0; j < cases2.Length; j++)
            {
                Console.Write(cases2[j] + ",");
            }*/
            //Console.WriteLine();
            int i = 0;
            if (!firstconst) i=1;
            long lastcase = 0;
            int lastnum = -1;
            long value = 0;
            int count = 0;
            for (; i < cases2.Length; i=i+2)
            {
                if (cases2[i]>=n)
                {
                    long pre = sumpre(cases2,i)+1;
                    if (lastnum != -1)
                    {
                        pre = sumpre(cases2, i, lastnum) + n;
                    }
                    lastnum = i;
                    //pre = pre - lastcase;
                    //lastcase = pre + lastcase;
                    long post = sumpost(cases2,i)+1;
                    long prepost = pre * post;
                    long subcases = cases2[i]-n;
                    long a = cases2[i] - 2-n+1;
                    long add = 0;
                    if (a > 0)
                    {
                        add = a * (a + 1) / 2;
                    }
                    //long add = Math.Max(0,cases2[i]-n-n);
                    value += prepost + pre * subcases + post * subcases + add;
                    //Console.WriteLine(pre + "*" + post + "+" + pre + "*" + subcases + "+" + post + "*" + subcases +"+"+add+ "=" + (prepost + pre * subcases + post * subcases + add));
                    //lastcase = i;
                    count++;
                }
            }
            return value;// +count * 10000000000000;
        }


        string Ask(string question)
        {
            Console.WriteLine(question);
            return Console.ReadLine();
        }

        void printToFile(List<String> lines, string filename)
        {
            using (StreamWriter file =
            new StreamWriter(filename))
            {
                foreach (string line in lines)
                {
                    file.WriteLine(line);
                    //Console.WriteLine(line);
                }
            }
        }

        void solve()
        {
            string filename = Ask("Filename??");
            string[] lines = readFile(filename + ".in");
            List<string> results = new List<string>();
            int numberOfCases = Int32.Parse(lines[0]);
            for (int i = 0; i < numberOfCases; i++)//For each case
            {
                string[] dataline1 = lines[i + 1].Split(' ');
                long answer = attempt(dataline1[0], Int64.Parse(dataline1[1]));
                //long answer = solvebadly2(dataline1[0], Int64.Parse(dataline1[1]));
                results.Add("Case #" + (i + 1) + ": " + answer);
                Console.WriteLine("Case #" + (i + 1) + ": " + answer);
            }
            printToFile(results, filename + ".out");
        }

        string[] readFile(string filename)
        {
            return System.IO.File.ReadAllLines(filename);
        }

        long sumpre(long[] array, int index)
        {
            long result = 0;
            for (int i = 0; i < index; i++)
            {
                result += array[i];
            }
            return result;
        }

        long sumpre(long[] array, int index, int start)
        {
            long result = 0;
            for (int i = start+1; i < index; i++)
            {
                result += array[i];
            }
            return result;
        }

        long sumpost(long[] array, int index)
        {
            long result = 0;
            for (int i = index+1; i < array.Length; i++)
            {
                result += array[i];
            }
            return result;
        }
    }
}
