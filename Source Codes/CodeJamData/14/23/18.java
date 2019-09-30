import java.io.*;
import java.math.BigInteger;
import java.util.*;

/**
 * User: Igor Kirov
 * Date: 03.05.2014
 */
public class C implements Runnable {
    class Sequence implements Comparable<Sequence> {
        String zip;
        int[] seq;

        Sequence(String zip, int[] seq) {
            this.zip = zip;
            this.seq = seq;
        }

        @Override
        public int compareTo(Sequence o) {
            return this.zip.compareTo(o.zip);
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Sequence sequence = (Sequence) o;

            if (!Arrays.equals(seq, sequence.seq)) return false;
            if (zip != null ? !zip.equals(sequence.zip) : sequence.zip != null) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = zip != null ? zip.hashCode() : 0;
            result = 31 * result + (seq != null ? Arrays.hashCode(seq) : 0);
            return result;
        }
    }

    private void generate(int k, int n, String[] zip, int[] perm) {
        if (k == n) {
            int[] seq = new int[n];
            StringBuilder str = new StringBuilder();
            for (int i = 0; i < n; i++) {
                seq[i] = perm[i];
                str.append(zip[perm[i]]);
            }
            sequences.add(new Sequence(str.toString(), seq));
            return;
        }
        for (int j = k; j < n; j++) {
            int t = perm[k];
            perm[k] = perm[j];
            perm[j] = t;
            generate(k + 1, n, zip, perm);
            t = perm[k];
            perm[k] = perm[j];
            perm[j] = t;
        }
    }

    private void genperms(int n, String[] zip) {
        int[] perm = new int[n];
        for (int i = 0; i < n; i++) {
            perm[i] = i;
        }
        generate(0, n, zip, perm);
    }

    List<Sequence> sequences;

    private boolean go(int n, boolean[] vis, Sequence s, int k, int curcnt, int[] curseq) {
        if (k == n) {
            return true;
        }
        vis[curseq[curcnt-1]] = true;
        for (int i = curcnt - 1; i >= 0; i--) {
            int u = curseq[i];
            int v = s.seq[k];
            boolean ok = false;
            if (a[u][v] && !vis[v]) {
                int[] ncurseq = new int[n];
                for (int j = 0; j <= i; j++) {
                    ncurseq[j] = curseq[j];
                }
                ncurseq[i + 1] = v;
                ok = go(n, vis, s, k + 1, i + 2, ncurseq);
            }
            if (ok) return true;
        }
        vis[curseq[curcnt-1]] = false;
        return false;
    }

    private boolean check(int n, Sequence s) {
        boolean[] vis = new boolean[n];
        int[] curseq = new int[n];
        int curcnt = 1;
        curseq[0] = s.seq[0];
        vis[curseq[0]] = true;
        return go(n, vis, s, 1, curcnt, curseq);
    }

    boolean[][] a;

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        String[] zip = new String[n];
        for (int i = 0; i < n; i++) {
            zip[i] = nextToken();
        }

        a = new boolean[n][n];
        for (int i = 0; i < m; i++) {
            int u = nextInt();
            int v = nextInt();
            a[u - 1][v - 1] = true;
            a[v - 1][u - 1] = true;
        }

        sequences = new ArrayList<>();

        genperms(n, zip);

        Collections.sort(sequences);

        for (Sequence s : sequences) {
            if (check(n, s)) {
                writer.println(s.zip);
//                writer.println(Arrays.toString(s.seq));
                return;
            }
        }

        throw new RuntimeException();
    }

    public static void main(String[] args) {
        new Thread(null, new C(), "", 64 * 1024 * 1024).start();
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

            reader = new BufferedReader(new FileReader("C.in"));
            writer = new PrintWriter(new FileWriter("C.out"));
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