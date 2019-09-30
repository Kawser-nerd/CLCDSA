import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.concurrent.*;

public class PC implements Runnable {
    static String PROBLEM_NAME = PC.class.getSimpleName().toLowerCase();
    static String INPUT_FILE_NAME = PROBLEM_NAME + ".in";
    static String OUTPUT_FILE_NAME = PROBLEM_NAME + ".out";

    static class InputReader {
        final BufferedReader rd;
        StringTokenizer tok = null;

        public InputReader(String filename) throws IOException {
            rd = new BufferedReader(new FileReader(new File(filename)));
        }

        public void close() {
            try {
                rd.close();
            } catch (IOException e) {
            }
        }

        public String nextToken() throws IOException {
            while (tok == null || !tok.hasMoreTokens()) {
                tok = new StringTokenizer(rd.readLine());
            }
            return tok.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(nextToken());
        }

        public String readLine() throws IOException {
            tok = null;
            return rd.readLine();
        }
    }

    public static void main(String[] args) {
        try {
            new Thread(new PC()).start();
        } catch (Exception e) {
        }
    }

    @Override
    public void run() {
        try {
            solve();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    static class Point {
        public long x;
        public long y;

        public Point(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }

    static class Result {
        public int[] r;

        public Result(int[] r) {
            this.r = r;
        }
    }

    private void solve() throws IOException {
        InputReader rd = new InputReader(INPUT_FILE_NAME);
        PrintWriter wr = new PrintWriter(new FileWriter(new File(OUTPUT_FILE_NAME)));

        ExecutorService es = Executors.newFixedThreadPool(16);

        int t = rd.nextInt();
        Future<Result>[] fs = new Future[t];

//        System.out.println(System.currentTimeMillis());

        for (int ti = 0; ti < t; ++ti) {
            int n = rd.nextInt();
            final Point[] p = new Point[n];
            for (int i = 0; i < n; ++i) {
                p[i] = new Point(rd.nextInt(), rd.nextInt());
            }
            fs[ti] = es.submit(new Callable<Result>() {
                @Override
                public Result call() throws Exception {
                    int[] r = subsolve(p);
                    return new Result(r);
                }
            });
        }

        for (int ti = 0; ti < t; ++ti) {
            Result result = null;
            try {
                result = fs[ti].get();
            } catch (InterruptedException e) {
                e.printStackTrace();
            } catch (ExecutionException e) {
                e.printStackTrace();
            }
            wr.println(String.format("Case #%d: ", ti + 1));
            for (int i = 0; i < result.r.length; ++i) {
                wr.println(result.r[i]);
            }
        }

        rd.close();
        wr.close();

        es.shutdown();
//
//
//        System.out.println(System.currentTimeMillis());
    }

    private int[] subsolve(Point[] p) {
        int n = p.length;
        int[] r = new int[n];
        Arrays.fill(r, n - 1);
        for (int i = 0; i < n; ++i) {
//            r[i] = subsubsolve(i, p);
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
                int left = 0;
                int right = 0;
                for (int k = 0; k < n; ++k) {
                    int c = classify(p[i], p[j], p[k]);
                    if (c == -1) {
                        ++left;
                    } else if (c == 1) {
                        ++right;
                    }
                    if (left > r[i] && right > r[i]) {
                        break;
                    }
                }
                r[i] = Math.min(r[i], left);
                r[i] = Math.min(r[i], right);
            }
        }
        return r;
    }

//    static class Pair implements Comparable<Pair> {
//        public double angle;
//        public int index;
//
//        public Pair(double angle, int index) {
//            this.angle = angle;
//            this.index = index;
//        }
//
//        @Override
//        public int compareTo(Pair o) {
//            return Double.compare(angle, o.angle);
//        }
//    }

    private int classify(Point pa, Point pb, Point pc) {
        long pabx = pb.x - pa.x;
        long paby = pb.y - pa.y;
        long pacx = pc.x - pa.x;
        long pacy = pc.y - pa.y;
        long vproduct = pabx * pacy - paby * pacx;
        if (vproduct < 0) {
            return -1;
        } else if (vproduct > 0) {
            return 1;
        }
        return 0;
//            long sproduct = pabx * pacx + paby * pacy;
//            if (sproduct > 0) {
//                return 2;
//            } else if (sproduct < 0) {
//                return -2;
//            }
    }

//    private int subsubsolve(int pi, Point[] p) {
//        int n = p.length;
//        Pair[] pairs = new Pair[n - 1];
//        int l = 0;
//        for (int i = 0; i < n; ++i) {
//            if (i != pi) {
//                pairs[l] = new Pair(Math.atan2(p[i].y - p[pi].y, p[i].x - p[pi].x), i);
//                ++l;
//            }
//        }
//        Arrays.sort(pairs);
//
//        int left = 0;
//        int on = 1;
//
//        int o = 0;
//        for (int i = 0; i < n - 1; ++i) {
//            on += 1;
//            while (true) {
//                int c = classify(p[pi], p[i], p[o]);
//            }
//        }
//
//    }
}