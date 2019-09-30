using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC048JanKen
{
    struct Contestant
    {
        int r;
        int h;

        public int R
        {
            get { return r; }
        }

        public int H
        {
            get { return h; }
        }

        public Contestant(int r, int h)
        {
            this.r = r;
            this.h = h;
        }

    }


    class Program
    {
        const int MaxR = 100000;

        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            Contestant[] contestants = new Contestant[N];
            string[] vals;
            int[] numR = new int[MaxR+1];
            int[] numG = new int[MaxR+1];
            int[] numC = new int[MaxR+1];
            int[] numP = new int[MaxR+1];
            int[] cumR = new int[MaxR+1];

            for(int i=0; i < N; i++)
            {
                vals = Console.ReadLine().Split(' ');
                contestants[i] = new Contestant(int.Parse(vals[0]), int.Parse(vals[1]));
                numR[contestants[i].R]++;
                switch(contestants[i].H)
                {
                    case 1:
                        numG[contestants[i].R]++;
                        break;
                    case 2:
                        numC[contestants[i].R]++;
                        break;
                    case 3:
                        numP[contestants[i].R]++;
                        break;
                }
            }

            for(int r=1; r <= MaxR; r++)
            {
                cumR[r] = cumR[r - 1] + numR[r];
            }

            for(int i=0; i < N; i++)
            {
                int numWin=0, numLose=0, numDraw=0;

                switch(contestants[i].H)
                {
                    case 1:
                        numWin = cumR[contestants[i].R - 1] + numC[contestants[i].R];
                        numLose = cumR[MaxR] - cumR[contestants[i].R] + numP[contestants[i].R];
                        numDraw = numG[contestants[i].R];
                        break;

                    case 2:
                        numWin = cumR[contestants[i].R - 1] + numP[contestants[i].R];
                        numLose = cumR[MaxR] - cumR[contestants[i].R] + numG[contestants[i].R];
                        numDraw = numC[contestants[i].R];
                        break;

                    case 3:
                        numWin = cumR[contestants[i].R - 1] + numG[contestants[i].R];
                        numLose = cumR[MaxR] - cumR[contestants[i].R] + numC[contestants[i].R];
                        numDraw = numP[contestants[i].R];
                        break;
                }

                numDraw--;

                Console.WriteLine("{0} {1} {2}", numWin, numLose, numDraw);
            }

        }
    }
}