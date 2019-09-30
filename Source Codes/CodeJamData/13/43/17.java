import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class GCJC {

    static void solve(int[] a, int[] b, PrintWriter out) {
        int n = a.length;
//        int[] addLeft = new int[n];
//        int[] addRight = new int[n];
//        int[] ans = new int[n];
//        Arrays.fill(ans, -1);
//        for (int it = 0; it < n; ++it) {
//            int min = -1;
//            for (int i = 0; i < n; ++i) {
//                if (ans[i] == -1 && a[i] == addLeft[i] + 1 && b[i] == addRight[i] + 1 &&
//                        (min == -1 || a[i] + b[i] < a[min] + b[min])) {
////                    if (min != -1) {
////                        System.err.println(Arrays.toString(a));
////                        System.err.println(Arrays.toString(b));
////                        System.err.println(Arrays.toString(addLeft));
////                        System.err.println(Arrays.toString(addRight));
////                        System.err.println(Arrays.toString(ans));
////                        throw new AssertionError("too many mins");
////                    }
//                    min = i;
//                }
//            }
//            if (min == -1) {
//                System.err.println(Arrays.toString(a));
//                System.err.println(Arrays.toString(b));
//                System.err.println(Arrays.toString(addLeft));
//                System.err.println(Arrays.toString(addRight));
//                System.err.println(Arrays.toString(ans));
//                throw new AssertionError("no min");
//            }
//            ans[min] = it + 1;
//            for (int i = min - 1; i >= 0; --i) {
//                addRight[i] = Math.max(addRight[i], addRight[min] + 1);
//            }
//            for (int i = min + 1; i < n; ++i) {
//                addLeft[i] = Math.max(addLeft[i], addLeft[min] + 1);
//            }
//        }
        boolean[][] g = new boolean[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (a[i] >= a[j]) {
                    g[j][i] = true;
                }
                if (b[i] <= b[j]) {
                    g[i][j] = true;
                }
            }
            int less = -1;
            for (int j = 0; j < i; ++j) {
                if (a[j] + 1 == a[i]) {
                    if (less == -1) {
                        less = j;
                    } else {
                        less = -2;
                    }
                }
            }
            if (less >= 0) {
                g[less][i] = true;
            }
            int more = -1;
            for (int j = i; j < n; ++j) {
                if (b[j] + 1 == b[i]) {
                    if (more == -1) {
                        more = j;
                    } else {
                        more = -2;
                    }
                }
            }
            if (more >= 0) {
                g[more][i] = true;
            }
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    g[i][j] |= g[i][k] && g[k][j];
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((g[i][j] && g[j][i])) {
                    throw new AssertionError(i + " " + j);
                }
            }
        }
        int[] ans = new int[n];
        boolean[] col = new boolean[n];
        for (int i = 0; i < n; ++i) {
            int less = 0;
            for (int j = i + 1; j < n; ++j) {
                if (g[j][i]) {
                    less++;
                }
            }
            while (less > 0 || col[ans[i]]) {
                while (col[ans[i]]) {
                    ans[i]++;
                }
                if (less > 0) {
                    ans[i]++;
                    less--;
                }
            }
            col[ans[i]] = true;
        }
        for (int i = 0; i < n; ++i) {
            out.print((ans[i] + 1) + " ");
        }
        out.println();
        out.flush();
        for (int i = 0; i < n; ++i) {
            int maxLeft = 1, maxRight =  1;
            for (int j = 0; j < i; ++j) {
                if (ans[j] < ans[i]) {
                    maxLeft = Math.max(maxLeft, a[j] + 1);
                }
            }
            for (int j = i + 1; j < n; ++j) {
                if (ans[j] < ans[i]) {
                    maxRight = Math.max(maxRight, b[j] + 1);
                }
            }
            if (maxLeft != a[i] || maxRight != b[i]) {
                throw new AssertionError(i + " " + maxLeft + " " + maxRight + " " + a[i] + " " + b[i]);
            }
        }
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < n; ++i) {
            b[i] = in.nextInt();
        }
        solve(a, b, out);
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);
//        ArrayList<Integer> ar = new ArrayList<Integer>();
//        for (int i = 0; i < 10; ++i) {
//            ar.add(i);
//        }
//        while (ar != null) {
//            Collections.shuffle(ar);
//            int[] a = new int[ar.size()];
//            int[] b = new int[ar.size()];
//            for (int i = 0; i < ar.size(); ++i) {
//                a[i] = 1;
//                for (int j = 0; j < i; ++j) {
//                    if (ar.get(j) < ar.get(i)) {
//                        a[i] = Math.max(a[i], a[j] + 1);
//                    }
//                }
//            }
//            for (int i = ar.size() - 1; i >= 0; --i) {
//                b[i] = 1;
//                for (int j = i; j < ar.size(); ++j) {
//                    if (ar.get(j) < ar.get(i)) {
//                        b[i] = Math.max(b[i], b[j] + 1);
//                    }
//                }
//            }
////            System.err.println("ar: " + ar);
//            solve(a, b, out);
//        }
        Input in = new Input(new BufferedReader(new InputStreamReader(System.in)));
        int tests = in.nextInt();
        for (int i = 0; i < tests; ++i) {
            out.print("Case #" + (i + 1) + ": ");
            solve(in, out);
            out.flush();
        }
        out.close();
    }

    static class Input {
        BufferedReader in;
        StringTokenizer st;

        public Input(BufferedReader in) {
            this.in = in;
            eat("");
        }

        public Input(String s) {
            this.in = new BufferedReader(new StringReader(s));
        }

        public void eat(String str) {
            st = new StringTokenizer(str);
        }

        public String next() throws IOException {
            while (!st.hasMoreTokens()) {
                String line = in.readLine();
                if (line == null) {
                    return null;
                }
                eat(line);
            }
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}
