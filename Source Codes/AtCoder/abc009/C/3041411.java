import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.util.Scanner;
import java.util.HashMap;
import java.util.Objects;
import java.util.Map;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        C solver = new C();
        solver.solve(1, in, out);
        out.close();
    }

    static class C {
        private static String s;
        private static Map<C.Key, String> dp = new HashMap<>();

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            // dp.clear();
            int n = in.nextInt(), k = in.nextInt();
            s = in.next();
            char[] array = s.toCharArray();
            Arrays.sort(array);
            out.println(calc(new C.Key(k, String.valueOf(array))));
            // System.out.println(dp);
        }

        private String calc(C.Key key) {
            if (key.k < 0) {
                return null;
            } else if (key.s.length() == 0) {
                return "";
            } else if (dp.containsKey(key)) {
                return dp.get(key);
            }

            // POSSIBILITY PREDICTION
            int[] count = new int[26];
            for (int i = s.length() - key.s.length(); i < s.length(); i++) {
                count[s.charAt(i) - 'a']++;
            }
            for (int i = 0; i < key.s.length(); i++) {
                count[key.s.charAt(i) - 'a']--;
            }
            int dif = IntStream.of(count).map(Math::abs).sum();
            if (dif > key.k * 2) {
                dp.put(key, null);
                return null;
            }

            for (int i = 0; i < key.s.length(); i++) {
                int k = s.charAt(s.length() - key.s.length()) == key.s.charAt(i) ? key.k : key.k - 1;
                String res = calc(new C.Key(k, key.s.substring(0, i) + key.s.substring(i + 1)));
                if (res != null) {
                    String v = key.s.charAt(i) + res;
                    dp.put(key, v);
                    return v;
                }
            }

            dp.put(key, null);
            return null;
        }

        private static class Key {
            private final int k;
            private final String s;

            public Key(int k, String s) {
                this.k = k;
                this.s = s;
            }

            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;
                C.Key key = (C.Key) o;
                return k == key.k &&
                        Objects.equals(s, key.s);
            }

            public int hashCode() {
                return Objects.hash(k, s);
            }

            public String toString() {
                return s + ":" + k;
            }

        }

    }
}