import java.io.*;
import java.util.*;
import java.math.*;
 
class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static PrintWriter pw = new PrintWriter(System.out);
    public static String line;
    public static StringTokenizer st;
    public static ArrayList<ArrayList<Integer>> adjList;
    public static int[] dx = {-1, 0, 1, 0, -1, 1, 1, -1, 0};
    public static int[] dy = {0, 1, 0, -1, 1, 1, -1, -1, 0};
    public static int INF = 0x3f3f3f3f;
    public static int MOD = 1000000007;
    public static long LINF = 0x3f3f3f3f3f3f3f3fL;

    public static long[] fact, inv;

    public static long nCr(int N, int R) {
        if (R < 0 || R > N) return 0;
        return (( fact[N] * inv[R] % MOD ) * inv[N-R]) % MOD;
    }

    public static void main(String[] args) throws Exception {
        int N = Integer.parseInt(br.readLine());
        fact = new long[N+1];
        inv = new long[N+1];
        
        fact[0] = 1;
        inv[0] = 1;
        BigInteger BIMOD = BigInteger.valueOf(MOD);
        for (int i = 1; i <= N; i++) {
            fact[i] = (i * fact[i-1]) % MOD;
            inv[i] = BigInteger.valueOf(fact[i]).modInverse(BIMOD).longValue();
        }
        // System.out.println(inv[1]);
        long ans = 0;
        long prev = 0;
        for (int K = 1; K <= N; K++) {
            if (N - K - 1 < 0) break;
            long n = ((nCr(K-1, N-K-1) * fact[K] % MOD) * fact[N-K-1]) % MOD;
            long times = ( n - prev + MOD ) % MOD;
            prev = n;
            ans = ans + ((times * K) % MOD);
            ans %= MOD;
        }
        pw.println(ans);

        pw.close(); 
        br.close();
    }
}

class Point implements Comparable<Point>{
    public int x, y;
 
    Point(int _x, int _y){
        x = _x;
        y = _y;
    }
 
    public String toString(){
        return x + " " + y;
    }

    public int compareTo(Point p){
        if (x != p.x) return x < p.x ? -1 : 1;
        if (y != p.y) return y < p.y ? -1 : 1;
        return 0;
    }
}