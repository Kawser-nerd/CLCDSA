using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace codejam {
    class Program {

        static void Main(string[] args) {
            FileStream ofs = new FileStream("B-small.out", FileMode.Create);
            StreamWriter sw = new StreamWriter(ofs);

            using (FileStream fs = new FileStream("B-small.in", FileMode.Open)) {
                using (StreamReader sr = new StreamReader(fs)) {
                    long nTests = Int32.Parse(sr.ReadLine());

                    for (long testNo = 0; testNo < nTests; testNo++) {
                        string[] nm = sr.ReadLine().Split(new[] {' '}, StringSplitOptions.RemoveEmptyEntries);
                        long nChicks = Int32.Parse(nm[0]);
                        long nNeeded = Int32.Parse(nm[1]);
                        long distance = Int32.Parse(nm[2]);
                        long maxTime = Int32.Parse(nm[3]);

                        long[] positions = sr.ReadLine().Split(new[] {' '}, StringSplitOptions.RemoveEmptyEntries).Select(s => Int64.Parse(s)).ToArray();
                        long[] speeds = sr.ReadLine().Split(new[] {' '}, StringSplitOptions.RemoveEmptyEntries).Select(s => Int64.Parse(s)).ToArray();

                        bool[] willReach = new bool[nChicks];
                        for (long i = 0; i < nChicks; i++) {
                            willReach[i] = (speeds[i] * maxTime) >= distance - positions[i];
                        }

                        long blockers = 0;
                        long swapsNeeded = 0;
                        for (long i = nChicks-1; i >= 0; i--) {
                            if (!willReach[i]) {
                                blockers++;
                            } else {
                                if (nNeeded > 0) {
                                    nNeeded--;
                                    swapsNeeded += blockers;
                                }
                            }
                        }

                        if (nNeeded == 0) {
                            sw.WriteLine(String.Format("Case #{0}: {1}", testNo+1, swapsNeeded));
                        } else {
                            sw.WriteLine(String.Format("Case #{0}: IMPOSSIBLE", testNo+1));
                        }
                    }
                }
            }
            sw.Dispose();
            ofs.Dispose();
        }
    }
}
