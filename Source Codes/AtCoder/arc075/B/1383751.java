import java.io.*;
import java.util.*;

public class Main implements Runnable {

    private void solve() throws IOException {

        int N = nextInt();
        long A = nextLong();
        long B = nextLong();

        long[] a = new long[N];

        for(int i = 0; i < N; ++i) a[i] = nextLong();

        long low = 1L;
        long high = 1_000_000_000_000_000_001L;

        long min = Long.MAX_VALUE;
        while(low <= high) {
            long mid = low + ( high - low ) / 2L;
            if(can(mid,a,A,B)) {
                min = Math.min(min, mid);
                high = mid - 1;
            } else low = mid + 1;
        }
        writer.println(min);

    }

    private boolean can(long hits, long[] a, long A, long B) {

        long left = hits;
        long C = A - B;
        for(int i = 0; i < a.length; ++i) {
            long atLeast = (a[i] / B);
            if(a[i] % B != 0) ++atLeast;
            if(atLeast <= hits) continue;
            long he = a[i];
            he -= (B * hits);
            if(he <= left * C) {
                long need = he / C;
                if(he % C != 0) ++need;
                left -= need;
            } else return false;
        }

        return true;
    }

    public static void main(String[] args) {
        new Main().run();
    }

    BufferedReader reader;
    //    BufferedReader reader2;
    StringTokenizer tokenizer;
    PrintWriter writer;
    //    BufferedWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
//            reader = new BufferedReader(new FileReader("input.txt"));
            //            reader2 = new BufferedReader(new FileReader("1.in"));
            tokenizer = null;
            writer = new PrintWriter(System.out);
//            writer = new     PrintWriter("output.txt");
//                                                    writer = new BufferedWriter(System.out);
            //                        writer = new BufferedWriter(new OutputStreamWriter(System.out));
            solve();
            reader.close();
            //            reader2.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    short nextShort() throws IOException {
        return Short.parseShort(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }

        return tokenizer.nextToken();
    }

}