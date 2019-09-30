import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        out.printf("Case #%d: ", testNumber);
        int r = in.nextInt();
        int c = in.nextInt();
        int w = in.nextInt();
        int addRow = c / w * (r - 1);
        int inRow = c / w + w;
        if (c % w == 0)
            inRow--;
        out.println(addRow + inRow);
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
