import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.Solve(in, out);
        out.close();
    }

    static class TaskC {
        static long MOD = 1_000_000_007;

        class Point implements Comparable<Point> {
            public double x, y;
            public int index;
            public Point ccwNeighbor;
            public Point cwNeighbor;
            double maxDegree;
            double minDegree;

            public void CalcMaxMin() {
                if (ccwNeighbor == null) {
                    maxDegree = 0;
                    minDegree = 0;
                } else {
                    maxDegree = (-Math.atan2(cwNeighbor.y - y, cwNeighbor.x - x) - Math.PI / 2) % (2 * Math.PI);
                    minDegree = (-Math.atan2(y - ccwNeighbor.y, x - ccwNeighbor.x) - Math.PI / 2) % (2 * Math.PI);
                    while (maxDegree < 0) maxDegree += 2 * Math.PI;
                    while (minDegree < 0) minDegree += 2 * Math.PI;
                    if (maxDegree < minDegree) maxDegree += 2 * Math.PI;
                }
            }


            public double Prop() {
                return (maxDegree - minDegree) / (2 * Math.PI);
            }

            public double Distance(Point p) {
                return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
            }

            @Override
            public int compareTo(Point o) {
                if (o.x == x) {
                    return Double.compare(y, o.y);
                }
                return Double.compare(x, o.x);
            }
        }

        public void Solve(InputReader in, PrintWriter out) {
            int n = in.NextInt();
            Point[] ps = new Point[n];
            for (int i = 0; i < n; i++) {
                Point p = new Point();
                p.x = in.NextDouble();
                p.y = in.NextDouble();
                p.index = i;
                ps[i] = p;
            }
            if (n == 1) {
                out.println(1);
                return;
            }
            if (n == 2) {
                out.println(0.5);
                out.println(0.5);
                return;
            }
            Point min = ps[0];
            for (int i = 0; i < n; i++) {
                if (ps[i].compareTo(min) < 0) {
                    min = ps[i];
                }
            }
            Point first = min;
            while (true) {
                if (min.cwNeighbor != null) break;
                for (int i = 0; i < n; i++) {
                    if (min.compareTo(ps[i]) < 0) {
                        if (min.cwNeighbor == null) min.cwNeighbor = ps[i];
                        else {
                            double orentation = Orentation(min, min.cwNeighbor, ps[i]);
                            if (orentation == 0) {
                                if (min.cwNeighbor.compareTo(ps[i]) < 0) {
                                    min.cwNeighbor = ps[i];
                                }
                            }
                            if (orentation > 0) {
                                min.cwNeighbor = ps[i];
                            }
                        }
                    }
                }
                if (min.cwNeighbor != null) {
                    min.cwNeighbor.ccwNeighbor = min;
                    min = min.cwNeighbor;
                } else {
                    break;
                }
            }
            while (true) {
                if (min.cwNeighbor != null) break;
                for (int i = 0; i < n; i++) {
                    if (min.compareTo(ps[i]) > 0) {
                        if (min.cwNeighbor == null) min.cwNeighbor = ps[i];
                        else {
                            double orentation = Orentation(min, min.cwNeighbor, ps[i]);
                            if (orentation == 0) {
                                if (min.cwNeighbor.compareTo(ps[i]) > 0) {
                                    min.cwNeighbor = ps[i];
                                }
                            }
                            if (orentation > 0) {
                                min.cwNeighbor = ps[i];
                            }
                        }
                    }
                }
                if (min.cwNeighbor != null && min != first) {
                    min.cwNeighbor.ccwNeighbor = min;
                    min = min.cwNeighbor;
                } else {
                    break;
                }
            }


            for (Point p : ps) p.CalcMaxMin();
            for (Point p : ps) out.println(p.Prop());

        }

        public double Orentation(Point a, Point b, Point c) {
            return ((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));

        }
    }


    public static int GetMax(int[] ar) {
        int max = Integer.MIN_VALUE;
        for (int a : ar) {
            max = Math.max(max, a);
        }
        return max;
    }

    public static int GetMin(int[] ar) {
        int min = Integer.MAX_VALUE;
        for (int a : ar) {
            min = Math.min(min, a);
        }
        return min;
    }

    public static long GetSum(int[] ar) {
        long s = 0;
        for (int a : ar) s += a;
        return s;
    }

    public static int[] GetCount(int[] ar) {
        return GetCount(ar, GetMax(ar));
    }

    public static int[] GetCount(int[] ar, int maxValue) {
        int[] dp = new int[maxValue + 1];
        for (int a : ar) {
            dp[a]++;
        }
        return dp;
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String Next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine(), " \t\n\r\f,");
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int NextInt() {
            return Integer.parseInt(Next());
        }

        public long NextLong() {
            return Long.parseLong(Next());
        }

        public double NextDouble() {
            return Double.parseDouble(Next());
        }

        public int[] NextIntArray(int n) {
            return NextIntArray(n, 0);
        }

        public int[] NextIntArray(int n, int offset) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = NextInt() - offset;
            }
            return a;
        }

        public int[][] NextIntMatrix(int n, int m) {
            return NextIntMatrix(n, m, 0);
        }

        public int[][] NextIntMatrix(int n, int m, int offset) {
            int[][] a = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = NextInt() - offset;
                }
            }
            return a;
        }
    }
}