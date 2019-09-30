using System;
using System.Collections.Generic;
using System.Text;

namespace Google {
    class SMS {

        static void Main(string[] args) {
            long NN = Int64.Parse(Console.ReadLine());
            for (long cs = 1; cs <= NN; cs++) {
                string line = Console.ReadLine();
                string[] data = line.Split(' ');

                long P = Int64.Parse(data[0]);
                long K = Int64.Parse(data[1]);
                long L = Int64.Parse(data[2]);

                line = Console.ReadLine();
                data = line.Split(' ');

                List<long> freq = new List<long>();

                for (int i = 0; i < L; i++) freq.Add(Int64.Parse(data[i]));

                freq.Sort();

                long result = 0;
                int index = freq.Count - 1;
                for (long i = 1; i <= P; i++) {
                    for (long j = 1; j <= K; j++) {
                        while (index >= 0 && freq[index] == 0) index--;
                        if (index < 0) break;
                       
                        result += freq[index] * i;
                        index--;
                    }
                }

                Console.WriteLine("Case #" + cs.ToString() + ": " +result.ToString());




            }
        }

    }
}