import java.io.*;
import java.util.StringTokenizer;

public class B {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        int tests = in.nextInt();
        for (int testcase = 1; testcase <= tests; testcase++) {
            int x = in.nextInt();
            int y = in.nextInt();

            StringBuilder answer = new StringBuilder();
            while (x > 0) {
                answer.append("WE");
                x--;
            }
            while (x < 0) {
                answer.append("EW");
                x++;
            }
            while (y > 0) {
                answer.append("SN");
                y--;
            }
            while (y < 0) {
                answer.append("NS");
                y++;
            }
            out.println("Case #" + testcase + ": " + answer.toString());
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("B-small-attempt0.in"));
            out = new PrintWriter(new File("B-small.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        new B().run();
    }
}