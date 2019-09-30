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
        int N = nextInt();
        int J = nextInt();
        Random r = new Random();

        System.out.printf("Case #1:%n");
        Set<String> used = new HashSet<>();
        outer : for (int i = 0; i < J;) {
            char[] ans = new char[N];
            ans[0] = '1';
            ans[N-1] = '1';
            for (int d = 1; d < N - 1; d++) {
                if (r.nextBoolean()) ans[d] = '1';
                else ans[d] = '0';
            }

            // Check
            String out = new String(ans) + " ";
            if (used.contains(out)) continue;
            used.add(out);
            for (int d = 2; d <= 10; d++) {
                String divisor = null;
                BigInteger value = new BigInteger(new String(ans), d);
                for (int n = 2; n <= 100; n++) {
                    if (value.equals(BigInteger.valueOf(n))) continue;
                    if (value.mod(BigInteger.valueOf(n)).equals(BigInteger.ZERO)) {
                        divisor = n + " ";
                        break;
                    }
                }
                if (divisor == null) {
                    continue outer;
                }
                out += divisor;
            }
            System.out.printf("%s%n", out);
            i += 1;
        }
    }
}
