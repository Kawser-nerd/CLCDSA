import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringJoiner;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] A, B;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        A = new int[N];
        B = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = fc.nextInt();
            B[i] = fc.nextInt();
        }

        int[] answer = solve();
        PrintWriter pw = new PrintWriter(System.out);
        pw.println(answer.length);
        StringJoiner j = new StringJoiner(" ");
        for (int i : answer) {
            j.add(String.valueOf(i));
        }
        pw.println(j.toString());
        pw.flush();
    }

    static int[] solve() {
        Job[] JA = new Job[N];
        Job[] JB = new Job[N];
        for (int i = 0; i < N; i++) {
            Job j = new Job(i+1, A[i], B[i]);
            JA[i] = j;
            JB[i] = j;
        }
        Arrays.sort(JA, Comparator.comparing(j -> j.a));
        Arrays.sort(JB, Comparator.comparing(j -> j.b));

        Job best = null;
        int ai = N-1;
        int bi = N-1;
        for (int t = (int)1e6; t >= 0; t--) {
            while( ai >= 0 && JA[ai].a == t ) {
                if( best != null ) {
                    best = best(JA[ai], best);
                } else {
                    best = JA[ai];
                }
                ai--;
            }

            while( bi >= 0 && JB[bi].b == t ) {
                if( best != null ) {
                    JB[bi].score = best.score + 1;
                    JB[bi].next = best;
                } else {
                    JB[bi].score = 1;
                }
                bi--;
            }
        }

        int[] ans = new int[best.score];
        ans[0] = best.id;
        Job cur = best;
        int idx = 1;

        while( cur.next != null ) {
            ans[idx++] = cur.next.id;
            cur = cur.next;
        }
        return ans;
    }

    static int compare(Job j1, Job j2) {
        if( j1.score != j2.score ) {
            return Integer.compare(j2.score, j1.score);
        } else {
            return Integer.compare(j1.id, j2.id);
        }
    }

    static Job best(Job j1, Job j2) {
        if( compare(j1, j2) < 0 ) {
            return j1;
        } else {
            return j2;
        }
    }

    static class Job {
        int id;
        int a, b;
        int score = Integer.MAX_VALUE / 2;
        Job next;

        public Job(int id, int a, int b) {
            this.id = id;
            this.a = a;
            this.b = b;
        }
    }

    @SuppressWarnings("unused")
    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken("\n");
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }
}