using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC021B {
    class Program {
        static void Main(string[] args) {
            int N = int.Parse(Console.ReadLine());
            int num = 50000;
            //double[] max = new double[num];
            //double[] min = new double[num];
            double[] max = Enumerable.Repeat(-100000000.0, num).ToArray();
            double[] min = Enumerable.Repeat(100000000.0, num).ToArray();
            int[] maxNum = new int[num];
            int[] minNum = new int[num];
            double[] stdx = new double[num];
            double[] stdy = new double[num];
            int l = 0;
            for(int i = 0; i < num; i++) {
                stdx[i] = Math.Cos(i / (double)num * Math.PI);
                stdy[i] = Math.Sin(i / (double)num * Math.PI);
            }
            int[] xs = new int[N];
            int[] ys = new int[N];
            for(int i = 0;i < N; i++) {
                int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                xs[i] = input[0];
                ys[i] = input[1];
            }
            for(int i = 0; i < N; i++) {
                for (int j = 0;j < num; j++) {
                    double p = xs[i] * stdx[j] + ys[i] * stdy[j];
                    if(p < min[j]) {
                        min[j] = p;
                        minNum[j] = i;
                    } else if(p == min[j]) {
                        int k = minNum[j];
                        double dis1 = Math.Pow(xs[i], 2) + Math.Pow(ys[i], 2);
                        double dis2 = Math.Pow(xs[k], 2) + Math.Pow(ys[k], 2);
                        if(dis1 < dis2) {
                            minNum[j] = i;
                        }
                    }
                    if(p > max[j]) {
                        max[j] = p;
                        maxNum[j] = i;
                    } else if (p == max[j]) {
                        int k = maxNum[j];
                        double dis1 = Math.Pow(xs[i], 2) + Math.Pow(ys[i], 2);
                        double dis2 = Math.Pow(xs[k], 2) + Math.Pow(ys[k], 2);
                        if (dis1 < dis2) {
                            maxNum[j] = i;
                        }
                    }
                }
            }
            double[] P = new double[N];
            for(int i = 0; i < num; i++) {
                P[maxNum[i]]++;
                P[minNum[i]]++;
            }
            for(int i = 0; i < N; i++) {
                P[i] = P[i] / (num * 2);
                Console.WriteLine(P[i]);
            }
        }
    }
}