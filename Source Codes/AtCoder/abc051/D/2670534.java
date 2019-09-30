import java.io.*;
import java.util.*;

/**
 *
 * @author baito
 */
public class Main
{
    static StringBuilder sb = new StringBuilder();
    static FastScanner sc = new FastScanner(System.in);
    static int INF = 123456789;
    static long MOD =1000000007;
    static int[] y4 = {0,1,0,-1};
    static int[] x4 = {1,0,-1,0};
    static int[] y8 = {0,1,0,-1,-1,1,1,-1};
    static int[] x8 = {1,0,-1,0,1,-1,1,-1};
    static long[] F;//factorial
    static boolean[] isPrime;
    static int[] primes;

    static int N,M;
    static int[] a,b,c;
    static int[][]dist;

    public static void main(String[] args)
    {

        N = sc.nextInt();
        M = sc.nextInt();
        a = new int[M];
        b = new int[M];
        c = new int[M];
        dist = new int[N][N];
        //long,INF?????
        for (int i = 0; i < M; i++)
        {
            a[i ] = sc.nextInt()-1;
            b[i ] = sc.nextInt()-1;
            c[i ] = sc.nextInt();
        }
        fill(dist,INF);
        for (int i = 0; i < N; i++)
        {
            dist[i][i] = 0;
        }
        for (int i = 0; i < M; i++)
        {
            dist[a[i]][b[i]] = Math.min(dist[a[i]][b[i]],c[i]);
            dist[b[i]][a[i]] = Math.min(dist[b[i]][a[i]],c[i]);
        }

        //????
        for (int k = 0; k < N; k++)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    dist[i][j] = Math.min(dist[i][j],dist[i][k]+dist[k][j] );
                        }
            }
        }
        int cou = 0;
        for (int i = 0; i < M; i++)
        {
            if(dist[a[i]][b[i]] != c[i]){
                cou++;
            }
        }
        System.out.println(cou);


    }
    public static long sumMod(long... lar)
    {
        long sum = 0;
        for (long l : lar)
            sum = (sum + l % MOD) % MOD;
        return sum;
    }
    /**<h1>???????????????????</h1>
     * <p>????????????????</p>
     * @return<b>int</b> ? ???????????????????
     */
    public static int lowerBound(final int[] arr, final int value) {
        int low = 0;
        int high = arr.length;
        int mid;
        while (low < high) {
            mid = ((high - low) >>> 1) + low;    //(low + high) / 2 (?????????)
            if (arr[mid] < value) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    /**<h1>?????????????????????</h1>
     * <p>????????????????</p>
     * @return<b>int</b> ? ????????????????????
     */
    public static int upperBound(final int[] arr, final int value) {
        int low = 0;
        int high = arr.length;
        int mid;
        while (low < high) {
            mid = ((high - low) >>> 1) + low;    //(low + high) / 2 (?????????)
            if (arr[mid] <= value) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
    //????????????????false???
    public static boolean nextPermutation(int A[])
    {
        int len = A.length;
        int pos = len - 2;
        for (; pos >= 0; pos--)
        {
            if (A[pos] < A[pos + 1])
                break;
        }
        if (pos == -1)
            return false;

        //pos??????????????
        int ok = pos + 1;
        int ng = len;
        while (Math.abs(ng - ok) > 1)
        {
            int mid = (ok + ng) / 2;
            if (A[mid] > A[pos])
                ok = mid;
            else
                ng = mid;

        }

        swap(A, pos, ok);
        reverse(A, pos + 1, len - 1);


        return true;
    }
    //????????????????false???
    public static boolean prevPermutation(int A[])
    {
        int len = A.length;
        int pos = len - 2;
        for (; pos >= 0; pos--)
        {
            if (A[pos] > A[pos + 1])
                break;
        }
        if (pos == -1)
            return false;

        //pos??????????????
        int ok = pos + 1;
        int ng = len;
        while (Math.abs(ng - ok) > 1)
        {
            int mid = (ok + ng) / 2;
            if (A[mid] < A[pos])
                ok = mid;
            else
                ng = mid;

        }

        swap(A, pos, ok);
        reverse(A, pos + 1, len - 1);


        return true;
    }
    //?nCr?mod???????????***factorial(N)????????***
    static long ncr(int n, int r)
    {
        factorial(n);
        return F[n] / (F[n - r] * F[r]);
    }
    static long modNcr(int n, int r)
    {
        long result = F[n];
        result = result * modInv(F[n - r]) % MOD;
        result = result * modInv(F[r]) % MOD;
        return result;
    }

    static long modInv(long n)
    {
        return modPow(n, MOD - 2);
    }

    static void factorial(int n)
    {
        F = new long[n + 1];
        F[0] = F[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            F[i] = (F[i - 1] * i) % MOD;
        }
    }

    static long modPow(long x, long n)
    {
        long res = 1L;
        while (n > 0)
        {
            if ((n & 1) == 1)
            {
                res = res * x % MOD;
            }
            x = x * x % MOD;
            n >>= 1;
        }
        return res;
    }

    //?nCr?mod?????????

    static int gcd(int n, int r) { return r == 0 ? n : gcd(r, n%r); }
    static long gcd(long n, long r) { return r == 0 ? n : gcd(r, n%r); }

    static <T> void swap(T[] x, int i, int j) { T t = x[i]; x[i] = x[j]; x[j] = t; }
    static void swap(int[] x, int i, int j) { int t = x[i]; x[i] = x[j]; x[j] = t; }
    public static void reverse(int[] x)
    {
        int l = 0;
        int r = x.length - 1;
        while (l < r)
        {
            int temp = x[l];
            x[l] = x[r];
            x[r] = temp;
            l++;
            r--;
        }
    }
    public static void reverse(int[] x,int s, int e)
    {
        int l = s;
        int r = e;
        while (l < r)
        {
            int temp = x[l];
            x[l] = x[r];
            x[r] = temp;
            l++;
            r--;
        }
    }
    static int length(int a) {int cou = 0; while(a != 0){ a /= 10; cou++; } return cou;}
    static int length(long a) {int cou = 0; while(a != 0){ a /= 10; cou++; } return cou;}
    static int countC2(char[][] a, char c){
        int co = 0;
        for (int i = 0; i < a.length; i++)
            for (int j = 0; j < a[0].length; j++)
                if(a[i][j] == c)
                    co++;
        return co;
    }
    static void fill(int[][] a, int v){
        for (int i = 0; i < a.length; i++)
            for (int j = 0; j < a[0].length; j++)
                a[i][j] = v;
    }
    static int max(int a, int b, int c)
    {
        return Math.max(a, Math.max(b, c));
    }

    static int max(int[] ar)
    {
        int res = Integer.MIN_VALUE;
        for (int i : ar)
            res = Math.max(res, i);
        return res;
    }
    static int max(int[][] ar)
    {
        int res = Integer.MIN_VALUE;
        for (int i[] : ar)
            res = max(i);
        return res;
    }
    static int min(int a, int b, int c)
    {
        return Math.min(a, Math.min(b, c));
    }
    static int min(int[] ar)
    {
        int res = Integer.MAX_VALUE;
        for (int i : ar)
            res = Math.min(res, i);
        return res;
    }
    static int min(int[][] ar)
    {
        int res = Integer.MAX_VALUE;
        for (int i[] : ar)
            res = min(i);
        return res;
    }
    static int abs(int a){
        return Math.abs(a);
    }
    static class FastScanner {

        private BufferedReader reader = null;
        private StringTokenizer tokenizer = null;

        public FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        public String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        /*public String nextChar(){
            return (char)next()[0];
        }*/
        public String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }

            return tokenizer.nextToken("\n");
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            return a;
        }
        public int [][] nextIntArray2(int h, int w){
            int[][] a = new int[h][w];
            for(int hi = 0 ; hi < h ; hi++){
                for(int wi = 0 ; wi < w ; wi++){
                    a[hi][wi] = nextInt();
                }
            }
            return a;
        }
        public int[] nextIntArray21(int n, int scalar)
        {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt() * scalar + nextInt();
            return a;
        }
        public Integer[] nextIntegerArray(int n) {
            Integer[] a = new Integer[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            return a;
        }
        public char[] nextCharArray(int n){
            char[] a = next().toCharArray();

            return a;
        }
        public char[][] nextCharArray2(int h , int w){
            char[][] a = new char[h][w];
            for (int i = 0; i < h; i++) {
                a[i] = next().toCharArray();
            }
            return a;
        }
        //????????????
        public char[][] nextCharArray2s(int h , int w){
            char[][] a = new char[h][w];
            for (int i = 0; i < h; i++) {
                a[i] = nextLine().replace(" ","").toCharArray();
            }
            return a;
        }
        public char[][] nextWrapCharArray2(int h , int w, char c){
            char[][] a = new char[h + 2][w + 2];
            //char c = '*';
            int i;
            for (i = 0; i < w + 2; i++)
                a[0][i] = c;
            for (i = 1; i < h + 1; i++) {
                a[i] = (c + next() + c).toCharArray();
            }
            for (i = 0; i < w + 2; i++)
                a[h + 1][i] = c;
            return a;
        }
        //???????????
        public char[][] nextWrapCharArray2s(int h , int w ,char c){
            char[][] a = new char[h + 2][w + 2];
            //char c = '*';
            int i;
            for (i = 0; i < w + 2; i++)
                a[0][i] = c;
            for (i = 1; i < h + 1; i++) {
                a[i] = (c + nextLine().replace(" ","") + c).toCharArray();
            }
            for (i = 0; i < w + 2; i++)
                a[h + 1][i] = c;
            return a;
        }
        public long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextLong();
            }
            return a;
        }
        public long [][] nextLongArray2(int h, int w){
            long[][] a = new long[h][w];
            for(int hi = 0 ; hi < h ; hi++){
                for(int wi = 0 ; wi < h ; wi++){
                    a[h][w] = nextLong();
                }
            }
            return a;
        }
    }
}