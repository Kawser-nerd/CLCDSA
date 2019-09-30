import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    public void run() {
        try {
            int testCount = reader.nextInt();
            for (int t = 1; t <= testCount; ++ t) {
                int a = reader.nextInt();
                int b = reader.nextInt();
                int c = reader.nextInt();
                memory = new Long[8][N + 1];
                writer.println(String.format("Case #%d: %d", t, solve(a, b, c)));
            }
        } catch (IOException ex) {
        }
        writer.close();
    }

    static int N = 32;

    int[] a, b, c;
    Long[][] memory;

    long go(int mask, int length) {
        if (length == 0) {
            return mask == 7 ? 1 : 0;
        }
        if (memory[mask][length] != null) {
            return memory[mask][length];
        }
        long result = 0;
        for (int x = 0; x < 2; ++ x) {
            for (int y = 0; y < 2; ++ y) {
                if ((mask >> 0 & 1) == 0 && x > a[length - 1]) {
                    continue;
                }
                if ((mask >> 1 & 1) == 0 && y > b[length - 1]) {
                    continue;
                }
                int z = x & y;
                if ((mask >> 2 & 1) == 0 && z > c[length - 1]) {
                    continue;
                }
                int newMask = mask;
                if (x < a[length - 1]) {
                    newMask |= 1;
                }
                if (y < b[length - 1]) {
                    newMask |= 2;
                }
                if (z < c[length - 1]) {
                    newMask |= 4;
                }
                result += go(newMask, length - 1);
            }
        }
        memory[mask][length] = result;
        return result;
    }

    long solve(int a, int b, int c) {
        this.a = transform(a);
        this.b = transform(b);
        this.c = transform(c);
        return go(0, N);
    }

    int[] transform(int n) {
        int[] result = new int[N];
        for (int i = 0; i < N; ++ i) {
            result[i] = n >> i & 1;
        }
        return result;
    }

    Main() {
        reader = new InputReader(System.in);
        writer = new PrintWriter(System.out);
    }

    public static void main(String[] args) {
        new Main().run();
    }

    private void debug(Object...os) {
        System.err.println(Arrays.deepToString(os));
    }

    private InputReader reader;
    private PrintWriter writer;
}

class InputReader {
    InputReader(InputStream in) {
        reader    = new BufferedReader(new InputStreamReader(in));
        tokenizer = new StringTokenizer("");
    }

    private String next() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    public Integer nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    private BufferedReader  reader;
    private StringTokenizer tokenizer;
}
