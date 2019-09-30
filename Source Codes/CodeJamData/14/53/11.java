import java.io.*;
import java.util.*;

public class Main {
    static int[] state = new int[2010];
    static int[] map = new int[2010];
    static boolean get(int val, int bitIndex) {
        return (val & (1 << bitIndex)) != 0;
    }
    
    static int solve(char[] type, int[] id) {
        int N = id.length;
        int[] copy = Arrays.copyOf(id, id.length);
        Arrays.sort(copy);
        int last = 0;
        int index = 1;
        for (int val : copy) {
            if (val != last) {
                last = val;
                map[val] = index++;
            }
        }
        for (int i = 0; i < N; ++i) {
            if (id[i] > 0) {
                id[i] = map[id[i]];
            }
        }
        int count = index - 1;
        int stateCount = 1 << count;
        int total = 2 * N + 1;
        boolean[][][] dp = new boolean[N + 1][total][stateCount];
        for (boolean[] arr : dp[0]) {
            Arrays.fill(arr, true);
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < total; ++j) {
                for (int k = 0; k < stateCount; ++k) {
                    if (!dp[i][j][k]) {
                        continue;
                    }
                    if (j <= 1) {
                        int a = 1;
                        ++a;
                    }
                    if (type[i] == 'E') {
                        if (id[i] == 0) {
                            if (j < total - 1) {
                                dp[i + 1][j + 1][k] = true;
                            }
                            for (int m = 0; m < count; ++m) {
                                if (!get(k, m)) {
                                    dp[i + 1][j][k | (1 << m)] = true;
                                }
                            }
                        } else if (!get(k, id[i] - 1)) {
                            dp[i + 1][j][k | (1 << (id[i] - 1))] = true;
                        }
                    } else {
                        if (id[i] == 0) {
                            if (j > 0) {
                                dp[i + 1][j - 1][k] = true;
                            }
                            for (int m = 0; m < count; ++m) {
                                if (get(k, m)) {
                                    dp[i + 1][j][k - (1 << m)] = true;
                                }
                            }
                        } else if (get(k, id[i] - 1)) {
                            dp[i + 1][j][k - (1 << (id[i] - 1))] = true;
                        }
                    }
                }
            }
        }
        
        int res = 10000;
        for (int j = 0; j < total; ++j) {
            for (int k = 0; k < stateCount; ++k) {
                if (!dp[N][j][k]) {
                    continue;
                }
                int temp = j;
                for (int m = 0; m < count; ++m) {
                    if (get(k, m)) {
                        ++temp;
                    }
                }
                res = Math.min(res, temp);
            }
        }
        return res == 10000 ? -1 : res;
    }
    
    public static void main(String[] args) throws Exception {
        FastScanner scan = new FastScanner(System.in);
        int taskCount = scan.nextInt();
        final int INSIDE = 1;
        final int OUTSIDE = -1;
        for (int taskIndex = 1; taskIndex <= taskCount; ++taskIndex) {
            Arrays.fill(state, 0);
            int N = scan.nextInt();
            char[] type = new char[N];
            int[] id = new int[N];
            for (int i = 0; i < N; ++i) {
                type[i] = scan.nextToken().charAt(0);
                id[i] = scan.nextInt();
            }
            int res = solve(type, id);
            
            if (res == -1) {
                System.out.println(String.format("Case #%d: CRIME TIME", taskIndex));
            } else {
                System.out.println(String.format("Case #%d: %d", taskIndex,
                        res));
            }
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
