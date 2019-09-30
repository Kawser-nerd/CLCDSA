import java.io.*;
import java.util.*;

public class Main {

    private static class InputReader {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException exp) {
                    throw new RuntimeException(exp);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {    //throws FileNotFoundException {
        InputStream inputStream = System.in;    //new FileInputStream("input.txt");
        OutputStream outputStream = System.out; //new FileOutputStream("output.txt");
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        Task newTask = new Task();
        newTask.solve(in, out);

        out.close();
    }

    private static class Task {
        //.constant
        private final int INF = Integer.MAX_VALUE;
        private final int MOD = (int)1e9 + 7;

        //.data
        private long[] cntCgtB = new long[100001];

        private int upperBound(Integer[] arr, int x) {
            int l = 0;
            int r = arr.length - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (arr[mid] > x) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            return r + 1;
        }

        //.code
        public void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            Integer[][] arr = new Integer[3][n];
            for (int j = 0; j < 3; ++j) {
                for (int i = 0; i < n; ++i) {
                    arr[j][i] = in.nextInt();
                }
            }

            Arrays.sort(arr[2], Comparator.reverseOrder());
            Arrays.sort(arr[1], Comparator.reverseOrder());

            cntCgtB[0] = upperBound(arr[2], arr[1][0]);
            for (int i = 1; i < n; ++i) {
                cntCgtB[i] = cntCgtB[i - 1] + upperBound(arr[2], arr[1][i]);
            }

            long ans = 0;
            for (int i = 0; i < n; ++i) {
                int k = upperBound(arr[1], arr[0][i]) - 1;
                if (k >= 0) {
                    ans += cntCgtB[k];
                }
            }

            out.println(ans);

        }//end

    }

}