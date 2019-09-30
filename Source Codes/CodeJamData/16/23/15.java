import java.io.PrintWriter;
import java.util.*;

/**
 * Created by Chushuhuch on 12.04.14.
 */
public class C {

    private static void solve() {
        int tn = in.nextInt();
        for ( int test = 1; test <= tn; test ++ ) {
            int en = in.nextInt();
            String[][] words = new String[en][2];
            HashMap<String, Integer> first = new HashMap<>();
            HashMap<String, Integer> second = new HashMap<>();
            int curFirst = 0;
            int curSecond = 0;
            for ( int i = 0; i < en; i ++ ) {
                words[i][0] = in.next();
                if ( ! first.containsKey( words[i][0] ) ) {
                    first.put( words[i][0], curFirst ++ );
                }
                words[i][1] = in.next();
                if ( ! second.containsKey( words[i][1] ) ) {
                    second.put( words[i][1], curSecond ++ );
                }
            }
            int m = first.size();
            int n = second.size();
            ArrayList<ArrayList<Integer>> e = new ArrayList<>( m );
            for ( int i = 0; i < m; i ++ ) {
                e.add( new ArrayList<>() );
            }
            for ( int i = 0; i < en; i ++ ) {
                e.get( first.get( words[i][0] ) ).add( second.get( words[i][1] ) );
            }
            int r = m;
            int[] up = new int[n];
            Arrays.fill( up, -1 );
            for ( int i = 0; i < m; i ++ ) {
                dfs( i, new boolean[m], up, e );
            }
            for ( int i = 0; i < n; i ++ ) {
                if ( up[i] < 0 ) {
                    r ++;
                }
            }
            out.println( "Case #" + test + ": " + ( en - r ) );
        }
    }

    private static boolean dfs( int v, boolean[] g, int[] up, ArrayList<ArrayList<Integer>> e ) {
        if ( g[v] ) return false;
        g[v] = true;
        for ( int to : e.get( v ) ) {
            if ( up[to] < 0 || dfs( up[to], g, up, e ) ) {
                up[to] = v;
                return true;
            }
        }
        return false;
    }

    private static Scanner in;
    private static PrintWriter out;

    public static void main( String[] args ) {
        Locale.setDefault(Locale.US);
        in = new Scanner( System.in );
        out = new PrintWriter( System.out );
        solve();
        out.close();
    }
}
