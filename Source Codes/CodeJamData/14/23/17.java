import java.io.*;
import java.util.*;

public class Main {
    static final long MOD = 1000000007;
    static int N;
    static boolean[][] connected;
    static String[] city;
    static String res;
    
    static void search(int[] order, boolean[] used, int index) {
        if (index == N) {
            boolean[] ban = new boolean[N];
        outer:
            for (int i = 1; i < N; ++i) {
                for (int j = i - 1; j >= 0; --j) {
                    if (!ban[j] && connected[order[i]][order[j]]) {
                        continue outer;
                    } else {
                        ban[j] = true;
                    }
                }
                return;
            }
            //System.out.println(Arrays.toString(order));
            StringBuilder builder = new StringBuilder(N * 5);
            for (int c : order) {
                builder.append(city[c]);
            }
            String value = builder.toString();
            if (res == null || value.compareTo(res) < 0) {
                res = value;
            }
            return;
        }
        for (int i = 0; i < N; ++i) {
            if (!used[i]) {
                used[i] = true;
                order[index] = i;
                search(order, used, index + 1);
                used[i] = false;
            }
        }
    }
    
    static String solve() {
        res = null;
        int[] order = new int[N];
        boolean[] used = new boolean[N];
        search(order, used, 0);
        return res;
    }
    
    public static void main(String[] args) throws Exception {
        FastScanner scan = new FastScanner(System.in);
        int taskCount = scan.nextInt();
        for (int taskIndex = 1; taskIndex <= taskCount; ++taskIndex) {
            N = scan.nextInt();
            int M = scan.nextInt();
            city = new String[N];
            connected = new boolean[N][N];
            for (int i = 0; i < N; ++i) {
                city[i] = scan.nextToken();
            }
            for (int i = 0; i < M; ++i) {
                int a = scan.nextInt() - 1;
                int b = scan.nextInt() - 1;
                connected[a][b] = connected[b][a] = true;
            }
            System.out.println(String.format("Case #%d: %s", taskIndex, solve()));
        }
    }
}

class FastScanner {
    BufferedReader in;
    StringTokenizer tok;
    
    public FastScanner(InputStream in) {
        this.in = new BufferedReader(new InputStreamReader(in));
        tok = new StringTokenizer("");
    }
    
    private String tryReadNextLine() {
        try {
            return in.readLine();
        } catch (Exception e) {
            throw new InputMismatchException();
        }
    }
    
    public String nextToken() {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(next());
        }
        return tok.nextToken();
    }
    
    private String next() {
        String newLine = tryReadNextLine();
        if (newLine == null)
            throw new InputMismatchException();
        return newLine;
    }
    
    public int nextInt() {
        return Integer.parseInt(nextToken());
    }
    
    public double nextDouble() {
        return Double.parseDouble(nextToken());
    }
    
    public long nextLong() {
        return Long.parseLong(nextToken());
    }
    
}