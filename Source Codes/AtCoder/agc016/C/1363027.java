import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class Main {

    public static void main(String[] args) throws Exception {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;

        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }
}

class Task {

    public void solve(InputReader in, PrintWriter out) {
        int H = in.nextInt();
        int W = in.nextInt();
        int h = in.nextInt();
        int w = in.nextInt();
        if (H % h == 0 && W % w == 0) {
            out.println("No");
            return;
        }
        int cnt = H / h * (W / w);
        out.println("Yes");
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                if (j > 1) out.print(" ");
                if (i % h == 0 && j % w == 0) {
                    out.print(-1000 * w * h + 999);
                } else {
                    out.print(1000);
                }
            }
            out.println();
        }
    }
}


class InputReader {

    private final BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String nextLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(nextLine());
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

}