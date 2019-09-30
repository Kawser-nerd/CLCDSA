import java.io.* ;
import java.util.* ;
public class p3 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in)) ;
    public static int getInt() throws Exception {
        return Integer.parseInt(br.readLine()) ;
    }
    static int adj[][] ;
    static int end[][] ;
    static int cost[][][] ;
    final static int INF = 1000000000 ;
    static int solve() throws Exception {
        int N = getInt() ;
        String s = br.readLine() ;
        char[] bb = s.toCharArray() ;
        adj = new int[N][N] ;
        end = new int[N][N] ;
        for (int i=0; i<N; i++)
            for (int j=i+1; j<N; j++) {
                for (int off=0; off<bb.length; off+=N) {
                    if (bb[off+i] != bb[off+j])
                        adj[i][j]++ ;
                }
                for (int off=0; off+N<bb.length; off+=N) {
                    if (bb[off+i] != bb[off+N+j])
                        end[i][j]++ ;
                    if (bb[off+j] != bb[off+N+i])
                        end[j][i]++ ;
                }
                adj[j][i] = adj[i][j] ;
            }
        int p = 1<<N ;
        cost = new int[p][N][N] ;
        for (int i=0; i<p; i++) {
            int t = i & (i - 1) ;
            if (t == 0)
                continue ;
            for (int b=0; b<N; b++)
                for (int e=0; e<N; e++)
                    cost[i][b][e] = INF ;
            for (int ne=0; ne<N; ne++) {
                if (((i >> ne) & 1) == 0)
                    continue ;
                int obm = i - (1 << ne) ;
                for (int b=0; b<N; b++) {
                    if (((obm >> b) & 1) == 0)
                        continue ;
                    for (int e=0; e<N; e++) {
                        if (((obm >> e) & 1) == 0)
                            continue ;
                        cost[i][b][ne] = Math.min(cost[i][b][ne],
                                                cost[obm][b][e] + adj[e][ne]) ;
                    }
                }
            }
        }
        int r = INF ;
        int bm = p - 1 ;
        for (int b=0; b<N; b++)
            for (int e=0; e<N; e++)
                if (e != b)
                    r = Math.min(r, cost[bm][b][e] + end[e][b]) ;
        return r + 1 ;
    }
    public static void main(String[] args) throws Exception {
        int lim = getInt() ;
        for (int c=1; c<=lim; c++) {
            int r = solve() ;
            System.out.println("Case #" + c + ": " + r) ;
        }
    }
}