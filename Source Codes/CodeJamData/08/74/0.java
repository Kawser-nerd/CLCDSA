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
    static int base = 9 ;
    static int[] moves = new int[] { -9, -8, -7, -1, 1, 7, 8, 9 } ;
    static int map(int x, int y) {
	return base + x + 8 * y ;
    }
    static HashMap<String, Boolean> hm ;
    static boolean win(int k, long board) {
	String key = "" + k + " " + board ;
	if (hm.get(key) != null)
	    return hm.get(key) ;
	boolean iswin = false ;
	long nb = board | (1L << k) ;
	for (int i=0; i<moves.length; i++) {
	    int d = moves[i] ;
	    if (((board >> (d + k)) & 1) == 0) {
		if (!win(k+d, nb)) {
		    iswin = true ;
		}
	    }
	}
	hm.put(key, iswin) ;
	//	System.out.println("Win of " + k + " " + board + " is " + iswin) ;
	return iswin ;
    }
    public static String docase() throws Exception {
	hm = new HashMap<String, Boolean>() ;
	int[] v = getInts() ;
	int R = v[0] ;
	int C = v[1] ;
	long board = -1L ;
	int king = 0 ;
	for (int i=0; i<R; i++) {
	    String s = br.readLine() ;
	    for (int j=0; j<C; j++) {
		int c = s.charAt(j) ;
		if (c == 'K')
		    king = map(i, j) ;
		else if (c == '.')
		    board &= ~(1L << map(i, j)) ;
	    }
	}
	if (win(king, board))
	    return "A" ;
	else
	    return "B" ;
    }
    public static void main(String[] args) throws Exception {
        int lim = getInt() ;
        for (int c=1; c<=lim; c++) {
            String r = docase() ;
            System.out.println("Case #" + c + ": " + r) ;
        }
    }
}