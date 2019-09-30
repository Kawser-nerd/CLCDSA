import java.io.*;
import java.util.StringTokenizer;
import java.util.Set;
import java.util.HashSet;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("B-small-attempt0.in"));
        PrintWriter out = new PrintWriter("b.out");

        int T = Integer.parseInt(in.readLine());
        for (int i = 1; i <= T; i++) {
            int N = Integer.parseInt(in.readLine());
            String[] cs = new String[N];
            int[] a = new int[N];
            int[] b = new int[N];
            for (int j = 0; j < N; j++) {
                StringTokenizer tz = new StringTokenizer(in.readLine());
                cs[j] = tz.nextToken();
                a[j] = Integer.parseInt(tz.nextToken());
                b[j] = Integer.parseInt(tz.nextToken());
            }

            int rmin = 1000000;
            boolean[] w = new boolean[N];
            while (true) {
                int r = 0;
                Set<String> cc = new HashSet<String>();
                boolean[] f = new boolean[10000];
                for (int j = 0; j < N; j++) {
                    if (w[j]) {
                        cc.add(cs[j]);
                        r++;
                        if (cc.size() > 3 || r > rmin) break;
                        
                        for (int x = a[j] - 1; x <= b[j] - 1; x++) {
                            f[x] = true;
                        }
                    }
                }

                if (cc.size() <= 3 && r <= rmin) {
                    boolean zz = true;
                    for (boolean y : f) {
                        if (!y) {
                            zz = false;break;
                        }
                    }

                    if (zz) {
                      rmin = r;
                    }
                }

                int k = N - 1;
                while (k >= 0 && w[k]) {
                    w[k] = false;
                    k--;
                }
                if (k < 0) break;
                w[k] = true;
            }

            out.print("Case #" + i + ": ");
            if (rmin > 10000) {
                out.println("IMPOSSIBLE");
            }
            else {
                out.println(rmin);
            }
        }

        in.close();
        out.close();
    }
}