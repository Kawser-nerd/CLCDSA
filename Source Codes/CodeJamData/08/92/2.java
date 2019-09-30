import java.io.* ;
import java.util.* ;
public class b {
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
    public static long docase() throws Exception {
	int[] f = getInts() ;
	int w = f[0] ;
	int h = f[1] ;
	int[] v1 = getInts() ;
	int[] v2 = getInts() ;
	int v1x = v1[0] ;
	int v2x = v2[0] ;
	int v1y = v1[1] ;
	int v2y = v2[1] ;
	int[] start = getInts() ;
	int startx = start[0] ;
	int starty = start[1] ;
	long r = 0 ;
	if (startx < 0 || startx >= w ||
	    starty < 0 || starty >= h)
	    return 0 ;
	if (v1x * v2y == v1y * v2x) { // collinear case
	    if (v1x == 0) {
		int t = w ;
		w = h ;
		h = t ;
		t = v1x ;
		v1x = v1y ;
		v1y = t ;
		t = v2x ;
		v2x = v2y ;
		v2y = t ;
		t = startx ;
		startx = starty ;
		starty = t ;
	    }
	    boolean seen[] = new boolean[w] ;
	    int q[] = new int[(h+w)*3] ;
	    int qp = 0 ;
	    int qg = 0 ;
	    q[qp++] = startx ;
	    q[qp++] = starty ;
	    seen[startx] = true ;
	    r = 1 ;
	    while (qg < qp) {
		int atx = q[qg++] ;
		int aty = q[qg++] ;
		if (atx + v1x >= 0 && atx + v1x < w && !seen[atx+v1x] &&
		    aty + v1y >= 0 && aty + v1y < h) {
		    q[qp++] = atx + v1x ;
		    q[qp++] = aty + v1y ;
		    seen[atx+v1x] = true ;
		    r++ ;
		}
		if (atx + v2x >= 0 && atx + v2x < w && !seen[atx+v2x] &&
		    aty + v2y >= 0 && aty + v2y < h) {
		    q[qp++] = atx + v2x ;
		    q[qp++] = aty + v2y ;
		    seen[atx+v2x] = true ;
		    r++ ;
		}
	    }
	    return r ;
	} else {
	    int sx = v1x + v2x ;
	    int sy = v1y + v2y ;
	    r = 1 ;
	    int lox = startx ;
	    int hix = startx ;
	    int loy = starty ;
	    int hiy = starty ;
	    long ww = 1 ;
	    while (true) {
		lox += v1x ;
		loy += v1y ;
		hix += v2x ;
		hiy += v2y ;
		ww++ ;
		while (lox < 0 || loy < 0 || lox >= w || loy >= h) {
		    lox += v2x - v1x ;
		    loy += v2y - v1y ;
		    ww-- ;
		    if (lox == hix && loy == hiy)
			break ;
		}
		while (hix < 0 || hiy < 0 || hix >= w || hiy >= h) {
		    if (lox == hix && loy == hiy)
			break ;
		    hix += v1x - v2x ;
		    hiy += v1y - v2y ;
		    ww-- ;
		    if (lox == hix || loy == hiy)
			break ;
		}
		if (lox < 0 || loy < 0 || hix < 0 || hiy < 0 ||
		    lox >= w || hix >= w || loy >= h || hiy >= h)
		    break ;
		r += ww ;
	    }
	    return r ;
	}
    }
    public static void main(String[] args) throws Exception {
        int lim = getInt() ;
        for (int c=1; c<=lim; c++) {
            long r = docase() ;
            System.out.println("Case #" + c + ": " + r) ;
        }
    }
   
}