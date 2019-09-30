using System;
using System.Collections.Generic;


class Scanner
{
    string[] s;
    int i;

    char[] cs = new char[] { ' ' };

    public Scanner()
    {
        s = new string[0];
        i = 0;
    }

    public string next()
    {
        if (i < s.Length) return s[i++];
        s = Console.ReadLine().Split(cs, StringSplitOptions.RemoveEmptyEntries);
        i = 0;
        return s[i++];
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }

    public int nextInt()
    {
        return int.Parse(next());
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

}


class Myon
{
    Scanner cin;
    Random rnd;
    Myon() { }

    public static void Main()
    {
        new Myon().multi();
    }

    void multi()
    {
        int c;
        cin = new Scanner();
        rnd = new Random();
        init();
        int T = cin.nextInt();
        for (c = 1; c <= T; c++)
        {
            Console.Write("Case #{0}: ", c);
            calc();
        }
    }

    long[] P, S;
    Dictionary<char, char> dic = new Dictionary<char, char>();
    Dictionary<char, char> uni;
    void calc()
    {
        int K = cin.nextInt();
        string S = cin.next();
        Dictionary<string, int> dic = new Dictionary<string, int>();

        for (int i = 1; i < S.Length; i++)
        {
            string[] add = getst(S[i - 1] + "" + S[i]);
            foreach (var item in add)
            {
                dic[item] = 0;
            }
        }
        Dictionary<char, int> input = new Dictionary<char, int>();
        Dictionary<char, int> output = new Dictionary<char, int>();
        uni = new Dictionary<char, char>();
        for (int i = 0; i < 26; i++)
        {
            input[(char)('a' + i)] = 0;
            output[(char)('a' + i)] = 0;
            uni[(char)('a' + i)] ='!';
        }
        for (int i = 0; i < 10; i++)
        {
            input[(char)('0' + i)] = 0;
            output[(char)('0' + i)] = 0;
            uni[(char)('0' + i)] = '!';
        }
        foreach (var item in dic.Keys)
        {
            //Console.WriteLine(item);
            input[item[0]]++;
            output[item[1]]++;
            connect(item[0], item[1]);
        }
        int group = 0;
        int ret = 0;
        Dictionary<char, int> retd = new Dictionary<char, int>();
        for (int i = 0; i < 26; i++)
        {
            char next = (char)('a' + i);
            if ((input[next] != 0 || output[next] != 0) && uni[next] == '!') group++;
            retd[next] = 0;
        }
        for (int i = 0; i < 10; i++)
        {
            char next = (char)('0' + i);
            if ((input[next] != 0 || output[next] != 0) && uni[next] == '!') group++;
            retd[next] = 0;
        }

        for (int i = 0; i < 26; i++)
        {
            char next = (char)('a' + i);
            char un = getuni(next);
            retd[un] += Math.Max(0, output[next] - input[next]);
        }
        for (int i = 0; i < 10; i++)
        {
            char next = (char)('0' + i);
            char un = getuni(next);
            retd[un] += Math.Max(0, output[next] - input[next]);
        }
        foreach (var item in retd.Values)
        {
            ret += Math.Max(0, item - 1);
        }
        //ret /= 2;
        ret += group + dic.Count;
        Console.WriteLine(ret);
    }


    char getuni(char c)
    {
        if (uni[c] == '!') return c;
        else return uni[c] = getuni(uni[c]);
    }

    bool connect(char a, char b)
    {
        a = getuni(a);
        b = getuni(b);
        if (a != b)
        {
            uni[b] = a;
            return true;
        }
        return false;
    }

    string[] getst(string s)
    {
        List<char> a = new List<char>();
        List<char> b = new List<char>();
        a.Add(s[0]); if (dic.ContainsKey(s[0])) a.Add(dic[s[0]]);
        b.Add(s[1]); if (dic.ContainsKey(s[1])) b.Add(dic[s[1]]);
        List<string> ret = new List<string>();
        foreach (var s1 in a)
        {
            foreach (var s2 in b)
            {
                ret.Add(s1 + "" + s2);
            }
        }
        return ret.ToArray();
    }

    void init()
    {
        string[] nums = new string[] { "o", "0", "i", "1", "e", "3", "a", "4", "s", "5", "t", "7", "b", "8", "g", "9" };
        for (int i = 0; i < nums.Length; i+=2)
        {
            dic[nums[i][0]] = nums[i + 1][0];
        }
    }
    

}
