import java.io.*;
import java.util.*;
import java.util.List;

public class Main {
    private static StringTokenizer st;
    private static BufferedReader br;
    public static long MOD = 1000000007;
    private static double EPS = 0.0000001;

    public static void print(Object x) {
        System.out.println(x + "");
    }
    public static void printArr(long[] x) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < x.length; i++) {
            s.append(x[i] + " ");
        }
        print(s);
    }
    public static void printArr(int[] x) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < x.length; i++) {
            s.append(x[i] + " ");
        }
        print(s);
    }
    public static void printArr(char[] x) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < x.length; i++) {
            s.append(x[i] + "");
        }
        print(s);
    }
    public static String join(Collection<?> x, String space) {
        if (x.size() == 0) return "";
        StringBuilder sb = new StringBuilder();
        boolean first = true;
        for (Object elt : x) {
            if (first) first = false;
            else sb.append(space);
            sb.append(elt);
        }
        return sb.toString();
    }

    public static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            st = new StringTokenizer(line.trim());
        }
        return st.nextToken();
    }
    public static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }
    public static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }
    public static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }
    public static List<Integer> nextInts(int N) throws IOException {
        List<Integer> ret = new ArrayList<Integer>();
        for (int i = 0; i < N; i++) {
            ret.add(nextInt());
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        br = new BufferedReader(new FileReader("input.txt"));

        int T = nextInt();
        for (int t = 1; t <= T; t++) {
            int N = nextInt();
            int K = nextInt();
            int[] min = new int[K];
            int[] max = new int[K];

            int[] sums = new int[N-K+1];
            for (int i = 0; i < N-K+1; i++) sums[i] = nextInt();

            int diff = 0;
            for (int i = 0; i < K; i++) {
                int cur = 0;
                for (int j = i; j < N-K; j += K) {
                    cur += sums[j+1] - sums[j];
                    min[i] = Math.min(min[i], cur);
                    max[i] = Math.max(max[i], cur);
                }
                diff = Math.max(diff, max[i] - min[i]);
            }
            int tolerance = 0;
            for (int i = 0; i < K; i++) tolerance += diff - (max[i] - min[i]);

            int mod = (sums[0] + 20000 * K) % K;
            int cur = 0;
            for (int i = 0; i < K; i++) cur -= min[i];
            cur = cur % K;
            int error = (cur <= mod) ? (mod - cur) : (mod + K - cur);
            if (tolerance < error) diff += 1;

            System.out.printf("Case #%d: %d%n", t, diff);
        }
    }
}