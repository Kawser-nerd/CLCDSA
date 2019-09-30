import java.util.*;

public class E {
    static long M = 10007;
    static long M(long x, long y) { return (x*y)%M; }
    static long A(long x, long y) { return (x+y)%M; }
    public static void main(String[] args) {
        F = new long[200];
        F[0] = 1;
        for(int i=1; i<200; i++)
            F[i] = M(F[i-1], i);

        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
CAS:
        for(int cas=1; cas<=T; cas++) {
            n = in.nextInt();
            A = new int[n];
            for(int i=0; i<n; i++)
                A[i] = in.nextInt();
            DP = new Long[(n+1)*n*n*n];
            INV = new boolean[n][n];
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    INV[i][j] = inv(i,j);

            long ans = 0;
            for(int kill=0; kill<n; kill++) {
                int cnt = 0;
                for(int i=0; i<n; i++)
                    if(INV[kill][i])
                        cnt++;
                for(int i=0; i<DP.length; i++)
                    DP[i] = null;
                ans = A(ans, f(-1, 0, 0, kill, cnt));
            }

            if(ans==0) ans=1;
            System.out.printf("Case #%d: %d\n", cas, ans);
        }
    }

    static boolean inv(int i, int j) {
        return (i<j && A[i]<A[j]) || (i>j && A[i]>A[j]);
    }
    static boolean sorted(int start, int ignore) {
        for(int i=start; i<n; i++) {
            int lo = i-1==ignore ? i-2 : i-1;
            if(lo>=0 && A[i]>A[lo]) return false;
        }
        return true; 
    }

    static Long[] DP;
    static boolean[][] INV;

    static int n;
    static int[] A;
    static long[] F;
    static long f(int min_i, int i, int nfired, int kill, int d) {
        if(d==0) return 0;
        if(i==n) return F[nfired];

        int key = (min_i+1)*n*n*n + i*n*n + nfired*n + d;
        if(DP[key]!=null) return DP[key];


        if(i==kill) return DP[key]=f(min_i, i+1, nfired, kill, d); //skip
        if(min_i >=0 && A[i]>A[min_i]) return DP[key]=f(min_i, i+1, nfired+1, kill, INV[kill][i]?d-1:d);
        else return DP[key]=A(
                f(min_i, i+1, nfired+1, kill, INV[kill][i]?d-1:d),
                f(i, i+1, nfired, kill, d));
    }
}
