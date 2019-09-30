import java.io.* ;
import java.util.* ;
public class p1 {
    static BufferedReader br = new BufferedReader(
                                       new InputStreamReader(System.in)) ;
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
    final static int BIG = 12000 ;
    static int val[] ;
    static boolean c[] ;
    static char op[] ;
    static int mcx[] ;
    static int M, V ;
    static String solveone() throws Exception {
        val = new int[BIG] ;
        c = new boolean[BIG] ;
        op = new char[BIG] ;
        mcx = new int[BIG] ;
        int[] f = getInts() ;
        M = f[0] ;
        V = f[1] ;
        int b = (M-1)/2 ;
        for (int i=1; i<=M; i++) {
            if (i<=b) {
                f = getInts() ;
                if (f[0] == 0)
                    op[i] = 'o' ;
                else
                    op[i] = 'a' ;
                if (f[1] == 0)
                    c[i] = false ;
                else
                    c[i] = true ;
            } else {
                val[i] = getInt() ;
                mcx[i] = BIG ;
            }
        }
        for (int i=b; i>0; i--) {
            if (op[i] == 'a')
                val[i] = val[2*i] & val[2*i+1] ;
            else
                val[i] = val[2*i] | val[2*i+1] ;
            mcx[i] = BIG ;
            for (int t=0; t<8; t++) {
                int va = val[2*i] ;
                int vb = val[2*i+1] ;
                int mop = op[i] ;
                int cost = 0 ;
                if (((t >> 0) & 1) != 0) {
                    va = 1 - va ;
                    cost += mcx[2*i] ;
                }
                if (((t >> 1) & 1) != 0) {
                    vb = 1 - vb ;
                    cost += mcx[2*i+1] ;
                }
                if (((t >> 2) & 1) != 0) {
                    mop = (char)('a' + 'o' - mop) ;
                    if (c[i])
                        cost += 1 ;
                    else
                        cost += BIG ;
                }
                if (cost < BIG) {
                    int nv ;
                    if (mop == 'a')
                        nv = va & vb ;
                    else
                        nv = va | vb ;
                    if (nv != val[i])
                        mcx[i] = Math.min(mcx[i], cost) ;
                }
            }
        }
        if (V == val[1])
            return "0" ;
        if (mcx[1] >= BIG)
            return "IMPOSSIBLE" ;
        return "" + mcx[1] ;
    }
    public static void main(String[] args) throws Exception {
        int lim = getInt() ;
        for (int c=1; c<=lim; c++) {
            String r = solveone() ;
            System.out.println("Case #" + c + ": " + r) ;
        }
    }
}