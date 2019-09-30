import java.io.*;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;
import java.util.StringTokenizer;

/**
 * User: Igor Kirov
 * Date: 03.05.2014
 */
public class Blarge implements Runnable {
    class Triple {
        int l, r, k;

        Triple(int l, int r, int k) {
            this.l = l;
            this.r = r;
            this.k = k;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Triple triple = (Triple) o;

            if (k != triple.k) return false;
            if (l != triple.l) return false;
            if (r != triple.r) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = l;
            result = 31 * result + r;
            result = 31 * result + k;
            return result;
        }
    }

    private Map<Triple, Long> cache = new HashMap<>();

    private long rec(int a, int b, int k) {
        Triple triple = new Triple(a, b, k);
        if (cache.containsKey(triple)) {
            return cache.get(triple);
        }
        if (a == 0 || b == 0) {
            return 1 + a + b;
        }
        int cura = 1;
        while (cura <= a) {
            cura *= 2;
        }
        int curb = 1;
        while (curb <= b) {
            curb *= 2;
        }
        int curk = 1;
        while (curk <= k) {
            curk *= 2;
        }
        long ret = 0;
        if (cura == curb) {
            ret += rec(cura / 2 - 1, curb / 2 - 1, k);
            ret += rec(cura / 2 - 1, b - (curb / 2), k);
            ret += rec(a - (cura / 2), curb / 2 - 1, k);
            if (curk > cura) {
                ret += rec(a - (cura / 2), b - (curb / 2), k);
            } else if (curk == cura) {
                ret += rec(a - (cura / 2), b - (curb / 2), k - (curk / 2));
            }
        } else if (cura <= curb) {
            ret += rec(a, curb / 2 - 1, k);
            ret += rec(a, b - (curb / 2), k);
        } else if (curb <= cura) {
            ret += rec(cura / 2 - 1, b, k);
            ret += rec(a - (cura / 2), b, k);
        }

        cache.put(triple, ret);

        return ret;
    }

    private void solve() throws IOException {
        int a = nextInt();
        int b = nextInt();
        int k = nextInt();
        writer.println(rec(a - 1, b - 1, k - 1));
    }

    public static void main(String[] args) {
        new Thread(null, new Blarge(), "", 64 * 1024 * 1024).start();
    }

    StringTokenizer tokenizer;
    BufferedReader reader;
    PrintWriter writer;

    public void run() {
        try {
            try {
                Locale.setDefault(Locale.US);
            } catch (Exception ignored) {
            }

            reader = new BufferedReader(new FileReader("Blarge.in"));
            writer = new PrintWriter(new FileWriter("Blarge.out"));
            tokenizer = null;

            int tests = nextInt();
            for (int i = 0; i < tests; i++) {
                writer.printf("Case #%d: ", i + 1);
                solve();
                writer.flush();
            }

            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private BigInteger nextBigInteger() throws IOException {
        return new BigInteger(nextToken());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    private String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}