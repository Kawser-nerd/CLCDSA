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
            int n = scanner.nextInt();
            int[] a = new int[n + 2];
            int num = 1;
            for (int i = 1; i <= n; i++) {
                a[i] = scanner.nextInt();
                if (a[i] > a[num]) num = i;
            }
            int l = 1, r = n, ans = 0;
            for (int iter = 1; iter < n; iter++) {
                num = l;
                for (int i = l; i <= r; i++) {
                    if (a[i] < a[num]) num = i;
                }
                if (r - num < num - l) {
                    while (num != r) {
                        int tmp = a[num + 1];
                        a[num + 1] = a[num];
                        a[num] = tmp;
                        num++;
                        ans++;
                    }
                    r--;
                }
                else {
                    while (num != l) {
                        int tmp = a[num - 1];
                        a[num - 1] = a[num];
                        a[num] = tmp;
                        num--;
                        ans++;
                    }
                    l++;
                }
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
            scanner = new Scanner(new FileInputStream("B-large.in"));
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