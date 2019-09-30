/**
 * Created by rubanenko on 31.05.14.
 */
import java.io.*;
import java.util.*;

public class A implements Runnable {

    int n, m, best, ans;
    String[] s;
    int[] a;

    void rec(int x) {
        if (x == m + 1) {
            int[][][] t = new int[5][100][100];
            int[] cnt = new int[100];
            int res = 0;
            for (int i = 1; i <= n; i++) {
             //   System.err.println(n);
                cnt[i] = 1;
                res++;
            }
            for (int i = 1; i <= m; i++) {
                int v = 1, num = a[i];
                for (int j = 0; j < s[i].length(); j++) {
                    int q = (int)s[i].charAt(j);
                    if (t[num][v][q] == 0) {
                        cnt[num]++;
                        t[num][v][q] = cnt[num];
                        res++;
                    }
                    v = t[num][v][q];
                }
            }
            for (int i = 1; i <= n; i++) {
                if (cnt[i] == 1) return;
            }
            if (res > best) {
                best = res;
                ans = 0;
            }
            if (res == best) ans++;
            return;
        }
        for (int i = 1; i <= n; i++) {
            a[x] = i;
            rec(x + 1);
        }
    }

    public void solve() throws IOException {
        int tc = scanner.nextInt();
        for (int tcc = 1; tcc <= tc; tcc++) {
            writer.print("Case #" + tcc + ": ");
            m = scanner.nextInt();
            n = scanner.nextInt();
            s = new String[m + 1];
            a = new int[m + 1];
            for (int i = 1; i <= m; i++) {
                s[i] = scanner.nextToken();
            }
            best = 0;
            ans = 0;
            rec(1);
            writer.println(best + " " + ans);
        }
    }

    public static void main(String[] args) {
        //	long startTime = System.currentTimeMillis();
        new A().run();
        //	long finishTime = System.currentTimeMillis();
        //	System.err.println(finishTime - startTime + "ms.");
    }

    public Scanner scanner;
    public PrintWriter writer;

    @Override
    public void run() {
        try {
            scanner = new Scanner(new FileInputStream("input.txt"));
            writer = new PrintWriter(new FileOutputStream("output.txt"));
            solve();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public static class Scanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;
        public boolean hasMoreTokens() throws IOException{
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                String s = nextLine();
                if (s == null) return false;
                tokenizer = new StringTokenizer(s);
            }
            return true;
        }
        Scanner(InputStream inputStream) {
            reader = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String nextLine() throws IOException {
            return reader.readLine();
        }

        public String nextToken() throws IOException {
            while (tokenizer == null || !tokenizer.hasMoreTokens())
                tokenizer = new StringTokenizer(nextLine());
            return tokenizer.nextToken();
        }

        public int nextInt() throws NumberFormatException, IOException {
            return Integer.parseInt(nextToken());
        }
        public long nextLong() throws NumberFormatException, IOException {
            return Long.parseLong(nextToken());
        }


        public double nextDouble() throws NumberFormatException, IOException {
            return Double.parseDouble(nextToken());
        }

    }
}