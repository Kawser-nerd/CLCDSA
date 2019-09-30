import java.io.*;
import java.util.StringTokenizer;

public class A {
    FastScanner in;
    PrintWriter out;

    private boolean isVowel(char ch) {
        return "aeiou".indexOf(ch) != -1;
    }

    public void solve() throws IOException {
        int tests = in.nextInt();
        for (int testcase = 1; testcase <= tests; testcase++) {
            String s = in.next();
            int n = in.nextInt();

            long answer = 0;
            int last = -1;
            int rle = 0;
            for (int i = 0; i < s.length(); i++) {
                boolean isCons = !isVowel(s.charAt(i));
                if (isCons) {
                    rle++;
                } else {
                    rle = 0;
                }
                if (rle >= n) {
                    last = i;
                }

                if (last != -1) {
                    answer += ((long)(last - n + 2));
                }
            }

            out.println("Case #" + testcase + ": " + answer);
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("A-large.in"));
            out = new PrintWriter(new File("a-large.out"));

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
        new A().run();
    }
}