using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace codejam {
    class Program {
        const int maxN = 510;
        const long modulo = 100003;
        static long[,] nPure = new long[maxN, maxN];

        static long[,] binomial = new long[maxN, maxN];

        static long Binomial(int from, int by) {
            Debug.Assert(by >= 0);
            Debug.Assert(from >= 0);

            return binomial[from, by];
        }

        static long PureCount(int maxValue, int maxValueRank) {
            Debug.Assert(maxValueRank < maxValue);
            Debug.Assert(maxValueRank >= 1);

            if (maxValue == 2) {
                return 1;
            }

            if (maxValueRank == 1) {
                return 1;
            }

            if (maxValue == maxValueRank + 1) {
                return 1;
            }

            if (nPure[maxValue, maxValueRank] == 0) {

                long count = 0;

                for (int prevRank = 1; prevRank < maxValueRank; prevRank++) {
                    int freeSpaces = maxValue - maxValueRank - 1;
                    int valuesInFree = maxValueRank - prevRank - 1;
                    long withSuchPrev = PureCount(maxValueRank, prevRank) * Binomial(freeSpaces, valuesInFree);
                    withSuchPrev %= modulo;

                    count += withSuchPrev;
                    count %= modulo;
                }

                nPure[maxValue, maxValueRank] = count;
            }

            return nPure[maxValue, maxValueRank];
        }

        static void Main(string[] args) {
            binomial[0, 0] = binomial[1, 0] = binomial[1, 1] = 1;
            for (int from = 2; from < maxN; from++) {
                binomial[from, 0] = binomial[from, from] = 1;
                for (int by = 1; by < from; by++) {
                    binomial[from, by] = (binomial[from-1, by] + binomial[from-1, by-1]) % modulo;
                }
            }

            FileStream ofs = new FileStream("C-small.out", FileMode.Create);
            StreamWriter sw = new StreamWriter(ofs);

            using (FileStream fs = new FileStream("C-small.in", FileMode.Open)) {
                using (StreamReader sr = new StreamReader(fs)) {
                    int nTests = Int32.Parse(sr.ReadLine());

                    for (int testNo = 0; testNo < nTests; testNo++) {
                        int maxValue = Int32.Parse(sr.ReadLine());

                        long numPureSets = 0;
                        for (int maxValueRank = 1; maxValueRank < maxValue; maxValueRank++) {
                            numPureSets += PureCount(maxValue, maxValueRank);
                            numPureSets %= modulo;
                        }

                        sw.WriteLine(String.Format("Case #{0}: {1}", testNo+1, numPureSets));
                    }
                }
            }
            sw.Dispose();
            ofs.Dispose();
        }
    }
}
