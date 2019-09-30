import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String S = sc.next();
	int T = sc.nextInt();
	int cnt = 0;
	int x = 0,y = 0;
	for ( int i = 0; i < S.length(); i++ ) {
	    if ( S.charAt(i) == 'L' ) {
		x--;
	    } else if ( S.charAt(i) == 'R' ) {
		x++;
	    } else if ( S.charAt(i) == 'U' ) {
		y++;
	    } else if ( S.charAt(i) == 'D' ) {
		y--;
	    } else if ( S.charAt(i) == '?' ) {
		cnt++;
	    }
	}

	if ( T == 1 ) {
	    int ans = 0;
	    if ( x >= 0 ) x += cnt;
	    else x -= cnt;
	    ans = Math.abs(x)+Math.abs(y);
	    System.out.println(ans);
	} else if ( T == 2 ) {
	    int ans = 0;
	    if ( Math.abs(x)+Math.abs(y) == cnt ) {
		System.out.println(0);
	    } else if ( Math.abs(x)+Math.abs(y) < cnt ) {
		ans = cnt-Math.abs(x)+Math.abs(y);
		if ( ans % 2 == 0 ) System.out.println(0);
		else System.out.println(1);

	    } else {
		ans = Math.abs(x)+Math.abs(y)-cnt;
		System.out.println(ans);		
	    }
	}
    }
}