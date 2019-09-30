using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;
using System.IO;

namespace q4
{
    class Program
    {

        static void Main(string[] args)
        {


            int N = 0;


            TextReader tr = new StreamReader(File.Open(@"F:\jam\q4\D-small-attempt1.in", FileMode.Open));
            TextWriter tw = new StreamWriter(File.Open(@"F:\jam\q4\output.txt", FileMode.Create));
            try
            {

                string tmp;
                tmp = tr.ReadLine();
                N = int.Parse(tmp);

                for (int i = 0; i < N; i++)
                {

                    int H, W, R;
                    tmp = tr.ReadLine();
                    string[] sts = tmp.Split(' ');

                    H = int.Parse(sts[0]);
                    W = int.Parse(sts[1]);
                    R = int.Parse(sts[2]);

                    int [,]map=new int[H+2,W+2];
                    for(int x=0;x<H+2;x++)
                    {
                        for (int y = 0; y < W + 2; y++)
                        {
                            map[x, y] = 0;
                        }
                    }
                    map[1,1]=1;
                    for(int j=0;j<R;j++)
                    {
                        int x;
                        int y;
                        tmp = tr.ReadLine();
                        sts = tmp.Split(' ');
                        x = int.Parse(sts[0]);
                        y = int.Parse(sts[1]);
                      
                            map[x, y] = -1;
                       

                    }
                    for (int x = 1; x < H ; x++)
                    {
                        for (int y = 1; y < W ; y++)
                        {
                            if (map[x, y] == -1)
                                continue;
                            int nx;
                           
                            int ny ;
                            nx = x + 2;
                            ny = y + 1;
                            if (map[nx, ny] > -1)
                            {
                                map[nx, ny] += map[x, y];
                            }

                            nx = x + 1;
                            ny = y + 2;
                            if (map[nx, ny] > -1)
                            {
                                map[nx, ny] += map[x, y];
                            }
                            if (map[nx, ny]>0)
                            {
                                map[nx, ny] = map[nx, ny] % 10007;
                            }
                        }
                    }

                    tw.WriteLine("Case #{0}: {1}",i + 1, map[H,W]);
                }

            }
            finally
            {
                tw.Close();
            }

        }

    }
}
