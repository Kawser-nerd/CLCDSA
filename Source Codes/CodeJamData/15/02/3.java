import java.io.*;
import java.util.*;
import java.util.List;

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
    public static List<Integer> nextInts(int N) throws IOException {
        List<Integer> ret = new ArrayList<Integer>();
        for (int i = 0; i < N; i++) {
            ret.add(nextInt());
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        //br = new BufferedReader(new InputStreamReader(System.in));
        br = new BufferedReader(new FileReader("input.txt"));

        int T = nextInt();
        for (int t = 1; t <= T; t++) {
            int D = nextInt();
            int[] pancakes = new int[D];
            for (int i = 0; i < D; i++) pancakes[i] = nextInt();

            int maxTime = 1000;
            for (int eatTime = 1; eatTime < 1000; eatTime++) {
                int moves = 0;
                for (int p : pancakes)
                    moves += ((int) Math.ceil(p / (float) eatTime)) - 1;
                maxTime = Math.min(maxTime, moves + eatTime);
            }
            System.out.printf("Case #%d: %d%n", t, maxTime);
        }
    }
}
