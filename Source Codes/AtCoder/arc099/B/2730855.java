import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int k = in.nextInt();

            TreeSet<Long> set = new TreeSet<>();
            set.add(0L);
            for (int i = 0; i < 14; i++) {
                StringBuilder s = new StringBuilder();
                for (int j = 0; j < i; j++) s.append("9");
                for (int j = 0; j < 1000; j++) {
                    String u = "";
                    int tmp = j;
                    while (tmp > 0) {
                        u = tmp % 10 + u;
                        tmp /= 10;
                    }
                    String numStr = u + s.toString();
                    if (!"".equals(numStr))
                        set.add(Long.parseLong(numStr));
                }
            }

            long[] x = new long[set.size()];
            int idx = 0;
            for (long t : set) {
                x[idx++] = t;
            }
            Arrays.sort(x);

            double[] a = new double[set.size()];
            for (int i = 0; i < set.size(); i++) {
                if (x[i] != 0)
                    a[i] = (double) x[i] / calc(x[i]);
            }

            Double min = Double.MAX_VALUE;
            List<Long> ans = new ArrayList<>();
            for (int i = a.length - 1; i > 0; i--) {
                if (Double.compare(min, a[i]) >= 0) {
                    ans.add(x[i]);
                    min = a[i];
                }
            }

            for (int i = 0; i < k; i++) {
                out.println(ans.get(ans.size() - 1 - i));
            }
        }

        int calc(long n) {
            int ret = 0;
            while (n > 0) {
                ret += n % 10;
                n /= 10;
            }
            return ret;
        }

    }

    static class InputReader {
        BufferedReader br;
        StringTokenizer st;

        public InputReader(InputStream inputStream) {
            br = new BufferedReader(new InputStreamReader(inputStream));
            st = new StringTokenizer("");
        }

        public String nextString() {
            while (!st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine(), " ");
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

    }
}