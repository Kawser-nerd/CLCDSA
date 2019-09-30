import java.rmi.activation.ActivationSystem;
import java.util.*;
import java.io.*;

public class A {
    FastScanner in;
    PrintWriter out;

    public void solve(int testNo) throws IOException {
        System.out.println("Solving case " + testNo);

        int n = in.nextInt();
        int[] s = new int[n];
        int x = 0;
        for (int i = 0; i < n; i++) {
            s[i] = in.nextInt();
            x += s[i];
        }
        
        out.print("Case #" + testNo + ":");
        System.out.print("Case #" + testNo + ":");

        for (int i = 0; i < n; i++) {
            double low = 0;
            double high = 1.0;
            for (int iter = 0; iter < 100; iter++) {
                double v = (low + high) / 2;
                double is = s[i] + x * v;
                
                double total = 0;
                for (int j = 0; j < n; j++) {
                    if (s[j] < is) {
                        total += (is - s[j]) / x;
                    }
                }
                
                if (total > 1) {
                    high = v;
                } else {
                    low = v;
                }
            }
            out.printf(" %.10f", 100.0 * low);
            System.out.printf(" %.10f",  100.0 * low);
        }
        
        out.println();
        System.out.println();

    }

    public void run() {
        try {
            in = new FastScanner(new File("A-large.in"));
            out = new PrintWriter(new File("A-large.out"));

            int testNo = in.nextInt();
            for (int test = 0; test < testNo; test++) {
                solve(test + 1);
            }

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        Locale.setDefault(Locale.US);
        new A().run();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File file) throws IOException {
            br = new BufferedReader(new FileReader(file));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                    return "";
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }
}