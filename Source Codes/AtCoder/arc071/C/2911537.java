import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static String S;
    static String T;
    static Query[] Q;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        S = sc.next();
        T = sc.next();
        Q = new Query[sc.nextInt()];
        for (int i = 0; i < Q.length; i++) {
            Q[i] = new Query(sc.nextInt()-1, sc.nextInt()-1, sc.nextInt()-1, sc.nextInt()-1);
        }

        boolean[] answer = solve();
        PrintWriter pw = new PrintWriter(System.out);
        for (boolean b : answer) {
            pw.println( b ? "YES" : "NO");
        }
        pw.flush();
    }

    static boolean[] solve() {
        Type[] rs = calcRui(S);
        Type[] rt = calcRui(T);
        boolean[] ans = new boolean[Q.length];
        for (int i = 0; i < Q.length; i++) {
            ans[i] = solve(Q[i], rs, rt);
        }
        return ans;
    }

    static boolean solve(Query q, Type[] rs, Type[] rt) {
        return calc(q.a, q.b, rs) == calc(q.c, q.d, rt);
    }

    static Type calc(int from, int to, Type[] rui) {
        Type pre = from == 0 ? Type.EMPTY : rui[from-1];
        Type all = rui[to];
        // f + x = t
        // ??? x????

        if( pre == Type.A ) {
            switch (all) {
                case A:
                    return Type.EMPTY; // A + E = A
                case B:
                    return Type.A; // A + A = B
                case EMPTY:
                    return Type.B; // A + B = E;
            }
        } else if( pre == Type.B ) {
            switch (all) {
                case A:
                    return Type.B; // B + B = A
                case B:
                    return Type.EMPTY; // B + E = B
                case EMPTY:
                    return Type.A; // B + A = E;
            }

        } else {
            switch (all) {
                case A:
                    return Type.A; // E + A = A
                case B:
                    return Type.B; // E + B = B
                case EMPTY:
                    return Type.EMPTY; // E + E = E;
            }
        }

        throw new RuntimeException("wtf");
    }

    static Type[] calcRui(String s) {
        Type[] rui = new Type[s.length()];
        // [from, to]
        Type type = Type.EMPTY;
        for (int i = 0; i < s.length() ; i++) {
            char c = s.charAt(i);
            if( type == Type.A ) {
                if( c == 'A' ) {
                    type = Type.B;
                } else {
                    type = Type.EMPTY;
                }
            } else if( type == Type.B ) {
                if( c == 'A' ) {
                    type = Type.EMPTY;
                } else {
                    type = Type.A;
                }
            } else {
                if( c == 'A' ) {
                    type = Type.A;
                } else {
                    type = Type.B;
                }
            }
            rui[i] = type;
        }
        return rui;
    }

    enum Type {
        A, B, EMPTY
    }

    static class Query {
        int a;
        int b;
        int c;
        int d;

        public Query(int a, int b, int c, int d) {
            this.a = a;
            this.b = b;
            this.c = c;
            this.d = d;
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