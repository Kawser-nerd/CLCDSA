import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

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
        LightScanner in = new LightScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        ADiverseWord solver = new ADiverseWord();
        solver.solve(1, in, out);
        out.close();
    }

    static class ADiverseWord {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            String m = in.string();
            if (m.equals("zyxwvutsrqponmlkjihgfedcba")) {
                out.println(-1);
            } else if (m.length() < 26) {
                boolean[] app = new boolean[26];
                for (char c : m.toCharArray()) {
                    app[c - 'a'] = true;
                }
                for (int i = 0; i < 26; i++) {
                    if (!app[i]) {
                        out.println(m + (char) (i + 'a'));
                        return;
                    }
                }
            } else {
                String s = String.valueOf(ArrayUtil.toCharArray(Permutation.nextPermutation(m.chars().toArray())));
                while (s.substring(0, s.length() - 1).compareTo(m) > 0) {
                    s = s.substring(0, s.length() - 1);
                }
                out.println(s);
            }
        }

    }

    static final class ArrayUtil {
        private ArrayUtil() {
        }

        public static void reverse(int[] a, int left, int right) {
            while (left < right) {
                int temp = a[left];
                a[left] = a[right];
                a[right] = temp;
                left++;
                right--;
            }
        }

        public static char[] toCharArray(int[] a) {
            char[] temp = new char[a.length];
            for (int i = 0; i < a.length; i++) {
                temp[i] = (char) a[i];
            }
            return temp;
        }

    }

    static class LightScanner {
        private BufferedReader reader = null;
        private StringTokenizer tokenizer = null;

        public LightScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
        }

        public String string() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new UncheckedIOException(e);
                }
            }
            return tokenizer.nextToken();
        }

    }

    static final class Permutation {
        private Permutation() {
        }

        public static int[] nextPermutation(int[] a) {
            if (a == null || a.length < 2) {
                return null;
            }
            int p = 0;
            for (int i = a.length - 2; i >= 0; i--) {
                if (a[i] < a[i + 1]) {
                    p = i;
                    break;
                }
            }
            int q = 0;
            for (int i = a.length - 1; i > p; i--) {
                if (a[i] > a[p]) {
                    q = i;
                    break;
                }
            }
            if (p == 0 && q == 0) {
                return null;
            }
            int temp = a[p];
            a[p] = a[q];
            a[q] = temp;
            ArrayUtil.reverse(a, p + 1, a.length - 1);
            return a;
        }

    }
}