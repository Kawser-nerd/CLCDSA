import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream;
        OutputStream outputStream;
        try {
            inputStream = new FileInputStream("in");
            outputStream = new FileOutputStream("output");
//            outputStream = System.out;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }
}

class Task {
    public void solve(InputReader in, PrintWriter out) {
        int T = 32;
        int countTest = in.nextInt();
        for (int test = 1; test <= countTest; test++) {
            out.print("Case #" + test + ": ");
            int a = in.nextInt();
            int b = in.nextInt();
            int k = in.nextInt();
            int[] sa = new int[T];
            int[] sb = new int[T];
            int[] sk = new int[T];
            for (int i = 0; i < T; i++) {
                sa[T - 1 - i] = a % 2;
                sb[T - 1 - i] = b % 2;
                sk[T - 1 - i] = k % 2;
                a /= 2;
                b /= 2;
                k /= 2;
            }
            long[][][][] f = new long[T + 1][2][2][2];
            f[0][0][0][0] = 1;
            for (int i = 0; i < T; i++) {
                for (int fi = 0; fi < 2; fi++) {
                    for (int fj = 0; fj < 2; fj++) {
                        for (int fk = 0; fk < 2; fk++) {
                            if (f[i][fi][fj][fk] == 0) {
                                continue;
                            }
                            for (int x = 0; x < 2; x++) {
                                for (int y = 0; y < 2; y++) {
                                    if ((fi == 0) && (x > sa[i])) {
                                        continue;
                                    }
                                    if ((fj == 0) && (y > sb[i])) {
                                        continue;
                                    }
                                    int z = (x & y);
                                    if ((fk == 0) && (z > sk[i])) {
                                        continue;
                                    }
                                    int nfi = fi;
                                    int nfj = fj;
                                    int nfk = fk;
                                    if (x < sa[i]) {
                                        nfi = 1;
                                    }
                                    if (y < sb[i]) {
                                        nfj = 1;
                                    }
                                    if (z < sk[i]) {
                                        nfk = 1;
                                    }
                                    f[i + 1][nfi][nfj][nfk] += f[i][fi][fj][fk];
                                }
                            }
                        }
                    }
                }
            }
            out.println(f[T][1][1][1]);
        }
    }
}

class InputReader {
    private static BufferedReader bufferedReader;
    private static StringTokenizer stringTokenizer;

    public InputReader(InputStream inputStream) {
        bufferedReader = new BufferedReader(new InputStreamReader(inputStream));
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public String next() {
        while (stringTokenizer == null || !stringTokenizer.hasMoreTokens()) {
            try {
                stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return stringTokenizer.nextToken();
    }

    public String nextLine() {
        try {
            return bufferedReader.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }
}
