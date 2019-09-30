import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.util.TreeMap;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author amotoma3
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int x1 = in.nextInt();
            int y1 = in.nextInt();
            int x2 = in.nextInt();
            int y2 = in.nextInt();

            if (x1 > x2) {
                int tmp;

                tmp = x1;
                x1 = x2;
                x2 = tmp;

                tmp = y1;
                y1 = y2;
                y2 = tmp;
            }

            int sign = y1 < y2 ? 1 : -1;
            y1 *= sign;
            y2 *= sign;

            int n = in.nextInt();
            TreeMap<Integer, Integer> map = new TreeMap<>();
            for (int i = 0; i < n; i++) {
                int x = in.nextInt();
                int y = sign * in.nextInt();

                if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
                    map.put(x, y);
                }
            }

            int[] lis = IntStream.generate(() -> (int) 1e9).limit(map.size()).toArray();
            for (int x : map.values()) {
                int index = ArrayUtils.lowerBound(lis, x);
                lis[index] = x;
            }
            int len = ArrayUtils.lowerBound(lis, (int) 1e9);

            if (len == Math.min(x2 - x1, y2 - y1) + 1) {
                out.println(100.0 * (x2 - x1 + y2 - y1) + (20 * Math.PI / 4 - 20) * (len - 1) + 20 * Math.PI / 2 - 20);
            } else {
                out.println(100.0 * (x2 - x1 + y2 - y1) + (20 * Math.PI / 4 - 20) * len);
            }
        }

    }

    static class InputReader {
        BufferedReader in;
        StringTokenizer tok;

        public String nextString() {
            while (!tok.hasMoreTokens()) {
                try {
                    tok = new StringTokenizer(in.readLine(), " ");
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            return tok.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

        public InputReader(InputStream inputStream) {
            in = new BufferedReader(new InputStreamReader(inputStream));
            tok = new StringTokenizer("");
        }

    }

    static class ArrayUtils {
        public static int lowerBound(int[] a, int x) {
            int high = a.length;
            int low = -1;
            while (high - low > 1) {
                int mid = (high + low) / 2;
                if (a[mid] < x) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
            return high;
        }

    }
}