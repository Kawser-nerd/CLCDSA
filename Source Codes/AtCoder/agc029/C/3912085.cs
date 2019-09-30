using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;
using System.Diagnostics;
using System.Threading.Tasks;



class Myon
{
    public Myon() { }
    public static int Main()
    {
        new Myon().calc();
        return 0;
    }
    

    Scanner cin;

    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        int[] A = cin.ArrayInt(N);
        int ok = N;
        int ng = 0;
        while(ok > ng + 1)
        {
            int mid = (ok + ng) / 2;
            if (check(mid, A)) ok = mid;
            else ng = mid;
        }
        Console.WriteLine(ok);
    }

    bool check(int t, int[] A)
    {
        List<int> T = new List<int>();
        List<int> num = new List<int>();
        

        //?????a?A[0]?
        T.Add(0);
        num.Add(A[0]);

        //Print(T, num);

        for (int i = 1; i < A.Length; i++)
        {
            if (A[i] > A[i - 1])
            {
                int p = T.Count - 1;

                if (T[p] == 0) num[p] += A[i] - A[i - 1];
                else
                {
                    T.Add(0);
                    num.Add(A[i] - A[i - 1]);
                }
            }
            else
            {
                //???A[i]???????
                List<int> NT = new List<int>();
                List<int> Nnum = new List<int>();
                int Remain = A[i];
                for (int j = 0; j < T.Count; j++)
                {
                    int Add = Math.Min(Remain, num[j]);
                    if (Add == 0) break;
                    NT.Add(T[j]);
                    Nnum.Add(Add);
                    Remain -= Add;
                }
                T = NT;
                num = Nnum;

                int p = T.Count - 1;
                if(T[p] == t - 1)
                {
                    //??????????????????????
                    if (p == 0) return false;
                    else
                    {
                        T.RemoveAt(p);
                        num.RemoveAt(p);
                        p--;
                    }
                }

                //???1??????
                if (num[p] == 1)
                {
                    if (p != 0 && T[p] + 1 == T[p - 1])
                    {
                        T.RemoveAt(p);
                        num.RemoveAt(p);
                        p--;
                        num[p]++;
                    }
                    else
                    {
                        T[p]++;
                    }
                }
                else
                {
                    num[p]--;
                    T.Add(T[p] + 1);
                    num.Add(1);
                }

                //????????A????
                int Nokori = A[i];
                foreach (var item in num)
                {
                    Nokori -= item;
                }

                if(Nokori >= 1)
                {
                    T.Add(0);
                    num.Add(Nokori);
                }
            }
            //Print(T, num);
        }
        return true;
    }
    
    void Print(List<int> T, List<int> num)
    {
        string Ans = "";
        for (int i = 0; i < T.Count; i++)
        {
            Ans += new String((char)('A' + Math.Min(25, T[i])), num[i]) + "-";
        }
        Console.WriteLine(Ans);
    }
}




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
        string st = Console.ReadLine();
        while (st == "") st = Console.ReadLine();
        s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
        if (s.Length == 0) return next();
        i = 0;
        return s[i++];
    }

    public int nextInt()
    {
        return int.Parse(next());
    }
    public int[] ArrayInt(int N, int add = 0)
    {
        int[] Array = new int[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextInt() + add;
        }
        return Array;
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

    public long[] ArrayLong(int N, long add = 0)
    {
        long[] Array = new long[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextLong() + add;
        }
        return Array;
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }


    public double[] ArrayDouble(int N, double add = 0)
    {
        double[] Array = new double[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextDouble() + add;
        }
        return Array;
    }
}