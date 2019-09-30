import java.io.*;
import java.util.*;
public class Main {
    private static MyScanner scanner;

    public static void main (String[] args){
        Main instance = new Main();
        scanner = instance.new MyScanner();
        instance.solve();
    }

    private void solve() {
        try {
            int N = scanner.nextInt();
            long[] A = new long[N];
            for (int i = 0; i < N; i++) {
                A[i] = scanner.nextLong();
            }
            long[] d = new long[N];
            for (int i = 0; i < N; i++) {
                d[i] = A[(i+1)%N] - A[i];
            }
            long n = 0;
            for (int i = 0; i < N; i++) {
                n += A[i];
            }
            long x = (long)(N+1)*N / 2l;
            long k = n / x;
            if (n % x != 0) {
                System.out.println("NO");
                return;
            }
            for (int i = 0; i < N; i++) {
                if (d[i]-k > 0 || (d[i]-k) % N != 0) {
                    System.out.println("NO");
                    return;
                }
            }
            System.out.println("YES");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private class MyScanner {
        String[] s;
        int i;
        BufferedReader br;
        String reg = " ";

        MyScanner () {
            s = new String[0];
            i = 0;
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public String next() throws IOException {
            if (i < s.length) return s[i++];
            String line = br.readLine();
            while (line.equals("")) {
                line = br.readLine();
            }
            s = line.split(reg, 0);
            i = 0;
            return s[i++];
        }

        public int nextInt() throws NumberFormatException, IOException {
            return Integer.parseInt(next());
        }

        public double nextDouble() throws NumberFormatException, IOException {
            return Double.parseDouble(next());
        }

        public long nextLong() throws NumberFormatException, IOException {
            return Long.parseLong(next());
        }
    }
}