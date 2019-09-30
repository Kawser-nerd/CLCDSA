import java.io.* ;
import java.util.* ;
public class a {
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
    static final int F = 10000 ;
    public static int docase() throws Exception {
	int n = getInt() ;
	int[][] w = new int[n][] ;
	boolean[][] hit = new boolean[F+1][3] ;
	for (int i=0; i<n; i++) {
	    w[i] = getInts() ;
	    for (int j=0; j<3; j++)
		hit[w[i][j]][j] = true ;
	}
	int r = 0 ;
	for (int a=0; a<=F; a++)
	    if (hit[a][0]) {
		int[] cnt = new int[F+2] ;
		for (int i=0; i<n; i++)
		    if (w[i][0] <= a && a + w[i][1] + w[i][2] <= F) {
			cnt[w[i][1]]++ ;
			cnt[F-a-w[i][2]+1]-- ;
		    }
		int s = 0 ;
		for (int i=0; i<=F; i++) {
		    s += cnt[i] ;
		    r = Math.max(r, s) ;
		}
	    }
	return r ;
    }
    public static void main(String[] args) throws Exception {
        int lim = getInt() ;
        for (int c=1; c<=lim; c++) {
            int r = docase() ;
            System.out.println("Case #" + c + ": " + r) ;
        }
    }
   
}