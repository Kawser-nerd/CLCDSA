import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    int V;

    int solveBig(int[] a, long c) {
        long curMax = 0;
        int res = 0;
        Arrays.sort(a);
        for (int i = 0; i < a.length; i++) {
            while (curMax < a[i] - 1) {
                curMax = curMax + (curMax + 1) * c;
                res++;
            }
            curMax += c * a[i];
        }
        while (curMax < V) {
            curMax = curMax  + (curMax + 1) * c;
            res++;
        }
        return res;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        out.printf("Case #%d: ", testNumber);
        int c = in.nextInt();
        int d = in.nextInt();
        V = in.nextInt();
        int[] a = new int[d];
        for (int i = 0; i < d; i++)
            a[i] = in.nextInt();
        out.println(solveBig(a, c));
    }

    public static void main(String[] args)throws IOException {
        FastScanner in = new FastScanner(new FileInputStream("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int t = in.nextInt();
        for (int test = 1; test <= t; test++)
            new Main().solve(test, in, out);
        in.close();
        out.close();
    }

}

class FastScanner {
    private StringTokenizer tokenizer;
    private BufferedReader reader;

    public FastScanner(InputStream inputStream) {
        reader = new BufferedReader(new InputStreamReader(inputStream));
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String line;
            try {
                line = reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            if (line == null)
                return null;
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public String nextLine() {
        String line;
        try {
            line = reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        tokenizer = null;
        return line;
    }

    public void close() {
        try {
            reader.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
