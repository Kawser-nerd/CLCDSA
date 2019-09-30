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
    public static String docase() throws Exception {
        getInt() ;
	int[] v = getInts() ;
	int[] d = new int[v.length-1] ;
	for (int i=0; i<d.length; i++)
	    d[d.length-i-1] = (v[i+1]-v[i]+10007)%10007 ;
	int delta = 2 ;
	int s0 = 1 ;
	int s1 = 0 ;
	while (true) {
	    int d2 = delta / 2 ;
	    boolean okay = true ;
	    if (s1 + delta >= d.length)
		return "UNKNOWN" ;
	    for (int i=s0+delta; i<d.length; i += delta) {
		if (d[i] != d[s0])
		    okay = false ;
	    }
	    boolean okay2 = false ;
	    for (int i=s1; i<d.length; i += delta) {
		if (d[i] != d[s1])
		    okay2 = true ;
	    }
	    if (okay && okay2) {
		return ""+(v[v.length-1]+d[s0])%10007 ;
	    }
	    delta = delta * 2 ;
	    s0 = 2 * s0 + 1 ;
	    s1 = 2 * s1 + 1 ;
	}
    }
    public static void main(String[] args) throws Exception {
        int lim = getInt() ;
        for (int c=1; c<=lim; c++) {
            String r = docase() ;
            System.out.println("Case #" + c + ": " + r) ;
        }
    }
}