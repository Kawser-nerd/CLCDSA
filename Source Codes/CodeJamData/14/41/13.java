/**
 * Created by rubanenko on 31.05.14.
 */
import java.io.*;
import java.util.*;

public class A implements Runnable {


    public void solve() throws IOException {
        int tc = scanner.nextInt();
        for (int tcc = 1; tcc <= tc; tcc++) {
            writer.print("Case #" + tcc + ": ");
            int n = scanner.nextInt(), x = scanner.nextInt();
            int[] a = new int[n + 2];
            for (int i = 1; i <= n; i++) {
                a[i] = scanner.nextInt();
            }
            for (int i = 1; i <= n; i++)
                for (int j = i + 1;j  <= n; j++) {
                    if (a[i] > a[j]) {
                        int tmp = a[i];
                        a[i] = a[j];
                        a[j] = tmp;
                    }
                }
            int ans = 0, r = n;
            for (int i = 1; i <= r; i++) {
                while (r > i && a[r] + a[i] > x) {
                    ans++;
                    r--;
                }
                if (i == r) {
                    ans++;
                    break;
                }
                ans++;
                r--;
            }
            writer.println(ans);
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
            scanner = new Scanner(new FileInputStream("A-large.in"));
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