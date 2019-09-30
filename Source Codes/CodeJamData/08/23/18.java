import java.io.*;
import java.util.*;

/**
 * User: def
 * Date: 26.07.2008
 */
public class C {
    public static void main(String args[]) throws IOException {
        new C().solve();
    }

    void solve() throws IOException {
        br = new BufferedReader(new FileReader("C-small-attempt0.in"));
        pw = new PrintWriter("C-small.out");

        int T = Integer.parseInt(br.readLine());
        for(int c = 1; c <= T; ++c) {
            System.out.println(c);
            int K = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int[] d = new int[n];
            for(int i = 0; i < n; ++i) {
                d[i] = Integer.parseInt(st.nextToken());
            }

            int[] v = new int[K];
            int s = 0;
            for(int k = 1; k <= K; ++k) {
                for(int p = 1; p < k; ++p) {
                    s++; if(s == K) s = 0;
                    while(v[s] != 0) {
                        s++; if(s == K) s = 0;
                    }
                }
                v[s] = k;
                if(k < K) {
                    s++; if(s == K) s = 0;
                    while(v[s] != 0) {
                        s++; if(s == K) s = 0;
                    }
                }
            }
            pw.print("Case #" + c + ":");
            for(int i = 0; i < n; ++i) {
                pw.print(" " + v[d[i] - 1]);
            }
            pw.println();
        }


        pw.close();
    }

    BufferedReader br;
    PrintWriter pw;
}
