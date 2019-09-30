import java.util.* ;
import java.io.* ;
public class r {
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
    static int s[][] = new int[100][100] ;
    static int w[][] = new int[100][100] ;
    static int tm[][] = new int[100][100] ;
    static long INF = 1000000000000000L ;
    static long encode(long t, int x, int y) {
        return (t << 10) + (y << 5) + x ;
    }
    public static void main(String[] args) throws Exception {
        int cnt = getInt() ;
        for (int c=1; c<=cnt; c++) {
            int[] f = getInts() ;
            int N = f[0] ;
            int M = f[1] ;
            for (int i=0; i<N; i++) {
                f = getInts() ;
                for (int j=0; j<M; j++) {
                    s[i][j] = f[j*3] ;
                    w[i][j] = f[j*3+1] ;
                    tm[i][j] = f[j*3+2] ;
                    tm[i][j] = (s[i][j] + w[i][j] - tm[i][j]) % (s[i][j] + w[i][j]) ;
                    tm[i][j] = (s[i][j] + w[i][j] + tm[i][j]) % (s[i][j] + w[i][j]) ;
                    if (tm[i][j] < 0)
                        throw new Exception("Bad mod calc") ;
                }
            }
            long a[][] = new long[100][100] ;
            for (int i=0; i<100; i++)
                for (int j=0; j<100; j++)
                    a[i][j] = INF ;
            TreeSet<Long> q = new TreeSet<Long>() ;
            q.add(encode(0, 2*N-1, 0)) ;
            a[2*N-1][0] = 0 ;
            while (q.size() > 0) {
                long v = q.first() ;
                q.remove(v) ;
                int x = (int)(v & 31) ;
                int y = (int)(((v >> 5) & 31)) ;
                long t = v >> 10 ;
                if (a[x][y] < t)
                    continue ;
                // walk
                int xx = ((x + 1) ^ 1) - 1 ;
                int yy = ((y + 1) ^ 1) - 1 ;
                if (xx >= 0 && xx < 2 * N && a[xx][y] > t + 2) {
                    a[xx][y] = t + 2 ;
                    q.add(encode(t+2, xx, y)) ;
                }
                if (yy >= 0 && yy < 2 * M && a[x][yy] > t + 2) {
                    a[x][yy] = t + 2 ;
                    q.add(encode(t+2, x, yy)) ;
                }
                // cross
                xx = x ^ 1 ;
                yy = y ^ 1 ;
                int i = xx >> 1 ;
                int j = yy >> 1 ;
                int m = (int)((t + tm[i][j]) % (s[i][j] + w[i][j])) ;
                int id = 1 ;
                int jd = 1 ;
                if (m < s[i][j]) {
                    jd = s[i][j] - m + 1 ;
                } else {
                    id = w[i][j] + s[i][j] - m + 1 ;
                }
                if (jd < 0 || id < 0)
                    throw new Exception("Bad val") ;
                if (a[xx][y] > t + id) {
                    a[xx][y] = t + id ;
                    q.add(encode(t+id, xx, y)) ;
                }
                if (a[x][yy] > t + jd) {
                    a[x][yy] = t + jd ;
                    q.add(encode(t+jd, x, yy)) ;
                }
            }
            System.out.println("Case #" + c + ": " + a[0][2*M-1]) ;
        }
    }
}