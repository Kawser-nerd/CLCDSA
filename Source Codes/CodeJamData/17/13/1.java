
import java.io.*;
import java.util.StringTokenizer;

public class C {

    private String solveTest() throws IOException {
        int hd = nextInt();
        int ad = nextInt();
        int hk = nextInt();
        int ak = nextInt();
        int b = nextInt();
        int d = nextInt();
        boolean[][][][] z = new boolean[101][101][101][101];
        int[][][][] ds = new int[101][101][101][101];
        int[] qhd = new int[101 * 101 * 101 * 101];
        int[] qhk = new int[101 * 101 * 101 * 101];
        int[] qad = new int[101 * 101 * 101 * 101];
        int[] qak = new int[101 * 101 * 101 * 101];
        int h = 0;
        int t = 1;
        qhd[0] = hd;
        qhk[0] = hk;
        qad[0] = ad;
        qak[0] = ak;
        z[hd][hk][ad][ak] = true;
        int res = Integer.MAX_VALUE;
        while (t > h) {
            int hhd = qhd[h];
            int hhk = qhk[h];
            int aad = qad[h];
            int aak = qak[h];
            if (hhk == 0) {
                res = Math.min(res, ds[hhd][hhk][aad][aak]);
            }
            h++;
            for (int i = 0; i < 4; i++) {
                int nhd = hhd;
                int nhk = hhk;
                int nad = aad;
                int nak = aak;
                if (i == 0) {
                    nhk -= nad;
                }
                if (i == 1) {
                    nad += b;
                    if (nad > 100) nad = 100;
                }
                if (i == 2) {
                    nhd = hd;
                }
                if (i == 3) {
                    nak -= d;
                    if (nak < 0) nak = 0;
                }
                if (nhk <= 0) {
                    nhk = 0;
                } else {
                    nhd -= nak;
                }
                if (nhd > 0) {
                    if (!z[nhd][nhk][nad][nak]) {
                        z[nhd][nhk][nad][nak] = true;
                        ds[nhd][nhk][nad][nak] = ds[hhd][hhk][aad][aak] + 1;
                        qhd[t] = nhd;
                        qhk[t]= nhk;
                        qad[t] = nad;
                        qak[t] = nak;
                        t++;
                    }
                }
            }

        }
        return res == Integer.MAX_VALUE ? "IMPOSSIBLE" : ("" + res);
    }

    private void solve() throws IOException {
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            String res = solveTest();
            System.out.println("Case #" + (i + 1) + ": " + res);
            out.println("Case #" + (i + 1) + ": " + res);
        }
    }


    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws FileNotFoundException {
        new C().run();
    }

    private void run() throws FileNotFoundException {
        br = new BufferedReader(new FileReader(this.getClass().getSimpleName().substring(0, 1) + ".in"));
        out = new PrintWriter(this.getClass().getSimpleName().substring(0, 1) + ".out");
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
        out.close();
    }

}