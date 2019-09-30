using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace gcj
{
    class Program
    {
        static void Main(string[] args)
        {
            System.IO.StreamReader sr = new System.IO.StreamReader(@"D:\other\gcj\B-large.in");
            System.IO.StreamWriter sw = new System.IO.StreamWriter(@"D:\other\gcj\ans.txt");

            string tmp = sr.ReadLine();
            int cas = Int32.Parse(tmp);

            for (int i = 0; i < cas; i++)
            {
                int n;
                tmp = sr.ReadLine();
                n = Int32.Parse(tmp);
                int j;
                int[] a = new int[n];
                int[] b = new int[n];
                int[] mark = new int[n];
                for (j = 0; j < n; j++)
                {
                    tmp = sr.ReadLine();
                    string[] arr = tmp.Split(' ');
                    a[j] = int.Parse(arr[0]);
                    b[j] = int.Parse(arr[1]);
                    mark[j]=0;
                }

                int now = 0;
                int score = 0;
                
                while (true) {
                    bool dd = false;
                    for (j = 0; j < n; j++) {
                        if (mark[j] < 2 && b[j]<=score)
                        { 
                            dd = true;
                            score += 2 - mark[j];
                            now++;
                            mark[j] = 2;
                        }
                    }

                    
                    int k = -1;
                    if (dd == false)
                    {
                        for (j = 0; j < n; j++)
                        {
                            if (mark[j] == 0 && a[j] <= score)
                            {
                                if (k == -1)
                                {
                                    k = j;
                                }
                                else {
                                    if (b[j] > b[k]) {
                                        k = j;
                                    }
                                }
                                
                            }
                        }
                        if (k != -1)
                        {
                            dd = true;
                            mark[k] = 1;
                            score++;
                            now++;
                           
                        }
                    }
                    if (dd == false)
                        break;
                }
                string o;
                if (score != 2 * n)
                    o = "Too Bad";
                else o = now.ToString();
                sw.WriteLine("Case #{0}: {1}", i + 1, o);
            }

            sr.Close();
            sw.Close();
        }
    }
}
