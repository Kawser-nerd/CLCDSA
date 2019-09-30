import java.io.*;
import java.util.*;
import java.util.stream.Stream;


public class Main implements Runnable {
    static final int MOD = (int) 1e9 + 7;
    static final int MI = (int) 1e9;
    static final long ML = (long) 1e18;
    static final Reader in = new Reader();
    static final PrintWriter out = new PrintWriter(System.out);
    StringBuilder answer = new StringBuilder();

    public static void main(String[] args) {
        new Thread(null, new Main(), "persefone", 1 << 28).start();
    }

    @Override
    public void run() {
        solve();
        printf();
        flush();
    }

    void solve() {
        int n = in.nextInt();
        long sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            int k = in.nextInt();
            if (k == 0) {
                ans += sum >> 1;
                sum = 0;
                continue;
            }

            sum += k;
            if (i == n - 1) ans += sum >> 1;
        }
        printf(ans);
    }

    void printf() {
        out.print(answer);
    }

    void close() {
        out.close();
    }

    void flush() {
        out.flush();
    }

    void printf(Stream<?> str) {
        str.forEach(o -> add(o, " "));
        add("\n");
    }


    void printf(Object... obj) {
        printf(false, obj);
    }

    void printfWithDescription(Object... obj) {
        printf(true, obj);
    }


    private void printf(boolean b, Object... obj) {

        if (obj.length > 1) {
            for (int i = 0; i < obj.length; i++) {
                if (b) add(obj[i].getClass().getSimpleName(), " - ");
                if (obj[i] instanceof Collection<?>) {
                    printf((Collection<?>) obj[i]);
                } else if (obj[i] instanceof int[][]) {
                    printf((int[][]) obj[i]);
                } else if (obj[i] instanceof long[][]) {
                    printf((long[][]) obj[i]);
                } else if (obj[i] instanceof double[][]) {
                    printf((double[][]) obj[i]);
                } else printf(obj[i]);
            }
            return;
        }

        if (b) add(obj[0].getClass().getSimpleName(), " - ");
        printf(obj[0]);
    }

    void printf(Object o) {
        if (o instanceof int[])
            printf(Arrays.stream((int[]) o).boxed());
        else if (o instanceof char[])
            printf(new String((char[]) o));
        else if (o instanceof long[])
            printf(Arrays.stream((long[]) o).boxed());
        else if (o instanceof double[])
            printf(Arrays.stream((double[]) o).boxed());
        else if (o instanceof boolean[]) {
            for (boolean b : (boolean[]) o) add(b, " ");
            add("\n");
        } else
            add(o, "\n");
    }

    void printf(int[]... obj) {
        for (int i = 0; i < obj.length; i++) printf(obj[i]);
    }

    void printf(long[]... obj) {
        for (int i = 0; i < obj.length; i++) printf(obj[i]);
    }

    void printf(double[]... obj) {
        for (int i = 0; i < obj.length; i++) printf(obj[i]);
    }

    void printf(boolean[]... obj) {
        for (int i = 0; i < obj.length; i++) printf(obj[i]);
    }

    void printf(Collection<?> col) {
        printf(col.stream());
    }

    <T, K> void add(T t, K k) {
        if (t instanceof Collection<?>) {
            ((Collection<?>) t).forEach(i -> add(i, " "));
        } else if (t instanceof Object[]) {
            Arrays.stream((Object[]) t).forEach(i -> add(i, " "));
        } else
            add(t);
        add(k);
    }


    <T> void add(T t) {
        answer.append(t);
    }

    @SuppressWarnings("unchecked")
    <T extends Comparable<? super T>> T min(T... t) {
        if (t.length == 0)
            return null;
        T m = t[0];
        for (int i = 1; i < t.length; i++)
            if (t[i].compareTo(m) < 0)
                m = t[i];
        return m;
    }

    @SuppressWarnings("unchecked")
    <T extends Comparable<? super T>> T max(T... t) {
        if (t.length == 0)
            return null;
        T m = t[0];
        for (int i = 1; i < t.length; i++)
            if (t[i].compareTo(m) > 0)
                m = t[i];
        return m;
    }

    static class Pair<K extends Comparable<? super K>, V extends Comparable<? super V>>
            implements Comparable<Pair<K, V>> {
        private K k;
        private V v;

        Pair(K k, V v) {
            this.k = k;
            this.v = v;
        }

        @SuppressWarnings("unchecked")
        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || !(o instanceof Pair)) return false;
            Pair<K, V> p = (Pair<K, V>) o;
            return k.compareTo(p.k) == 0 && v.compareTo(p.v) == 0;
        }

        @Override
        public int hashCode() {
            int hash = 31;
            hash = hash * 89 + k.hashCode();
            hash = hash * 89 + v.hashCode();
            return hash;
        }

        @Override
        public int compareTo(Pair<K, V> pair) {
            return k.compareTo(pair.k) == 0 ? v.compareTo(pair.v) : k.compareTo(pair.k);
        }

        @Override
        public Pair<K, V> clone() {
            return new Pair<K, V>(this.k, this.v);
        }

        @Override
        public String toString() {
            return String.valueOf(k).concat(" ").concat(String.valueOf(v)).concat("\n");
        }
    }

    static class Reader {
        private BufferedReader br;
        private StringTokenizer st;

        Reader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            try {
                while (st == null || !st.hasMoreTokens()) {
                    st = new StringTokenizer(br.readLine());
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++)
                arr[i] = nextInt();
            return arr;
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String s = "";
            try {
                s = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return s;
        }
    }
}