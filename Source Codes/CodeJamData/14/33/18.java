package at.jaki.round1C.C;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class C {

    //private static final String INPUT = "C-large.in";
    private static final String INPUT = "C-small-attempt0.in";
    //private static final String INPUT = "C-test.in";
    //private static final String OUTPUT = "C-large.out";
    private static final String OUTPUT = "C-small-attempt0.out";
    //private static final String OUTPUT = "C-test.out";

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(INPUT));
        PrintWriter pw = new PrintWriter(OUTPUT);
        int totalTests = Integer.parseInt(br.readLine());
        for (int testNo = 1; testNo <= totalTests; testNo++) {
            String[] temp = br.readLine().split(" ");
            int n = Integer.parseInt(temp[0]);
            int m = Integer.parseInt(temp[1]);
            int k = Integer.parseInt(temp[2]);


            String result = "" + solve(n, m, k);
            pw.print("Case #" + testNo + ": ");
            pw.println(result);

            System.out.println(result);
        }

        pw.flush();
        pw.close();

    }

    private static int solve(int n, int m, int k) {
        if (n > m) return solve(m, n, k);
        if (n == 1 || m == 1 || n == 2 || m == 2) {
            return k;
        }
        if (k < 5) {
            return k;
        }
        if (k == 5) {
            return 4;
        }
        if (n == 3) {
            if (m == 3) {
                return k - 1;
            }
            if (m == 4) {
                if (k >= 8) {
                    return k - 2;
                } else {
                    return k - 1;
                }
            }
            if (m == 5) {
                if (k >= 11) {
                    return k - 3;
                } else if (k >= 8) {
                    return k - 2;
                } else {
                    return k - 1;
                }
            }
            if (m == 6) {
                if (k >= 14) {
                    return k - 4;
                } else if (k >= 11) {
                    return k - 3;
                } else if (k >= 8) {
                    return k - 2;
                } else {
                    return k - 1;
                }
            }
        }
        if (n == 4) {
            if (m == 4) {
                if (k >= 12) {
                    return k - 4;
                } else if (k >= 10) {
                    return k - 3;
                } else if (k >= 8) {
                    return k - 2;
                } else {
                    return k - 1;
                }
            }
            if (m == 5) {
                if (k >= 16) {
                    return k - 6;
                } else if (k >= 14) {
                    return k - 5;
                } else if (k >= 13) {
                    return k - 4;
                } else if (k >= 10) {
                    return k - 3;
                } else if (k >= 8) {
                    return k - 2;
                } else {
                    return k - 1;
                }
            }
        }
        throw new IllegalStateException("!!");
    }

}
