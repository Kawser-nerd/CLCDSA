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
        int countTest = in.nextInt();
        for (int test = 1; test <= countTest; test++) {
            out.print("Case #" + test + ": ");
            int n = in.nextInt();
            String[] a = new String[n];
            String[] c = new String[n];
            int[][] cntC = new int[n][];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextLine();
                c[i] = "";
                for (int j = 0; j < a[i].length(); j++) {
                    if ((c[i].isEmpty()) || (a[i].charAt(j) != c[i].charAt(c[i].length() - 1))) {
                        c[i] += a[i].charAt(j);
                    }
                }
                cntC[i] = new int[c[i].length()];
                for (int j = 0, x = 0; j < a[i].length(); j++) {
                    if (a[i].charAt(j) == c[i].charAt(x)) {
                        cntC[i][x]++;
                    } else {
                        x++;
                        cntC[i][x]++;
                    }
                }
            }
            boolean diff = false;
            for (int i = 1; i < n; i++) {
                if (!c[i].equals(c[i - 1])) {
                    diff = true;
                    break;
                }
            }
            if (diff) {
                out.println("Fegla Won");
                continue;
            }
            int m = c[0].length();
            int[] maxC = new int[m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    maxC[j] = Math.max(maxC[j], cntC[i][j]);
                }
            }
            int res = 0;
            for (int j = 0; j < m; j++) {
                int curRes = Integer.MAX_VALUE;
                for (int len = 1; len <= maxC[j]; len++) {
                    int cur = 0;
                    for (int i = 0; i < n; i++) {
                        cur += Math.abs(cntC[i][j] - len);
                    }
                    curRes = Math.min(curRes, cur);
                }
                res += curRes;
            }
            out.println(res);
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
