using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

class Program
{
    int K, N;
    int[] need;
    int[][] keyget;
    List<int>[] lis;
    bool check(int[] init, bool[] used)
    {
        int[] q = new int[222];
        bool[] ok = new bool[222];
        int op = 0, cl = 0;
        for (int i = 1; i <= 200; i++){
            if (init[i] > 0){
                q[op++] = i;
                ok[i] = true;
            }else
                ok[i] = false;
        }
        while (cl < op)
        {
            int x = q[cl++];
            foreach (int i in lis[x])if(!used[i])
            {
                foreach (int y in keyget[i])
                {
                    if (!ok[y])
                    {
                        ok[y] = true;
                        q[op++] = y;
                    }
                }
            }
        }
        for (int i = 0; i < N; i++) if (!used[i])
                if (!ok[need[i]])
                    return false;
        int[] tmp = new int[222];
        for (int i = 1; i <= 200; i++)
            tmp[i] = init[i];
        for (int i = 0; i < N; i++)if(!used[i])
        {
            tmp[need[i]]--;
            foreach (int key in keyget[i])
                tmp[key]++;
        }
        for (int i = 1; i <= 200; i++)
            if (tmp[i] < 0)
                return false;
        return true;
    }
    void Run()
    {
        StreamReader sr = new StreamReader(@"D:\Temporary Files\Mary's HDrive\G-remain-backup\Contest 2013\GCJ\Q\d.in");
        StreamWriter so = new StreamWriter(@"D:\Temporary Files\Mary's HDrive\G-remain-backup\Contest 2013\GCJ\Q\d.out");
        int _ = Convert.ToInt32(sr.ReadLine());
        for (int t = 1; t <= _; t++)
        {
            String[] str = sr.ReadLine().Split(' ');
            K = Convert.ToInt32(str[0]);
            N = Convert.ToInt32(str[1]);
            int[] init = new int[222];
            str = sr.ReadLine().Split(' ');
            for (int i = 0; i < K; i++){
                int w = Convert.ToInt32(str[i]);
                init[w] ++;
            }
            need = new int[N];
            lis = new List<int>[222];
            for (int i = 1; i <= 200; i++)
                lis[i] = new List<int>();
            keyget = new int[N][];
            for (int i = 0; i < N; i++)
            {
                str = sr.ReadLine().Split(' ');
                need[i] = Convert.ToInt32(str[0]);
                lis[need[i]].Add(i);
                int L = Convert.ToInt32(str[1]);
                keyget[i] = new int[L];
                for (int j = 0; j < L; j++)
                    keyget[i][j] = Convert.ToInt32(str[j + 2]);
            }

            bool[] todo = new bool[N];
            so.Write("Case #{0}:", t);
            if(!check(init,todo))
                so.Write(" IMPOSSIBLE");
            else{
                for(int i=0; i<N; i++){
                    bool error = true;
                    for(int j=0; j<N; j++)if(!todo[j] && init[need[j]]>0){
                        todo [j] = true;
                        init[need[j]]--;
                        foreach (int key in keyget[j])
                        {
                            init[key]++;
                        }
                        if (check(init, todo))
                        {
                            so.Write(" " + (j + 1));
//                            Console.WriteLine(j + 1);
                            error = false;
                            break;
                        }
                        todo[j] = false;
                        init[need[j]]++;
                        foreach (int key in keyget[j])
                        {
                            init[key]--;
                        }
                    }
                    if (error)
                    {
                        Console.WriteLine("Error!");
                    }
                }
            }
            so.WriteLine("");
            Console.WriteLine(t);
        }
        so.Close();
    }
    static void Main(string[] args)
    {
        new Program().Run();
    }
}