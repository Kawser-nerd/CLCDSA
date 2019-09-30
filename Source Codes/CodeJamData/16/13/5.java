import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class Main {
    private static StringTokenizer st;
    private static BufferedReader br;
    public static long MOD = 1000000007;

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

    public static void main(String[] args) throws IOException {
        // br = new BufferedReader(new InputStreamReader(System.in));
        br = new BufferedReader(new FileReader("input.txt"));

        int T = nextInt();

        for (int t = 1; t <= T; t++) {
            int N = nextInt();
            int[] bffs = new int[N+1];
            for (int i = 0; i < N; i++)
                bffs[i+1] = nextInt();

            // Find cycles and tails
            int best = -1;
            int[] tails = new int[N+1];

            for (int start = 1; start <= N; start++) {
                Map<Integer, Integer> seen = new HashMap<>();
                int cur = start;
                int pos = 1;
                while (!seen.containsKey(cur)) {
                    if (!seen.containsKey(bffs[cur]))
                        tails[cur] = Math.max(tails[cur], pos);

                    seen.put(cur, pos);
                    cur = bffs[cur];
                    pos += 1;
                }
                best = Math.max(best, pos - seen.get(cur));
            }

            // Match links
            int links = 0;
            for (int start = 1; start <= N; start++) {
                if (bffs[start] < start) continue;
                if (bffs[bffs[start]] != start) continue;
                links += tails[start] + tails[bffs[start]];
            }

            System.out.printf("Case #%d: %d%n", t, Math.max(best, links));
            //System.out.printf("Case #%d: IMPOSSIBLE%n", t);
        }

    }
}
