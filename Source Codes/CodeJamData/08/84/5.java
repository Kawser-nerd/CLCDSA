import java.io.IOException;
import java.io.File;
import java.io.PrintWriter;
import java.util.*;

public class DHard implements Runnable {
    int[] nc;
    int k;
    int n;
    int p;
    private int MOD = 30031;

    class Profile {
        int[] r;

        Profile() {
            r = new int[k];
            for (int i = 0; i < k; i++) {
                r[i] = i;
            }
        }

        Profile(int x) {
            r = new int[k];
            int j = 0;
            for (int i = 0; i < p; i++) {
                if ((x & (1 << i)) != 0) {
                    r[j] = i;
                    j++;
                }
            }
        }

        int getOrder() {
            int v = 0;
            for (int i = 0; i < k; i++) {
                v |= 1 << r[i];
            }
            return v;
        }

        Profile(int[] r) {
            this.r = r;
        }

        Profile next(int z) {
            int[] v = r.clone();
            for (int i = 0; i < k; i++) {
                v[i]++;
            }
            v[z] = 0;
            for (int i = 0; i < k; i++) {
                if (v[i] >= p) {
                    return null;
                }
            }
            Arrays.sort(v);
            return new Profile(v);
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Profile profile = (Profile) o;

            if (!Arrays.equals(r, profile.r)) return false;

            return true;
        }

        boolean isValid() {
            for (int i = 0; i < k; i++) {
                if (r[i] != i) {
                    return false;
                }
            }
            return true;
        }

        public int hashCode() {
            return (r != null ? Arrays.hashCode(r) : 0);
        }
    }

    public class Matrix {
        int sz;
        int[][] m;

        public Matrix(int sz, int[][] m) {
            this.sz = sz;
            this.m = m;
        }

        public Matrix(int sz) {
            this.sz = sz;
            m = new int[sz][sz];
            for (int i = 0; i < sz; i++) {
                m[i][i] = 1;
            }
        }

        Matrix mul(Matrix b) {
            int[][] c = new int[sz][sz];
            for (int i = 0; i < sz; i++) {
                for (int j = 0; j < sz; j++) {
                    for (int k = 0; k < sz; k++) {
                        c[i][j] = (c[i][j] + m[i][k] * b.m[k][j] % MOD) % MOD;
                    }
                }
            }
            return new Matrix(sz, c);
        }

        Matrix pow(int b) {
            Matrix r = new Matrix(sz);
            Matrix a = this;
            while (b > 0) {
                if (b % 2 == 1) {
                    r = r.mul(a);
                }
                a = a.mul(a);
                b /= 2;
            }
            return r;
        }
    }

    public void solve() throws IOException {
        Scanner in = new Scanner(new File("D-large.in"));
        PrintWriter out = new PrintWriter(new File("D-large.out"));

        int tn = in.nextInt();
        for (int test = 1; test <= tn; test++) {
            n = in.nextInt();
            k = in.nextInt();
            p = in.nextInt();
            nc = new int[p];

            int pn = 0;
            int[] pmap = new int[1 << p];
            for (int i = 0; i < (1 << p); i++) {
                if (Integer.bitCount(i) == k) {
                    pmap[i] = pn;
                    pn++;
                }
            }

            int[][] m = new int[pn][pn];

            for (int i = 0; i < (1 << p); i++) {
                if (Integer.bitCount(i) == k) {
                    Profile p = new Profile(i);
                    for (int j = 0; j < k; j++) {
                        Profile q = p.next(j);
                        if (q != null) {
                            int ni = q.getOrder();
                            m[pmap[i]][pmap[ni]]++;
                        }
                    }
                }
            }

            Matrix mat = new Matrix(pn, m);
            mat = mat.pow(n - k);

            int row = pmap[new Profile().getOrder()];

            int ans = mat.m[row][row];

            System.out.println(ans);
            out.printf("Case #%d: %d\n", test, ans);
        }

        out.close();
    }

    public void run() {
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Thread(new DHard()).start();
    }
}