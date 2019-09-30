import java.io.* ;
import java.util.* ;
public class d {
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
    static int map(int x, int y) {
	return 33 + x + y * 32 ;
    }
    static int[] dx = { -32, -1, 1, 32 } ;
    static void explor(int at, char[] b, int[] d) {
	boolean[] seen = new boolean[1024] ;
	int[] q = new int[4096] ;
	int qp = 0 ;
	int qg = 0 ;
	q[qp++] = at ;
	q[qp++] = 0 ;
	seen[at] = true ;
	while (qg < qp) {
	    at = q[qg++] ;
	    int dist = q[qg++] ;
	    if (d[at] > dist) {
		d[at] = dist ;
		for (int dir=0; dir<4; dir++)
		    if (b[at+dx[dir]] != 0 &&
			!seen[at+dx[dir]]) {
			q[qp++] = at+dx[dir] ;
			q[qp++] = dist + 1 ;
			seen[at+dx[dir]] = true ;
		    }
	    }
	}
    }
    public static int docase() throws Exception {
	int[] d = new int[1024] ;
	char[] b = new char[1024] ;
	int[] hw = getInts() ;
	boolean[] fin = new boolean[1024] ;
	int h = hw[0] ;
	int w = hw[1] ;
	for (int i=0; i<h; i++) {
	    String s = br.readLine() ;
	    for (int j=0; j<w; j++) {
		char c = s.charAt(j) ;
		if (c == 'T') {
		    b[map(i, j)] = 'F' ;
		} else if (c == '#') {
		    b[map(i, j)] = 'I' ;
		}
	    }
	}
	for (int i=0; i<1024; i++)
	    d[i] = 1000000 ;
	explor(map(0, 0), b, d) ;
	fin[map(0, 0)] = true ;
	int add = 0 ;
	while (true) {
	    int bestf = -1 ;
	    for (int i=0; i<1024; i++)
		if (b[i] == 'F' && !fin[i] && (bestf < 0 || d[i] < d[bestf]))
		    bestf = i ;
	    if (bestf < 0)
		break ;
	    int dd = d[bestf] ;
	    while (dd > 0) {
		add += dd ;
		dd -= 2 ;
	    }
	    fin[bestf] = true ;
	    explor(bestf, b, d) ;
	}
	int cst = 0 ;
	for (int i=0; i<1024; i++)
	    if (b[i] != 0)
		cst += d[i] ;
	return cst + add ;
    }
    public static void main(String[] args) throws Exception {
        int lim = getInt() ;
        for (int c=1; c<=lim; c++) {
            int r = docase() ;
            System.out.println("Case #" + c + ": " + r) ;
        }
    }
   
}