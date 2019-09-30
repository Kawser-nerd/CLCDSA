import java.io.*;
import java.util.*;

/**
 * @author baito
 */
class RevComparator implements Comparator{
    @Override
    public int compare(Object o1,Object o2){
        return (int)o2 - (int)o1;
    }
}
public class Main
{
    static StringBuilder sb = new StringBuilder();
    static FastScanner sc = new FastScanner(System.in);
    static long MOD = 998244353;
    static long[] f;

    static int N;
    static int[] A;

    public static void main(String[] args)
    {
        N = sc.nextInt();
        A = sc.nextIntArray(N * 3);
        long cou = 0;
        PriorityQueue pq = new PriorityQueue();
        long[] memo = new long[N + 1];
        
        //???
        for(int i = 0 ; i < N; i++){
            pq.add(A[i]);
            //System.out.println("In : " + A[i]);
            cou += A[i];
        }
        memo[0] = cou;
        //System.out.println("memo[0] : " + memo[0]);
        for(int i = N,m = 1 ; i < 2 * N; i++,m++){
            pq.add(A[i]);
           // System.out.println("In : " + A[i]);
            int temp = (int)pq.poll();
            cou += A[i] - temp ;
            //System.out.println("out : " + temp);
            memo[m] = cou;
            //System.out.println("memo[" +m+"] : "+  memo[m]);
        }
        cou = 0;
        
        //????
        PriorityQueue pq2 = new PriorityQueue(new RevComparator());
        for(int i = 0 ; i < N; i++){
            pq2.add(A[3 * N - 1 - i ]);
            //System.out.println("In : " + A[3 * N - 1 - i ]);
            cou += A[3 * N - 1 - i ];
        }
        memo[N] -= cou;
        //System.out.println("memo[N] : " + memo[N]);
        for(int i = N,m = 1 ; i < 2 * N; i++,m++){
            pq2.add(A[3 * N - 1 - i]);
          //  System.out.println("In : " + A[3 * N - 1 - i]);
            int tem = (int)pq2.poll();
            //System.out.println("out : " + tem);
            cou += A[3 * N - 1 - i] - tem ;
            memo[N - m] -= cou;
            //System.out.println("memo[" +(N -m)+"] : "+  memo[N-m]);
        }
        long max = memo[0];
        //System.out.println("memo[" +0+"] : "+  memo[0]);
        for(int i = 1; i < N + 1; i++){
            max = Math.max(max,memo[i]);
           // System.out.println("memo[" +i+"] : "+  memo[i]);
        }
        System.out.println(max);
        
        
        
        
        
        
        
        
        
    }

    //?nCr?mod?????????
    static long comb(int n, int r)
    {
        long result = f[n];
        result = result * modInv(f[n - r]) % MOD;
        result = result * modInv(f[r]) % MOD;
        return result;
    }

    static long modInv(long n)
    {
        return modPow(n, MOD - 2);
    }

    static void factorial(int n)
    {
        f = new long[n + 1];
        f[0] = f[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            f[i] = (f[i - 1] * i) % MOD;
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

    static void fill(int[][] a, int v)
    {
        for (int i = 0; i < a.length; i++)
            for (int j = 0; j < a[0].length; j++)
                a[i][j] = v;
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.