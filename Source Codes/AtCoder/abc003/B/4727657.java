import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String S = sc.next();
	String T = sc.next();
	boolean f = true;
	String card = "atcoder";
	for ( int i = 0; i < S.length(); i++ ) {
	    if ( S.charAt(i) == T.charAt(i) ) {
		continue;
	    }else if ( S.charAt(i) == '@' ) {
		boolean ok = false;
		for ( int j = 0; j < card.length(); j++ ) {
		    if ( T.charAt(i) == card.charAt(j) ) ok = true;
		}
		if (ok == false) f = false;
	    } else  if ( T.charAt(i) == '@' ) {

		boolean ok = false;
		for ( int j = 0; j < card.length(); j++ ) {
		    if ( S.charAt(i) == card.charAt(j) ) ok = true;
		}
		if (ok == false) f = false;

	    } else if ( S.charAt(i) != T.charAt(i) ) f = false;
	}
	if(f) System.out.println("You can win");
	else System.out.println("You will lose");
    }
}