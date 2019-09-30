import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String[] S = new String[12];
	for ( int i = 0; i < 12; i++ ) {
	    S[i] = sc.next();
	}
	int ans = 0;
	for ( int i = 0; i < 12; i++ ) {
	    boolean f = false;
	    for ( int j = 0; j < S[i].length(); j++ ) {
		if ( S[i].charAt(j) == 'r' ) f = true;
	    }
	    if(f) ans++;
	}
	System.out.println(ans);
    }
}