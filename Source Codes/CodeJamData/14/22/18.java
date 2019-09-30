import java.io.*;
import java.util.*;

public class Main {
    static final long MOD = 1000000007;
    
    static int[] getBits(int x) {
        int[] res = new int[31];
        for (int i = 0; i < 31; ++i) {
            res[i] = x % 2;
            x /= 2;
        }
        return res;
    }
    
    static long solve(int A, int B, int K) {
        long res = 0;
        int[] bits = getBits(A);
        int higher = 0;
        for (int i = bits.length - 1; i >= 0; --i) {
            if (bits[i] == 1) {
                res += solve(higher, i, B, K);
                higher |= 1 << i;
            }
        }
        return res;
    }
    
    static long solve(int AH, int AI, int B, int K) {
        long res = 0;
        int[] bits = getBits(B);
        int higher = 0;
        for (int i = bits.length - 1; i >= 0; --i) {
            if (bits[i] == 1) {
                res += solve(AH, AI, higher, i, K);
                higher |= 1 << i;
            }
        }
        return res;
    }
    
    static long solve(int AH, int AI, int BH, int BI, int KVal) {
        int[] A = getBits(AH);
        int[] B = getBits(BH);
        int[] K = getBits(KVal);
        long[][] dp = new long[32][2];
        dp[31][0] = 1;
        for (int i = A.length - 1; i >= 0; --i) {
            for (int j = 0; j < 2; ++j) {
                if (i >= AI && A[i] != j) {
                    continue;
                }
                for (int k = 0; k < 2; ++k) {
                    if (i >= BI && B[i] != k) {
                        continue;
                    }
                    dp[i][1] += dp[i + 1][1];
                    int current = j & k;
                    if (current > K[i]) {
                        continue;
                    } else if (current == K[i]) {
                        dp[i][0] += dp[i + 1][0];
                    } else {
                        dp[i][1] += dp[i + 1][0];
                    }
                }
            }
        }
        //System.out.println(AH + " " + AI + " " + BH + " " + BI + " " + dp[0][1]);
        return dp[0][1];
    }
    
    public static void main(String[] args) throws Exception {
        FastScanner scan = new FastScanner(System.in);
        int taskCount = scan.nextInt();
        for (int taskIndex = 1; taskIndex <= taskCount; ++taskIndex) {
            int A = scan.nextInt();
            int B = scan.nextInt();
            int K = scan.nextInt();
            System.out.println(String.format("Case #%d: %d", taskIndex, solve(A, B, K)));
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
    
    public String next() {
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