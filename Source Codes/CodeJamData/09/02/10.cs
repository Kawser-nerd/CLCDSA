using System;
using System.Collections;
using System.IO;
public class G2
{
 /*
    5
3 3
9 6 3
5 9 6
3 5 9
1 10
0 1 2 3 4 5 6 7 8 7
  */
    public static void Main()
    {
       
        StreamReader SR;
        SR = File.OpenText("B-large.in");
        string S;
        StreamWriter SW;
        SW = File.CreateText("B.out");
        
        int N = int.Parse(SR.ReadLine());

        //N, W, E, S
        int[,] dir = new int[4, 2] { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };   
        for (int cc = 1; cc <= N; cc++)
        {
            string[] a = SR.ReadLine().Split();
            int A = int.Parse(a[0]);
            int B = int.Parse(a[1]);
            int[,] m = new int[A, B];
            int[,] h = new int[A,B];
             for (int i = 0; i < A; i++)
             {
                 string[] tt = SR.ReadLine().Split();
                 for(int j=0;j<B;j++)
                     h[i,j] = int.Parse(tt[j]);
             }
            for (int i = 0; i < A; i++)
                for (int j = 0; j < B; j++)
                    m[i, j] = -1;

            int index = 0;

            for (int i = 0; i < A; i++)
                for (int j = 0; j < B; j++)
                {
                    if (m[i, j] == -1)
                    {
                        

                        int ci = i;
                        int cj = j;
                        ArrayList al = new ArrayList();
                        al.Add(i * B + j);
                       
                        int v = -1;
                        while (true)
                        {
                            int height = h[ci, cj];
                            int next = -1;
                            for (int d = 0; d < 4; d++)
                            {
                                int ni = ci + dir[d, 0];
                                int nj = cj + dir[d, 1];
                                if (ni >= 0 && ni < A && nj >= 0 && nj < B && h[ni, nj] < height)
                                {
                                    height = h[ni, nj];
                                    next = d;
                                }
                            }
                            if (next == -1)
                                break;
                           
                            int nni = ci + dir[next, 0];
                            int nnj = cj + dir[next, 1];
                            if (m[nni, nnj] != -1)
                            {
                                v = m[nni, nnj];
                                break;
                            }
                            al.Add(nni * B + nnj);
                            ci = nni;
                            cj = nnj;
                        }
                        if (v == -1)
                        {
                            v = index;
                            index++;
                        }
                        for (int k = 0; k < al.Count; k++)
                        {
                            int x = (int)al[k] / B;
                            int y = (int)al[k] % B;
                            m[x, y] = v;
                        }

                    }

                }




            SW.WriteLine("Case #" + cc + ":");
            Console.WriteLine("Case #" + cc + ":");
            for(int i=0;i<A;i++)
            {    for(int j=0;j<B;j++)
                {
                    char c = (char)(m[i,j]+'a');
                    if (j == 0)
                    {
                        Console.Write(c);
                        SW.Write(c);
                    }
                    else
                    {
                        Console.Write(" " + c);
                        SW.Write(" "+c);
                    }
                }
                SW.WriteLine();
                Console.WriteLine();
            }
        }
       

   



        SR.Close();




        SW.Close();


    }

}