import java.io.*;
import java.math.BigInteger;
import java.util.*;

/**
 * User: Igor Kirov
 * Date: 12.05.13
 */
public class GW implements Runnable {
    int delta = 500;

    class Attack implements Comparable<Attack> {
        int time;
        int w;
        int e;
        int s;

        @Override
        public int compareTo(Attack o) {
            return time - o.time;
        }
    }

    private boolean successful(int[] wall, Attack a) {
        for (int i = delta + a.w + 1; i <= delta + a.e; i++) {
            if (wall[i] < a.s) {
                return true;
            }
        }
        return false;
    }

    private void updateWall(int[] wall, Attack a) {
        for (int i = delta + a.w + 1; i <= delta + a.e; i++) {
            wall[i] = Math.max(wall[i], a.s);
        }
    }

    private void solve() throws IOException {
        int n = nextInt();

        Map<Integer, List<Attack>> attacks = new TreeMap<Integer, List<Attack>>();

        for (int i = 0; i < n; i++) {
            int d = nextInt();
            int nn = nextInt();
            int w = nextInt();
            int e = nextInt();
            int s = nextInt();
            int dd = nextInt();
            int dp = nextInt();
            int ds = nextInt();
            for (int j = 0; j < nn; j++) {
                Attack a = new Attack();
                a.time = d;
                a.w = w;
                a.e = e;
                a.s = s;
                List<Attack> l = attacks.get(d);
                if (l == null) {
                    l = new ArrayList<Attack>();
                }
                l.add(a);
                attacks.put(d, l);

                w += dp;
                e += dp;
                d += dd;
                s += ds;
            }
        }

        int[] wall = new int[1000];
        int res = 0;
        for (Integer i : attacks.keySet()) {
            for (Attack a : attacks.get(i)) {
                if (successful(wall, a)) {
                    res++;
                }
            }
            for (Attack a : attacks.get(i)) {
                updateWall(wall, a);
            }
        }

        writer.println(res);
    }

    public static void main(String[] args) {
        new Thread(null, new GW(), "", 64 * 1024 * 1024).start();
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

            reader = new BufferedReader(new FileReader("GW.in"));
            writer = new PrintWriter(new FileWriter("GW.out"));
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