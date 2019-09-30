using System;
using System.Collections;
using System.IO;
public class G2
{
    public static void Main()
    {
        StreamReader SR;
        SR = File.OpenText("C-large.in");
        string S;
        StreamWriter SW;
        SW = File.CreateText("C.out");

        int N = int.Parse(SR.ReadLine());

        string ss = "welcome to code jam";
        for(int cc=1;cc<=N;cc++)
        {
            S = SR.ReadLine();
            int l = S.Length;
            int[,] r = new int[l, 19];
            for (int i = 18; i >= 0; i--)
            {
                for (int j = 0; j < l; j++)
                {
                    if (S[j] == ss[i])
                    {
                        if (i == 18)
                            r[j, 18] = 1;
                        else
                        {
                            for (int k = j + 1; k < l; k++)
                            {
                                r[j, i] += r[k, i + 1];
                                r[j, i] %= 10000;
                                   
                            }
                        }
                    }
                }
            }

            int res = 0;
            for (int i = 0; i < l; i++)
                res += r[i, 0];
            res %= 10000;
            res += 10000;
            string rr = Convert.ToString(res);
            rr = rr.Substring(1);
            

            

            SW.WriteLine("Case #" + cc + ": "+rr);
            Console.WriteLine("Case #" + cc + ": "+rr);
        }
        SR.Close();

        SW.Close();

    }

}