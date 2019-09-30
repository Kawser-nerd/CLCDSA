import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D {
    long MOD = 1000000007L;

    long[][][] cnt;
    long[][] c;
    long[] dig;
    long[] fact;


    public void solve() throws FileNotFoundException {
        Scanner in = new Scanner(new File("D-large.in"));
        PrintWriter out = new PrintWriter("D-large.out");

        c = new long[71][71];
        c[0][0] = 1;
        for (int i = 1; i < 71; i++) {
            c[i][0] = 1;
            for (int j = 1; j < c[i].length; j++) {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
            }
        }
        fact = new long[71];
        fact[0] = 1;
        for (int i = 1; i < fact.length; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        int testN = in.nextInt();
        for (int test = 1; test <= testN; test++) {
            long time = System.currentTimeMillis();
            out.print("Case #" + test + ": ");

            long n = in.nextLong();
            int b = in.nextInt();

            cnt = new long[b + 1][b * (b - 1)][b];
            cnt[0][0][0] = 1;
            for (int i = 1; i < b; i++) {
                cnt[1][i][i] = 1;
            }
            for (int i = 1; i < b; i++) {
                for (int j = 0; j < cnt[i].length; j++) {
                    for (int k = 0; k < b; k++) {
                        if (cnt[i][j][k] == 0) {
                            continue;
                        }

                        for (int l = k + 1; l < b; l++) {
                            cnt[i + 1][j + l][l] = (cnt[i][j][k] + cnt[i + 1][j + l][l]) % MOD;
                        }
                    }
                }
            }

            long[][] cc = new long[b + 1][b * (b - 1)];
            for (int i = 0; i <= b; i++) {
                for (int j = 0; j < cc[i].length; j++) {
                    for (int k = 0; k < b; k++) {
                        cc[i][j] = (cc[i][j] + cnt[i][j][k]) % MOD;
                    }
                }
            }

            int dn = 0;
            long nn = n;
            while (nn > 0) {
                nn /= b;
                dn++;
            }
            dig = new long[dn];
            nn = n;
            dn = 0;
            while (nn > 0) {
                dig[dn] = nn % b;
                nn /= b;
                dn++;
            }

            long[][][][] a = new long[dn + 1][b * b][b + 1][2];

            for (int s = 0; s < cc[0].length; s++) {
                if (s % b != dig[0]) {
                    continue;
                }

                for (int k = 0; k < b; k++) {
                    a[1][s / b][k][0] = cc[k][s];
                    a[1][s / b][k + 1][1] = cc[k][s]; 
                }
            }

            for (int i = 1; i < dn; i++) {
                for (int j = 0; j < a[i].length; j++) {
                    for (int k = 0; k <= b; k++) {
                        for (int z = 0; z < 2; z++) {
                            if (a[i][j][k][z] == 0) {
                                continue;
                            }

                            for (int s = 0; s < cc[0].length; s++) {
                                if ((j + s) % b != dig[i]) {
                                    continue;
                                }
                                int nj = (j + s) / b;
                                for (int t = 0; t <= k; t++) {
                                    long nw = 0;
                                    if (z == 0) {
                                        nw = (c[k][t] * fact[t]) % MOD;
                                    } else {
                                        if (t > 0) {
                                            nw = (c[k - 1][t - 1] * fact[t]) % MOD;
                                        }
                                    }
                                    nw = (nw * cc[t][s]) % MOD;
                                    a[i + 1][nj][t][0] = (a[i + 1][nj][t][0] + nw * a[i][j][k][z]) % MOD;

                                    if (t > 0) {
                                        nw = 0;
                                        if (z == 0) {
                                            nw = (c[k][t] * fact[t]) % MOD;
                                        } else {
                                            nw = (c[k - 1][t - 1] * fact[t]) % MOD;
                                        }
                                        nw = (nw * cc[t - 1][s]) % MOD;
                                        a[i + 1][nj][t][1] = (a[i + 1][nj][t][1] + nw * a[i][j][k][z]) % MOD;
                                    }
                                }

                            }
                        }
                    }
                }
            }

            long r = 0;
            for (int i = 0; i <= b; i++) {
                r = (r + a[dn][0][i][0]) % MOD;
            }
            out.println(r);
            System.err.println(System.currentTimeMillis() - time);
        }

        in.close();

        out.close();
    }

    public static void main(String[] args) throws FileNotFoundException {
        new D().solve();
    }
}