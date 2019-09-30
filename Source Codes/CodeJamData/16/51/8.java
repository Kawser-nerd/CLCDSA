import java.io.*;
import java.util.*;

public class Assistant {

    public void solve() {
        String s = in.nextToken();

        char[] stack = new char[s.length()];
        int size = 0;
        for (char c : s.toCharArray()) {
            if (size > 0 && c == stack[size - 1]) {
                size--;
            } else {
                stack[size++] = c;
            }
        }
        out.println(5 * (size / 2) + 10 * (s.length() - size) / 2);
    }

    public void run() {
        try {
            in = new FastScanner("input.txt");
            out = new PrintWriter("output.txt");
            int tests = in.nextInt();
            for (int i = 1; i <= tests; i++) {
                long time = System.currentTimeMillis();
                out.printf("Case #%d: ", i);
                solve();
                System.err.printf("Solved case #%d in %d ms\n", i, System.currentTimeMillis() - time);
            }
            out.close();
        } catch (FileNotFoundException e) {
        }
    }

    FastScanner in;
    PrintWriter out;

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
            }
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new Assistant().run();
    }
}
