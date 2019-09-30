using System;
using System.Collections.Generic;
using System.Text;

    class TriangleAreas {
        public string Process(int N, int M, int A) {
            if (N * M < A) return "IMPOSSIBLE";
            for (int x1 = 0; x1 <= N; x1++) {
                for (int y2 = 0; y2 <=M; y2++) {
                    int x1y2 = x1 * y2;
                    int target = -(A - x1y2);
                    int xmax = N;
                    if (target < 0) xmax = N - x1;
                    if (target < 0) target = -target;
                    int minfac = Math.Min(xmax, M);
                    int maxfac = Math.Max(xmax, M);
                    int fac = Math.Min(minfac, (int)Math.Sqrt(target));
                    int x2 = 0;
                    int y1 = 0;
                    while (fac >= 1 && target / fac <= maxfac) {
                        if (target % fac == 0) {
                            if (xmax <= M) {
                                x2 = fac;
                                y1 = target / fac;
                            } else {
                                y1 = fac;
                                x2 = target / fac;
                            }
                            if (xmax < N) {
                                x2 = -x2;
                                //return "blah";
                                return string.Format("{0} {1} {2} {3} {4} {5}", -x2, 0, x1 - x2, y1, 0, y2);
                            } else {
                                int area = x2 * y1 - y2 * x1;
                                
                                //return (Math.Max(x1,x2)>N).ToString() + (Math.Max(y1,y2)>M).ToString() + (area!=A) + area.ToString();
                                return string.Format("{0} {1} {2} {3} {4} {5}", 0, 0, x1 , y1, x2, y2);
                            }
                        }
                        fac--;
                    }
                }
            }
            return "IMPOSSIBLE";
        }
    }
