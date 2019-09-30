using System;
using System.Collections;
using System.IO;
public class GG
{
    bool[,] isHappy;
    bool[,] check;
    const int max = 15000001;
    bool go(int n, int b)
    {
        if (isHappy[n,b])
        {
            return true;
        }
        if(!check[n, b])
        {
            check[n, b] = true;
            int r = 0;
            int x = n;
            while (x > 0)
            {
                r += (x % b) * (x % b);
                x /= b;
            }
            if (go(r, b))
            {

                isHappy[n, b] = true;
                return true;
            }
            else
            {
                isHappy[n, b] = false;
                return false;
            }
            

        }
        else
        {
            isHappy[n, b] = false;
            return false;

        }
    }
    public void compute()
    {
        for (int b = 2; b <= 10; b++)
        {
            isHappy[1, b] = true;
            check[1, b] = true;
            for (int i = 2; i < max; i++)
            {
                go(i,b);
            }
        }
    }
    public void processing()
    {
        StreamReader SR;
        StreamWriter SW;
        SR = File.OpenText("A.in");
        SW = File.CreateText("A.out");

        check = new bool[max, 11];
        isHappy = new bool[max, 11];
        int NN = int.Parse(SR.ReadLine());
        compute();
        Console.WriteLine("computing finished");



        for (int cc = 1; cc <= NN; cc++)
        {
            string[] par = SR.ReadLine().Split();
            int[] num = new int[par.Length];
            for (int i = 0; i < num.Length; i++)
                num[i] = int.Parse(par[i]);

            for (int i = 2; i < max; i++)
            {
                bool good = true;
                for (int j = 0; j < num.Length; j++)
                {
                    if (!isHappy[i, num[j]])
                    {
                        good = false;
                        break;
                    }
                }
                if (good)
                {
                    SW.WriteLine("Case #" + cc + ": "+i);
                    Console.WriteLine("Case #" + cc + ": "+i);
                    break;
                }
            }



           // SW.WriteLine("Case #" + cc + ": ");
           // Console.WriteLine("Case #" + cc + ": ");
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