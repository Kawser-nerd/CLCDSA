using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1_3 {
    class Program {
        Program() {
            Console.ReadLine(); Console.WriteLine("Case #1:");
            int[] RNMK = Console.ReadLine().Split().Select(t => int.Parse(t)).ToArray();
            for (int i = 0; i < RNMK[0]; ++i) {
                BigInteger[] prods = Console.ReadLine().Split().Select(t => new BigInteger(t, 10)).ToArray();
                int count2 = 0, count3 = 0, count5 = 0;
                for (int j=0; j<RNMK[3]; ++j) {
                    while (prods[j] % 2 == 0) { prods[j] /= 2; ++count2; }
                    while (prods[j] % 3 == 0) { prods[j] /= 3; ++count3; }
                    while (prods[j] % 5 == 0) { prods[j] /= 5; ++count5; }
                }
                double n3 = (double)(2 * count3) / RNMK[3];
                double n5 = (double)(2 * count5) / RNMK[3];
                double e2 = (double)(2 * count2) / RNMK[3];
                double n4 = e2 + n3 + n5 - RNMK[1];
                if (n4 < 0) n4 = 0;
                double n2 = RNMK[1] - n3 - n5 - n4;
                if (n2 < 0) n2 = 0;
                int nn2 = (int)(n2 + 0.5);
                int nn3 = (int)(n3 + 0.5);
                int nn4 = (int)(n4 + 0.5);
                int nn5 = (int)(n5 + 0.5);
                while (nn2 + nn3 + nn4 + nn5 < RNMK[1]) {
                    nn2+=RNMK[1]-(nn2 + nn3 + nn4 + nn5);
                }
                while (nn2 + nn3 + nn4 + nn5 > RNMK[1]) {
                    if (nn2 > 0) --nn2;
                    else if (nn3 > 0) --nn3;
                    else if (nn4 > 0) --nn4;
                    else if (nn5 > 0) --nn5;
                }
                string solnstr = "";
                for (int k = 0; k < nn2; ++k) solnstr += "2";
                for (int k = 0; k < nn3; ++k) solnstr += "3";
                for (int k = 0; k < nn4; ++k) solnstr += "4";
                for (int k = 0; k < nn5; ++k) solnstr += "5";
                Console.WriteLine(solnstr);
            }
        }
        static void Main(string[] args) {
            new Program();
        }
    }
}
