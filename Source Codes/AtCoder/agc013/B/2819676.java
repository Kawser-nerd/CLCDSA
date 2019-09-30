import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int M;
    static Edge[] E;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        E = new Edge[M];
        for (int i = 0; i < M; i++) {
            E[i] = new Edge(sc.nextInt()-1, sc.nextInt()-1);
        }

        ArrayDeque<Integer> path = solve();
        PrintWriter pw = new PrintWriter(System.out);
        pw.println(path.size());
        StringJoiner j = new StringJoiner(" ");
        for (Integer each : path) {
            j.add(String.valueOf(each+1));
        }
        pw.append(j.toString());
        pw.flush();
    }

    static class Edge {
        int a;
        int b;

        public Edge(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    static ArrayDeque<Integer> solve() {
        ArrayDeque<Integer> q = new ArrayDeque<>();

        List<Integer>[] rin = new List[N];
        for (Edge e : E) {
            if( rin[e.a] == null ) rin[e.a] = new ArrayList<>();
            rin[e.a].add(e.b);
            if( rin[e.b] == null ) rin[e.b] = new ArrayList<>();
            rin[e.b].add(e.a);
        }

        q.add(0);
        q.add(rin[0].get(0));
        Set<Integer> set = new HashSet<>(q);

        fst: while(true) {
            int first = q.getFirst();

            for (Integer each : rin[first]) {
                if( !set.contains(each) ) {
                    q.addFirst(each);
                    set.add(each);
                    continue fst;
                }
            }
            break;
        }

        lst: while(true) {
            Integer last = q.getLast();

            for (Integer each : rin[last]) {
                if( !set.contains(each) ) {
                    q.addLast(each);
                    set.add(each);
                    continue lst;
                }
            }
            break;
        }

        return q;
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

        double nextDouble() {
            return Double.parseDouble(next());
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.