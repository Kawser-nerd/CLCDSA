import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int height = in.nextInt();
            int width = in.nextInt();
            int horz = in.nextInt();
            int vert = in.nextInt();
            char[][] res = new char[height][width];
            for (char[] x : res) Arrays.fill(x, '.');
            if (height % 2 != 0) {
                --height;
                for (int i = 0; i + 2 <= width && horz > 0; i += 2) {
                    --horz;
                    res[height][i] = '<';
                    res[height][i + 1] = '>';
                }
                ++height;
            }
            if (width % 2 != 0) {
                --width;
                for (int i = 0; i + 2 <= height && vert > 0; i += 2) {
                    --vert;
                    res[i][width] = '^';
                    res[i + 1][width] = 'v';
                }
                ++width;
            }
            for (int i = 0; i < height / 2; ++i) {
                for (int j = 0; j < width / 2; ++j) {
                    boolean extra = 2 * i + 3 == height && 2 * j + 3 == width;
                    if (horz >= 2) {
                        --horz;
                        res[i * 2][j * 2] = '<';
                        res[i * 2][j * 2 + 1] = '>';
                        if (horz > 0) {
                            --horz;
                            res[i * 2 + 1][j * 2] = '<';
                            res[i * 2 + 1][j * 2 + 1] = '>';
                        }
                    } else if (vert >= 2) {
                        --vert;
                        res[i * 2][j * 2] = '^';
                        res[i * 2 + 1][j * 2] = 'v';
                        if (vert > 0) {
                            --vert;
                            res[i * 2][j * 2 + 1] = '^';
                            res[i * 2 + 1][j * 2 + 1] = 'v';
                        }
                    } else if (horz > 0 && (vert == 0 || !extra)) {
                        --horz;
                        res[i * 2][j * 2] = '<';
                        res[i * 2][j * 2 + 1] = '>';
                        if (horz > 0) {
                            --horz;
                            res[i * 2 + 1][j * 2] = '<';
                            res[i * 2 + 1][j * 2 + 1] = '>';
                        }
                    } else if (vert > 0 && (horz == 0 || !extra)) {
                        --vert;
                        res[i * 2][j * 2] = '^';
                        res[i * 2 + 1][j * 2] = 'v';
                        if (vert > 0) {
                            --vert;
                            res[i * 2][j * 2 + 1] = '^';
                            res[i * 2 + 1][j * 2 + 1] = 'v';
                        }
                    } else if (horz > 0 && vert > 0 && extra) {
                        res[i * 2][j * 2] = '^';
                        res[i * 2 + 1][j * 2] = 'v';
                        res[i * 2][j * 2 + 1] = '<';
                        res[i * 2][j * 2 + 2] = '>';
                        res[i * 2 + 1][j * 2 + 2] = '^';
                        res[i * 2 + 2][j * 2 + 2] = 'v';
                        --horz;
                        --vert;
                    }
                }
            }
            if (horz > 0 || vert > 0) {
                out.println("NO");
            } else {
                out.println("YES");
                for (char[] x : res) {
                    out.println(new String(x));
                }
            }
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}