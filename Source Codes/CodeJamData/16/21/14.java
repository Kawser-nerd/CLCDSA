import java.io.PrintWriter;
import java.util.*;
import java.util.stream.Stream;

/**
 * Created by Chushuhuch on 12.04.14.
 */
public class A {

    final private static char[][] DIGITS = Arrays.stream( new String[] { "ZERO", "TWO", "FOUR", "SIX", "EIGHT", "THREE", "ONE", "FIVE", "SEVEN", "INNE" } ).map( String::toCharArray ).toArray( char[][]::new );
    final private static int[] NUMBERS = new int[] { 0, 2, 4, 6, 8, 3, 1, 5, 7, 9 };

    private static void solve() {
        int tn = in.nextInt();
        for ( int test = 1; test <= tn; test ++ ) {
            char[] c = in.next().toCharArray();
            int[] cnt = new int[26];
            for ( char d : c ) {
                cnt[d - 'A'] ++;
            }
            ArrayList<Character> r = new ArrayList<>();
            for ( int i = 0; i < DIGITS.length; i ++ ) {
                int ch = -1;
                for ( int j = 0; j < DIGITS[i].length; j ++ ) {
                    boolean found = false;
                    for ( int k = i + 1; k < DIGITS.length; k ++ ) {
                        found |= new String( DIGITS[k] ).contains( "" + DIGITS[i][j] );
                    }
                    if ( ! found ) {
                        ch = DIGITS[i][j] - 'A';
                        break;
                    }
                }
                if ( ch < 0 ) {
                    throw new RuntimeException();
                }
                int count = 0;
                for ( int j = 0; j < DIGITS[i].length; j ++ ) {
                    if ( DIGITS[i][j] == ch + 'A' ) {
                        count ++;
                    }
                }
                if ( count != 1 ) {
                    System.out.println( ( char ) ( 'A' + ch ) + " " + new String( DIGITS[i] ) );
                    throw new RuntimeException();
                }
                int times = cnt[ch];
                for ( int j = 0; j < DIGITS[i].length; j ++ ) {
                    cnt[DIGITS[i][j] - 'A'] -= times;
                }
                for ( int j = 0; j < times; j ++ ) {
                    r.add( ( char ) ( '0' + NUMBERS[i] ) );
                }
            }
            StringBuilder res = new StringBuilder();
            r.stream().sorted().forEach( res::append );
            out.println( "Case #" + test + ": " + res );
        }
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
