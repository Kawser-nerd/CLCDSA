using System;
using System.Collections;
using System.IO;
public class GG
{
    int oo = 100000000;
    int[,] count;
    int L;
    int Q;
    int[] pos;
    int go(int left, int right)
    {
        if (count[left, right] != -1)
            return count[left, right];
        
        if (right == left + 1)
        {
            count[left, right] = 0;
            return 0;
        }
        if (right == left + 2)
        {
            count[left, right] = pos[right] - pos[left] - 2;
            return count[left, right];
        }

        count[left, right] = oo;
        for (int i = left + 1; i < right; i++)
        {
            count[left, right] = Math.Min(count[left, right], go(left, i) + go(i, right)+pos[right]-pos[left]-2);
        }
        return count[left, right];

    }
    public void processing()
    {
        StreamReader SR;
        StreamWriter SW;
        SR = File.OpenText("C-large.in");
        SW = File.CreateText("C.out");

        int NN = int.Parse(SR.ReadLine());

        for (int cc = 1; cc <= NN; cc++)
        {
            string[] ss = SR.ReadLine().Split();
            L = int.Parse(ss[0]);
            Q = int.Parse(ss[1]);
            ss = SR.ReadLine().Split();
            pos = new int[Q + 2];
            pos[0] = 0;
            pos[Q + 1] = L+1;
            for (int i = 1; i <= Q; i++)
                pos[i] = int.Parse(ss[i - 1]);
            count = new int[Q + 2, Q + 2];
            for (int i = 0; i < Q + 2; i++)
                for (int j = 0; j < Q + 2; j++)
                    count[i, j] = -1;
            int res = go(0, Q + 1);         

            SW.WriteLine("Case #" + cc + ": " + res);
            Console.WriteLine("Case #" + cc + ": " + res);
        }
        SR.Close();
        SW.Close();
    }
    public static void Main()
    {
        GG g = new GG();
        g.processing();
    }
}