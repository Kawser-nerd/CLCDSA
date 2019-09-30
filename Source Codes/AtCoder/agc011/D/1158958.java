import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class Main {

    private void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        String s = next();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = s.charAt(i) == 'B' ? 1 : 0;
        }
        int j = 0;
        while (k > 0) {
            if (j == n) {
                if (n % 2 == 1) {
                    if (k % 2 == 0) {
                        for (int i = 0; i < n; i++) {
                            out.print("AB".charAt(i % 2));
                        }
                    } else {
                        out.print("B");
                        for (int i = 1; i < n; i++) {
                            out.print("AB".charAt(i % 2));
                        }
                    }
                } else {
                    for (int i = 0; i < n; i++) {
                        out.print("BA".charAt(i % 2));
                    }
                }
                return;
            } else {
                if ((a[j] + j) % 2 == 0) {
                    a[j] = 1 - a[j];
                } else {
                    j++;
                }
                k--;
            }
        }
//        System.out.println(j + " " + Arrays.toString(a));
        for (int i = 0; i < n; i++) {
            int q;
            if (j + i >= n) {
                q = (n + i + 1) % 2;
            } else {
                q = (a[j + i] + j) % 2;
            }
            out.print("AB".charAt(q));
        }
        out.println();
    }

    // ------------------

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    PrintWriter out = new PrintWriter(System.out);

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}