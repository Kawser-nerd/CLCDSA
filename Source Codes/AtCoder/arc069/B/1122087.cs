using System;

class p
{

    //i,i+1?????i-1?????????
    static char backChar(string s,char[] temp,int i)
    {
        if (temp[i] == 'S')//i?????
        {
            if (s[i] == 'o')//???????????
                return temp[i + 1];
            else //???×????????
            {
                if (temp[i + 1] == 'S') return 'W';
                else return 'S';
            }
        }
        else //i?????
        {
            if (s[i] == 'x')//???×???????
                return temp[i + 1];
            else //????????????
            {
                if (temp[i + 1] == 'S') return 'W';
                else return 'S';
            }
        }
    }

    //i-1,i?????i+1?????????
    static char nextChar(string s,char[] temp,int i)
    {
        if (temp[i] == 'S')//i?????
        {
            if (s[i] == 'o')//???????????
                return temp[i - 1];
            else //???×????????
            {
                if (temp[i - 1] == 'S') return 'W';
                else return 'S';
            }
        }
        else //i?????
        {
            if (s[i] == 'x')//???×???????
                return temp[i - 1];
            else //????????????
            {
                if (temp[i - 1] == 'S') return 'W';
                else return 'S';
            }
        }
    }

    static void Main(string[] a)
    {
        int N = int.Parse(Console.ReadLine());
        string s = Console.ReadLine();
        //s ? o ? x ???????? N ????
        char[] t = new char[N];
        //t ??? N ? S ? W ?????????;???????-1???
        char[] temp = new char[N];
        //???????????????????????????temp
        char lastNext;
        char firstBack;
        bool flag = false;

        string[] strarray = { "SS", "SW", "WS", "WW" };

        foreach (string str in strarray)
        {
            if (flag != false) break;
            temp[0] = str[0];
            temp[1] = str[1];
            for (int i = 1; i < N - 1; i++)
            {
                temp[i + 1] = nextChar(s, temp, i);
            }
            lastNext = nextChar(s, temp, N - 1);
            firstBack = backChar(s, temp, 0);
            if (lastNext == temp[0] && firstBack == temp[N - 1])
            {
                flag = true;
                for (int i = 0; i < N; i++)
                    t[i] = temp[i];
            }
        }

        if (flag)
        {
            for (int i = 0; i < N; i++) Console.Write(t[i]);
        }
        else Console.Write("-1");
        Console.WriteLine();

    }
}