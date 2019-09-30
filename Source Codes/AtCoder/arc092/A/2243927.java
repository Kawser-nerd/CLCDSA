import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.TreeSet;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        int RED = 0;
        int BLUE = 1;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int N = in.nextInt();

            TaskC.Point[] points = new TaskC.Point[2 * N];

            for (int i = 0; i < N; i++) {
                points[i] = new TaskC.Point(in.nextInt(), in.nextInt(), RED);
            }
            for (int i = 0; i < N; i++) {
                points[N + i] = new TaskC.Point(in.nextInt(), in.nextInt(), BLUE);
            }

            Arrays.sort(points, (p1, p2) -> p1.x - p2.x);

            int ans = 0;

            TreeSet<TaskC.Point> reds = new TreeSet<>((p1, p2) -> p1.y - p2.y);

            for (TaskC.Point p : points) {
                if (p.color == RED) {
                    reds.add(p);
                } else {
                    TaskC.Point redPair = reds.floor(p);
                    if (redPair != null) {
                        ans++;
                        reds.remove(redPair);
                    }
                }
            }

            out.println(ans);
        }

        static class Point {
            int x;
            int y;
            int color;

            public Point(int x, int y, int color) {
                this.x = x;
                this.y = y;
                this.color = color;
            }

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}