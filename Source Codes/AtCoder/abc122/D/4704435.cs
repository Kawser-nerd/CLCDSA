using System;
using System.Collections.Generic;
using System.Linq;

class Procon
{
    public Procon() { }
    static void Main(string[] agrs)
    {
        new Procon().Do();
    }

    Scanner cin;

    int N;

    Dictionary<string, long>[] last4str;

    string[] Alphabet = new string[4] { "A", "G", "C", "T" };

    public bool Check(string key)
    {
        if (key.Contains("AGC"))
        {
            return true;
        }

        for (int i = 1; i < key.Length; i++)
        {
            char[] tmpCharArray = key.ToCharArray();
            char tmp = tmpCharArray[i];
            tmpCharArray[i] = tmpCharArray[i - 1];
            tmpCharArray[i - 1] = tmp;
            string tmpKey = new string(tmpCharArray);
            if (tmpKey.Contains("AGC"))
            {
                return true;
            }
        }
        return false;
    }

    public long Count(long i)
    {
        last4str[i] = new Dictionary<string, long>();
        if (i == 0)
        {
            last4str[i]["A"] = 1;
            last4str[i]["G"] = 1;
            last4str[i]["C"] = 1;
            last4str[i]["T"] = 1;
        }
        else
        {
            foreach (string k in last4str[i - 1].Keys)
            {
                foreach (string a in Alphabet)
                {
                    var newKey = k + a;
                    if (Check(newKey))
                    {
                        continue;
                    }
                    newKey = newKey.Substring(Math.Max(newKey.Length - 3, 0));
                    if (last4str[i].ContainsKey(newKey))
                    {
                        last4str[i][newKey] = (last4str[i][newKey] + last4str[i - 1][k]) % 1000000007;
                    }
                    else
                    {
                        last4str[i].Add(newKey, last4str[i - 1][k]);
                    }
                }
            }
        }

        long ans = 0;
        foreach (long v in last4str[i].Values)
        {
            ans = (ans + v) % 1000000007;
        }

        return ans;
    }

    public void Do()
    {
        cin = new Scanner();
        N = cin.nextInt();

        last4str = new Dictionary<string, long>[N];
        long ans = 0;
        for (int i = 0; i < N; i++)
        {
            ans = Count(i);
        }
        Console.WriteLine(ans);
    }
}

class Scanner
{
    string[] s;
    int i;
    int max_i;

    public Scanner()
    {
        s = new string[0];
        max_i = 0;
        i = 0;
    }

    public string nextString()
    {
        if (i >= s.Length)
        {
            s = Console.ReadLine().Split(' ');
            max_i = s.Length;
            i = 0;
            if (max_i == 0)
            {
                return "";
            }
            return s[i++];
        }
        else
        {
            return s[i++];
        }
    }

    public int nextInt()
    {
        return int.Parse(nextString());
    }

    public long nextLong()
    {
        return long.Parse(nextString());
    }

    public double nextDouble()
    {
        return double.Parse(nextString());
    }

    public string[] arrayString()
    {
        return Console.ReadLine().Split(' ');
    }

    public int[] arrayInt()
    {
        string[] str = Console.ReadLine().Split(' ');
        int[] array = new int[str.Length];
        for (int i = 0; i < str.Length; i++)
        {
            array[i] = int.Parse(str[i]);
        }
        return array;
    }

    public long[] arrayLong()
    {
        string[] str = Console.ReadLine().Split(' ');
        long[] array = new long[str.Length];
        for (int i = 0; i < str.Length; i++)
        {
            array[i] = long.Parse(str[i]);
        }
        return array;
    }

    public double[] arrayDouble()
    {
        string[] str = Console.ReadLine().Split(' ');
        double[] array = new double[str.Length];
        for (int i = 0; i < str.Length; i++)
        {
            array[i] = double.Parse(str[i]);
        }
        return array;
    }
}