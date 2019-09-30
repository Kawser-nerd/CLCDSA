using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace ConsoleApplication1
{
    class Go
    {
        public string whatsNext(string t)
        {
            for (int i = t.Length - 1; i != 0; i--)
            {
                if (t[i] > t[i - 1])
                {
                    int x=i;
                    int min=t[x];
                    for (int j = i; j < t.Length; j++)
                    {
                        if (t[j] > t[i - 1] && t[j] < min)
                        {
                            min = t[j];
                            x = j;
                        }
                    }
                    char[] ret = t.ToCharArray();
                    char tmp=ret[i-1];
                    ret[i-1] = ret[x];
                    ret[x] = tmp;

                    ArrayList rem = new ArrayList();
                    for (int j = i; j < t.Length; j++)
                    {
                        rem.Add(ret[j]);
                    }
                    rem.Sort();
                    for (int j = i; j < t.Length; j++)
                    {
                        ret[j] = (char)rem[j - i];
                    }

                    return new string(ret);
                }
            }

            ArrayList al=new ArrayList(t.ToCharArray());
            al.Sort();
            string nv = new string((char[])al.ToArray(typeof(char)));
            nv=nv.Substring(0, 1) + "0" + nv.Substring(1);

            char[] data = nv.ToCharArray();
            if (data[0] == '0')
            {
                for (int i = 0; i < data.Length; i++)
                {
                    if (data[i] > '0')
                    {
                        data[0] = data[i];
                        data[i] = '0';
                        break;
                    }
                }
            }
            return new string(data);
        }

        public void process(string fileName)
        {
            StreamReader f = File.OpenText(fileName);
            StreamWriter fo = File.CreateText(fileName + ".result.txt");

            int n = int.Parse(f.ReadLine());

            for (int i = 0; i < n; i++)
            {
                string number = f.ReadLine();

                string nextNumber = whatsNext(number);

                fo.WriteLine("Case #" + (i + 1).ToString() + ": " + nextNumber);
            }

            f.Close();
            fo.Close();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Go go = new Go();
            go.process("c:\\projects\\CodeJam2009\\B-large.in");
        }
    }
}
