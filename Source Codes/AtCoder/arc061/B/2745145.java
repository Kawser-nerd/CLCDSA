import java.io.*;
import java.util.*;

/**
 * @author baito
 */
class P  {
  int a, b;
  P (int a, int b) {
    this.a = a;
    this.b = b;
  }
 
  public int hashCode() {
    return a * 31 + b * 101;
  }
 
  public boolean equals(Object object) {
    P point = (P)object;
    return this.a == point.a && this.b == point.b;
  }
    // public boolean equals(P p){
    //     return this.a == p.a && this.b == p.b;
    // }

}

public class Main
{
    static StringBuilder sb = new StringBuilder();
    static FastScanner sc = new FastScanner(System.in);
    static int INF = 12345678;
    static long LINF = 123456789123456789L;
    static long MINF = -123456789123456789L;
    static long MOD = 1000000007;
    static int[] y4 = {0, 1, 0, -1};
    static int[] x4 = {1, 0, -1, 0};
    static int[] y9 = {0,0, 1, 0, -1, -1, 1, 1, -1};
    static int[] x9 = {0,1, 0, -1, 0, 1, -1, 1, -1};
    static long[] F;//factorial
    static boolean[] isPrime;
    static int[] primes;
    static char[][] map;

    static int H,W,N;
    static int[] A;

    public static void main(String[] args)
    {
        H = sc.nextInt();
        W = sc.nextInt();
        N = sc.nextInt();
        int[] x= new int[N];
        int[] y = new int[N];
        sc.nextIntArrays2arDec(y,x);
        Map<P,Integer> m= new HashMap<>();
        for(int i = 0; i<N;i++){
            int fx = x[i];
            int fy = y[i];
            for(int j = 0 ; j< 9;j++){
                int nx = fx+x9[j];
                int ny = fy+y9[j];
                if(nx < 1 || ny < 1)continue;
                if(nx >= W -1 || ny >= H -1)continue;
                P np = new P(nx,ny);
                
                Integer value;
                if(m.containsKey(np)){
                    value = m.get(np)+1;
                }else{
                    value = 1;
                }
               // System.out.println(nx+" "+ny+" "+value);
                //System.out.println(m.size());
                
               // m.put(np,value == null ? 1 : value + 1);
                m.put(np,value);
                
            }
        }
        long[] counts = new long[10];
        counts[0] = (long)(H-2)*(W-2)-m.size();
        for(Integer ite : m.values()){
            counts[ite]++;
        }
        for(int i = 0; i < 10; i++){
            System.out.println(counts[i]);
        }
        
        
        
    }


    public static boolean isOutofIndex(int x, int y)
    {
        if (x < 0 || y < 0) return true;
        if (map[0].length <= x || map.length <= y) return true;
        return false;
    }

    public static void setPrimes()
    {
        int n = 100001;
        isPrime = new boolean[n];
        List<Integer> prs = new ArrayList<>();
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= n; i++)
        {
            if (!isPrime[i]) continue;
            prs.add(i);
            for (int j = i * 2; j < n; j += i)
            {
                isPrime[j] = false;
            }
        }
        primes = new int[prs.size()];
        for (int i = 0; i < prs.size(); i++)
            primes[i] = prs.get(i);
    }

    public static void revSort(int[] a)
    {
        Arrays.sort(a);
        reverse(a);
    }

    public static void revSort(long[] a)
    {
        Arrays.sort(a);
        reverse(a);
    }

    public static int[][] copy(int[][] ar)
    {
        int[][] nr = new int[ar.length][ar[0].length];
        for (int i = 0; i < ar.length; i++)
            for (int j = 0; j < ar[0].length; j++)
                nr[i][j] = ar[i][j];
        return nr;
    }


    /**
     * <h1>???????????????????</h1>
     * <p>????????????????</p>
     *
     * @return<b>int</b> ? ???????????????????
     */
    public static int lowerBound(final int[] arr, final int value)
    {
        int low = 0;
        int high = arr.length;
        int mid;
        while (low < high)
        {
            mid = ((high - low) >>> 1) + low;    //(low + high) / 2 (?????????)
            if (arr[mid] < value)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }

    /**
     * <h1>?????????????????????</h1>
     * <p>????????????????</p>
     *
     * @return<b>int</b> ? ????????????????????
     */
    public static int upperBound(final int[] arr, final int value)
    {
        int low = 0;
        int high = arr.length;
        int mid;
        while (low < high)
        {
            mid = ((high - low) >>> 1) + low;    //(low + high) / 2 (?????????)
            if (arr[mid] <= value)
            {
                low = mid + 1;
            }
            else
            {
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
            if (A[pos] < A[pos + 1]) break;
        }
        if (pos == -1) return false;

        //pos??????????????
        int ok = pos + 1;
        int ng = len;
        while (Math.abs(ng - ok) > 1)
        {
            int mid = (ok + ng) / 2;
            if (A[mid] > A[pos]) ok = mid;
            else ng = mid;

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
            if (A[pos] > A[pos + 1]) break;
        }
        if (pos == -1) return false;

        //pos??????????????
        int ok = pos + 1;
        int ng = len;
        while (Math.abs(ng - ok) > 1)
        {
            int mid = (ok + ng) / 2;
            if (A[mid] < A[pos]) ok = mid;
            else ng = mid;

        }

        swap(A, pos, ok);
        reverse(A, pos + 1, len - 1);


        return true;
    }

    //?nCr?mod???????????***factorial(N)????????***
    static long ncr(int n, int r)
    {
        if (n < r) return 0;
        else if (r == 0) return 1;

        factorial(n);
        return F[n] / (F[n - r] * F[r]);
    }

    static long ncr2(int a, int b)
    {
        if (b == 0) return 1;
        else if (a < b) return 0;
        long res = 1;
        for (int i = 0; i < b; i++)
        {
            res *= a - i;
            res /= i + 1;
        }
        return res;
    }

    static long ncrdp(int n, int r)
    {
        if (n < r) return 0;
        long[][] dp = new long[n + 1][r + 1];
        for (int ni = 0; ni < n + 1; ni++)
        {
            dp[ni][0] = dp[ni][ni] = 1;
            for (int ri = 1; ri < ni; ri++)
            {
                dp[ni][ri] = dp[ni - 1][ri - 1] + dp[ni - 1][ri];
            }
        }
        return dp[n][r];
    }

    static long modNcr(int n, int r)
    {
        if (n < r) return 0;
        long result = F[n];
        result = result * modInv(F[n - r]) % MOD;
        result = result * modInv(F[r]) % MOD;
        return result;
    }

    public static long modSum(long... lar)
    {
        long res = 0;
        for (long l : lar)
            res = (res + l % MOD) % MOD;
        return res;
    }

    public static long modDiff(long a, long b)
    {
        long res = a - b;
        if (res < 0) res += MOD;
        res %= MOD;
        return res;
    }

    public static long modMul(long... lar)
    {
        long res = 1;
        for (long l : lar)
            res = (res * l) % MOD;
        if (res < 0) res += MOD;
        res %= MOD;
        return res;
    }

    public static long modDiv(long a, long b)
    {
        long x = a % MOD;
        long y = b % MOD;
        long res = (x * modInv(y)) % MOD;
        return res;
    }

    static long modInv(long n)
    {
        return modPow(n, MOD - 2);
    }

    static void factorial(int n)
    {
        F = new long[n + 1];
        F[0] = F[1] = 1;
//        for (int i = 2; i <= n; i++)
//        {
//            F[i] = (F[i - 1] * i) % MOD;
//        }
        //
        for (int i = 2; i <= 100000; i++)
        {
            F[i] = (F[i - 1] * i) % MOD;
        }
        for (int i = 100001; i <= n; i++)
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

    static int gcd(int n, int r)
    {
        return r == 0 ? n : gcd(r, n % r);
    }

    static long gcd(long n, long r)
    {
        return r == 0 ? n : gcd(r, n % r);
    }

    static <T> void swap(T[] x, int i, int j)
    {
        T t = x[i];
        x[i] = x[j];
        x[j] = t;
    }

    static void swap(int[] x, int i, int j)
    {
        int t = x[i];
        x[i] = x[j];
        x[j] = t;
    }

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

    public static void reverse(long[] x)
    {
        int l = 0;
        int r = x.length - 1;
        while (l < r)
        {
            long temp = x[l];
            x[l] = x[r];
            x[r] = temp;
            l++;
            r--;
        }
    }

    public static void reverse(int[] x, int s, int e)
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

    static int length(int a)
    {
        int cou = 0;
        while (a != 0)
        {
            a /= 10;
            cou++;
        }
        return cou;
    }

    static int length(long a)
    {
        int cou = 0;
        while (a != 0)
        {
            a /= 10;
            cou++;
        }
        return cou;
    }

    static int countC2(char[][] a, char c)
    {
        int co = 0;
        for (int i = 0; i < a.length; i++)
            for (int j = 0; j < a[0].length; j++)
                if (a[i][j] == c) co++;
        return co;
    }

    static int countI(int[] a, int key)
    {
        int co = 0;
        for (int i = 0; i < a.length; i++)
            if (a[i] == key) co++;
        return co;
    }

    static int countI(int[][] a, int key)
    {
        int co = 0;
        for (int i = 0; i < a.length; i++)
            for (int j = 0; j < a[0].length; j++)
                if (a[i][j] == key) co++;
        return co;
    }

    static void fill(int[][] a, int v)
    {
        for (int i = 0; i < a.length; i++)
            for (int j = 0; j < a[0].length; j++)
                a[i][j] = v;
    }


    static void fill(long[][] a, long v)
    {
        for (int i = 0; i < a.length; i++)
            for (int j = 0; j < a[0].length; j++)
                a[i][j] = v;
    }

    static void fill(int[][][] a, int v)
    {
        for (int i = 0; i < a.length; i++)
            for (int j = 0; j < a[0].length; j++)
                for (int k = 0; k < a[0][0].length; k++)
                    a[i][j][k] = v;
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
            res = Math.max(res, max(i));
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
            res = Math.min(res, min(i));
        return res;
    }

    static int sum(int[] a)
    {
        int cou = 0;
        for (int i : a)
            cou += i;
        return cou;
    }

    static int abs(int a)
    {
        return Math.abs(a);
    }

    static class FastScanner
    {

        private BufferedReader reader = null;
        private StringTokenizer tokenizer = null;

        public FastScanner(InputStream in)
        {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        public String next()
        {
            if (tokenizer == null || !tokenizer.hasMoreTokens())
            {
                try
                {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e)
                {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        /*public String nextChar(){
            return (char)next()[0];
        }*/
        public String nextLine()
        {
            if (tokenizer == null || !tokenizer.hasMoreTokens())
            {
                try
                {
                    return reader.readLine();
                } catch (IOException e)
                {
                    throw new RuntimeException(e);
                }
            }

            return tokenizer.nextToken("\n");
        }

        public long nextLong()
        {
            return Long.parseLong(next());
        }

        public int nextInt()
        {
            return Integer.parseInt(next());
        }

        public double nextDouble()
        {
            return Double.parseDouble(next());
        }

        public int[] nextIntArray(int n)
        {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = nextInt();
            }
            return a;
        }

        public int[] nextIntArrayDec(int n)
        {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = nextInt() - 1;
            }
            return a;
        }

        public int[][] nextIntArray2(int h, int w)
        {
            int[][] a = new int[h][w];
            for (int hi = 0; hi < h; hi++)
            {
                for (int wi = 0; wi < w; wi++)
                {
                    a[hi][wi] = nextInt();
                }
            }
            return a;
        }

        public int[][] nextIntArray2Dec(int h, int w)
        {
            int[][] a = new int[h][w];
            for (int hi = 0; hi < h; hi++)
            {
                for (int wi = 0; wi < w; wi++)
                {
                    a[hi][wi] = nextInt() - 1;
                }
            }
            return a;
        }

        //??????????
        public void nextIntArrays2ar(int[] a, int[] b)
        {
            for (int i = 0; i < a.length; i++)
            {
                a[i] = sc.nextInt();
                b[i] = sc.nextInt();
            }
        }

        public void nextIntArrays2arDec(int[] a, int[] b)
        {
            for (int i = 0; i < a.length; i++)
            {
                a[i] = sc.nextInt() - 1;
                b[i] = sc.nextInt() - 1;
            }
        }

        //??????????
        public void nextIntArrays3ar(int[] a, int[] b, int[] c)
        {
            for (int i = 0; i < a.length; i++)
            {
                a[i] = sc.nextInt();
                b[i] = sc.nextInt();
                c[i] = sc.nextInt();
            }
        }

        //??????????
        public void nextIntArrays3arDecLeft2(int[] a, int[] b, int[] c)
        {
            for (int i = 0; i < a.length; i++)
            {
                a[i] = sc.nextInt() - 1;
                b[i] = sc.nextInt() - 1;
                c[i] = sc.nextInt();
            }
        }

        public Integer[] nextIntegerArray(int n)
        {
            Integer[] a = new Integer[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = nextInt();
            }
            return a;
        }

        public char[] nextCharArray(int n)
        {
            char[] a = next().toCharArray();

            return a;
        }

        public char[][] nextCharArray2(int h, int w)
        {
            char[][] a = new char[h][w];
            for (int i = 0; i < h; i++)
            {
                a[i] = next().toCharArray();
            }
            return a;
        }

        //????????????
        public char[][] nextCharArray2s(int h, int w)
        {
            char[][] a = new char[h][w];
            for (int i = 0; i < h; i++)
            {
                a[i] = nextLine().replace(" ", "").toCharArray();
            }
            return a;
        }

        public char[][] nextWrapCharArray2(int h, int w, char c)
        {
            char[][] a = new char[h + 2][w + 2];
            //char c = '*';
            int i;
            for (i = 0; i < w + 2; i++)
                a[0][i] = c;
            for (i = 1; i < h + 1; i++)
            {
                a[i] = (c + next() + c).toCharArray();
            }
            for (i = 0; i < w + 2; i++)
                a[h + 1][i] = c;
            return a;
        }

        //???????????
        public char[][] nextWrapCharArray2s(int h, int w, char c)
        {
            char[][] a = new char[h + 2][w + 2];
            //char c = '*';
            int i;
            for (i = 0; i < w + 2; i++)
                a[0][i] = c;
            for (i = 1; i < h + 1; i++)
            {
                a[i] = (c + nextLine().replace(" ", "") + c).toCharArray();
            }
            for (i = 0; i < w + 2; i++)
                a[h + 1][i] = c;
            return a;
        }

        public long[] nextLongArray(int n)
        {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = nextLong();
            }
            return a;
        }

        public long[][] nextLongArray2(int h, int w)
        {
            long[][] a = new long[h][w];
            for (int hi = 0; hi < h; hi++)
            {
                for (int wi = 0; wi < h; wi++)
                {
                    a[h][w] = nextLong();
                }
            }
            return a;
        }
    }
}