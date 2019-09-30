import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int[] A;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        N = sc.nextInt();
        A = sc.nextIntArray(N);
        Ans answer = solve();
        pw.println( answer.value );
        pw.println( answer.way.size() );
        for (int each : answer.way) {
            pw.println(each+1);
        }
        pw.flush();
    }

    static Ans solve() {
        long even = 0;
        for (int i = 0; i < N; i++) {
            if( i % 2 == 0 && A[i] > 0) {
                even += A[i];
            }
        }

        long odd = 0;
        for (int i = 0; i < N; i++) {
            if( i % 2 == 1 && A[i] > 0 ) {
                odd += A[i];
            }
        }

        if( even <= 0 && odd <= 0 ) {
            return case_0();
        }

        List<Integer> ways = new ArrayList<>();
        LinkedList<Long> list = new LinkedList<>();
        for (int i : A) {
            list.add((long) i);
        }

        // ?????even?????
        if( odd > even ) {
            list.removeFirst();
            ways.add(0);
        }

        while(list.size() > 1 ) {
            if( list.size() == 2 ) {
                list.removeLast();
                ways.add(1);

            } else {
                // plus?????
                // ???minus??????????
                if( list.getFirst() < 0 ) {
                    // ???????
                    ways.add(0);
                    ways.add(0);
                    list.removeFirst(); // minus?
                    list.removeFirst(); // odd?

                } else {
                    long nextEven = list.get(2);
                    if( nextEven >= 0 ) {
                        long first = list.getFirst();
                        ways.add(1);
                        list.set(1, first + nextEven);
                        list.remove(2);
                        list.remove(0);

                    } else {
                        if( list.size() == 3 ) {
                            // 0 1 2 -> 0 1
                            list.removeLast();
                            ways.add(2);
                        } else {
                            // 0 1 2 3 -> 0 1 1+3 3 -> 0 1+3
                            long second = list.get(1);
                            long forth = list.get(3);
                            ways.add(2);
                            list.set(2, second + forth); //??????????????????
                            list.remove(3);
                            list.remove(1);
                        }
                    }
                }
            }
        }
        return new Ans(list.getFirst(), ways);
    }

    static Ans case_0() {
        int max = Integer.MIN_VALUE;
        int max_index = -1;

        for (int i = 0; i < N; i++) {
            if( A[i] > max ) {
                max = A[i];
                max_index = i;
            }
        }

        List<Integer> ways = new ArrayList<>();
        // max_index????????
        // -> max_index???????????????(way=0)
        // + N-max_index-1????????????????(way=size-1)
        for (int i = 0; i < max_index; i++) {
            ways.add(0);
        }
        for (int i = 0; i < N-max_index-1; i++) {
            int size = N - max_index - i;
            ways.add(size-1);
        }

        return new Ans(max, ways);
    }

    static class Ans {
        long value;
        List<Integer> way;

        public Ans(long value, List<Integer> way) {
            this.value = value;
            this.way = way;
        }
    }

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