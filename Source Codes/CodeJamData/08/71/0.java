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
    public static HashMap<String, String[]> find ;
    public static HashMap<String, Integer> costs ;
    public static int cost(String f) {
	if (f.charAt(0) > 'Z')
	    return 0 ; // ingredients are free
	if (costs.get(f) != null)
	    return costs.get(f) ;
	String[] comp = find.get(f) ;
	Vector<Integer> a = new Vector<Integer>() ;
	for (int i=2; i<comp.length; i++) {
	    if (comp[i].charAt(0) > 'Z') { // ingredient; skip
	    } else {
		a.add(cost(comp[i])) ;
	    }
	}
	int r = 1 ;
	Collections.sort(a) ;
	for (int i=0; i<a.size(); i++) {
	    int t = a.size() - i + 1 ;
	    r = Math.max(t, r) ;
	    t = a.get(i) + a.size() - i - 1 ;
	    r = Math.max(t, r) ;
	}
	//	System.out.println("To make " + f + " requires " + r) ;
	return r ;
    }
    public static int docase() throws Exception {
        int M = getInt() ;
	String makeme = null ;
	find = new HashMap<String, String[]>() ;
	costs = new HashMap<String, Integer>() ;
	for (int i=0; i<M; i++) {
            String f[] = br.readLine().split(" ") ;
	    find.put(f[0], f) ;
	    if (makeme == null)
		makeme = f[0] ;
	}
	return cost(makeme) ;
    }
    public static void main(String[] args) throws Exception {
        int lim = getInt() ;
        for (int c=1; c<=lim; c++) {
            int r = docase() ;
            System.out.println("Case #" + c + ": " + r) ;
        }
    }
}