import java.io.* ;
import java.util.* ;
public class p2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in)) ;
    public static int getInt() throws Exception {
        return Integer.parseInt(br.readLine()) ;
    }
    public static int[] getInts() throws Exception {
        String s[] = br.readLine().split(" ") ;
        int[] r = new int[s.length] ;
        for (int i=0; i<r.length; i++)
            r[i] = Integer.parseInt(s[i]) ;
        return r ;
    }
    public static String solve(int N, int M, int A, boolean flip)
        throws Exception {
        if (N < M)
            return solve(M, N, A, true) ;
        int y1 = M ;
        int x1 = (A + M - 1) / M ;
        int left = x1 * y1 - A ;
        int y2 = 1 ;
        int x2 = left ;
        if (y1 < 0 || y1 > M || y2 < 0 || y2 > M || x1 < 0 || x1 > N ||
            x2 < 0 || x2 > N || (x1*y1-x2*y2 != A))
            throw new Exception("BAD") ;
        if (flip)
            return "0 0 " + y1 + " " + x2 + " " + y2 + " " + x1 ;
        else
            return "0 0 " + x2 + " " + y1 + " " + x1 + " " + y2 ;
    }
    public static String docase() throws Exception {
        int[] f = getInts() ;
        int N = f[0] ;
        int M = f[1] ;
        int A = f[2] ;
        if (N*M<A)
            return "IMPOSSIBLE" ;
        return solve(N, M, A, false) ;
    }
    public static void main(String[] args) throws Exception {
        int lim = getInt() ;
        for (int c=1; c<=lim; c++) {
            String r = docase() ;
            System.out.println("Case #" + c + ": " + r) ;
        }
    }
}