import java.io.* ;
import java.util.* ;
public class c {
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
    public static double[] getDoubs() throws Exception {
        String s[] = br.readLine().split(" ") ;
        double[] r = new double[s.length] ;
        for (int i=0; i<r.length; i++)
            r[i] = Double.parseDouble(s[i]) ;
        return r ;
    }
    static public class Thing implements Comparable {
	public Thing(long b, double v) {
	    val = v ;
	    bits = b ;
	}
	public boolean equal(Object o) {
	    if (!(o instanceof Thing))
		return false ;
	    return equal((Thing)o) ;
	}
	public boolean equal(Thing t) {
	    return (t.bits == bits) ;
	}
	public int compareTo(Thing t) {
	    if (t.val > val)
		return -1 ;
	    if (t.val < val)
		return 1 ;
	    if (t.bits < bits)
		return -1 ;
	    if (t.bits > bits)
		return 1 ;
	    return 0 ;
	}
	public int compareTo(Object o) {
	    if (!(o instanceof Thing))
		return -1 ;
	    return compareTo((Thing)o) ;
	}
	double val ;
	long bits ;
    }
    static TreeSet<Thing> q = new TreeSet<Thing>() ;
    static TreeSet<Long> done = new TreeSet<Long>() ;
    static double[][] a = null ;
    static double BIGBAD = 10000 ;
    public static String docase() throws Exception {
        int[] params = getInts() ;
	int M = params[0] ;
	int Q = params[1] ;
	q = new TreeSet<Thing>() ;
	done = new TreeSet<Long>() ;
	a = new double[Q][] ;
	for (int i=0; i<Q; i++) {
	    double probs[] = getDoubs() ;
	    for (int j=0; j<probs.length; j++)
		if (probs[j] == 0.0)
		    probs[j] = BIGBAD ;
		else
		    probs[j] = -Math.log(probs[j]) ;
	    Arrays.sort(probs) ;
	    a[i] = probs ;
	}
	double val = 0 ;
	for (int i=0; i<Q; i++)
	    val += a[i][0] ;
	q.add(new Thing(0, val)) ;
	done.add(0L) ;
	double r = 0 ;
	for (int tr=0; tr<M; tr++) {
	    if (q.size() == 0)
		break ;
	    Thing t = q.first() ;
	    q.remove(t) ;
	    r += Math.exp(-t.val) ;
	    long bm = t.bits ;
	    for (int i=0; i<Q; i++) {
		int o = (int)(((bm >> 2*i) & 3)) ;
		long nbm = bm + (1L << (2 * i)) ;
		if (o < 3 && a[i][o+1] < BIGBAD && !(done.contains(nbm))) {
		    q.add(new Thing(nbm,
				    t.val - a[i][o] + a[i][o+1])) ;
		    done.add(nbm) ;
		}
	    }
	}
	return "" + r ;
    }
    public static void main(String[] args) throws Exception {
        int lim = getInt() ;
        for (int c=1; c<=lim; c++) {
            String r = docase() ;
            System.out.println("Case #" + c + ": " + r) ;
        }
    }
}