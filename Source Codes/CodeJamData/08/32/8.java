package indy.codejam;

import java.io.*;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.*;
import java.math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.lang.Math.*;
import static java.lang.Double.parseDouble;
import static java.lang.Float.parseFloat;
import static java.lang.Long.parseLong;
import static java.lang.Integer.parseInt;

public class UglyNumbers {

    public static void main(String[] args) throws Exception {
        String name = "B-large";
        String path = "C:/codejam/";
        Scanner sc = new Scanner(new File(path + name + ".in"));
        PrintWriter pw = new PrintWriter(path + name + ".out");
        int N = sc.nextInt();
        for (int z = 1; z <= N; z++) {
            String s = sc.next();
            int n = s.length();
            BigInteger[][][][][] r = new BigInteger[2][3][5][7][n + 1];
            for (int i = 0; i <= n; i++) {
                for (int i2 = 0; i2 < 2; i2++) {
                    for (int i3 = 0; i3 < 3; i3++) {
                        for (int i5 = 0; i5 < 5; i5++) {
                            for (int i7 = 0; i7 < 7; i7++) {
                                r[i2][i3][i5][i7][i] = BigInteger.ZERO;
                            }
                        }
                    }
                }
            }
            r[0][0][0][0][0] = BigInteger.valueOf(1);

            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    String s1 = s.substring(j, i);
                    int r2 = new BigInteger(s1).mod(BigInteger.valueOf(2)).intValue();
                    int r3 = new BigInteger(s1).mod(BigInteger.valueOf(3)).intValue();
                    int r5 = new BigInteger(s1).mod(BigInteger.valueOf(5)).intValue();
                    int r7 = new BigInteger(s1).mod(BigInteger.valueOf(7)).intValue();

                    for (int i2 = 0; i2 < 2; i2++) {
                        for (int i3 = 0; i3 < 3; i3++) {
                            for (int i5 = 0; i5 < 5; i5++) {
                                for (int i7 = 0; i7 < 7; i7++) {
                                    r[i2][i3][i5][i7][i] = r[i2][i3][i5][i7][i]
                                            .add(r[(i2 + r2) % 2][(i3 + r3) % 3][(i5 + r5) % 5][(i7 + r7) % 7][j]);
                                    r[i2][i3][i5][i7][i] = r[i2][i3][i5][i7][i]
                                            .add(r[(i2 + 2 - r2) % 2][(i3 + 3 - r3) % 3][(i5 + 5 - r5) % 5][(i7 + 7 - r7) % 7][j]);
                                }
                            }
                        }
                    }
                }
            }

            BigInteger res = BigInteger.ZERO;
            for (int i2 = 0; i2 < 2; i2++) {
                for (int i3 = 0; i3 < 3; i3++) {
                    for (int i5 = 0; i5 < 5; i5++) {
                        for (int i7 = 0; i7 < 7; i7++) {
                            if (i2 * i3 * i5 * i7 == 0) {
                                res = res.add(r[i2][i3][i5][i7][n]);
                            }
                        }
                    }
                }
            }

            pw.print("Case #" + z + ": " + res.divide(BigInteger.valueOf(2)));
            pw.println();
            pw.flush();
        }
        pw.close();
    }
}
