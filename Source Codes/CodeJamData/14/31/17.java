package at.jaki.round1C.A;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class A {

    //private static final String INPUT = "A-large.in";
    private static final String INPUT = "A-small-attempt0.in";
    //private static final String INPUT = "A-test.in";
    //private static final String OUTPUT = "A-large.out";
    private static final String OUTPUT = "A-small-attempt0.out";
    //private static final String OUTPUT = "A-test.out";

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(INPUT));
        PrintWriter pw = new PrintWriter(OUTPUT);
        int totalTests = Integer.parseInt(br.readLine());
        for (int testNo = 1; testNo <= totalTests; testNo++) {
            String[] temp = br.readLine().split("/");
            long p = Long.parseLong(temp[0]);
            long q = Long.parseLong(temp[1]);
            System.out.println(p + " / " + q);

            while (p % 2 == 0 && q % 2 == 0) {
                p /= 2;
                q /= 2;
            }
            for (long i = 3; i <= Math.sqrt(p); i += 2) {
                if (p % i == 0 && q % i == 0) {
                    p /= i;
                    q /= i;
                }
            }
            if (q % p == 0) {
                q /= p;
                p = 1;
            }

            String result;
            if (!is2Fac(q)) {
                result = "impossible";
            } else {
                while (p > 1) {
                    q /= 2;
                    p /= 2;
                }
                result = "" + count(q);
            }


            System.out.println(p + " / " + q);

            pw.print("Case #" + testNo + ": ");
            pw.println(result);

            System.out.println(result);
        }

        pw.flush();
        pw.close();

    }

    private static int count(long q) {
        int total = 0;
        while (q > 1) {
            q /= 2;
            total++;
        }
        return total;
    }

    private static boolean is2Fac(long q) {
        while (q > 1) {
            if (q % 2 == 0) {
                q /= 2;
            } else {
                return false;
            }
        }
        return true;
    }

}
