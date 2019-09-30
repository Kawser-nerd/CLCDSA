import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	String S = sc.next();
	if ( N == 1 ) {
	    if ( S.equals("b")) {
		System.out.println(0);
		return;
	    } else {
		System.out.println(-1);
		return;
	    }
	}
	for ( int i = 0; i < S.length(); i++ ) {

	    if ( S.charAt(i) == 'a' ||
		 S.charAt(i) == 'b' ||
		 S.charAt(i) == 'c' ){
		}else {
		System.out.println(-1);
		return;
	    }
	}

	StringBuilder sb = new StringBuilder();
	sb.append("b");

	for ( int i = 1; i <= 100; i++ ) {
	    if ( i % 3 == 1 ) {
		sb.insert(0,"a");
		sb.append("c");
	    } else if ( i % 3 == 2 ) {
		sb.insert(0,"c");
		sb.append("a");
	    } else if ( i % 3 == 0 ) {
		sb.insert(0,"b");
		sb.append("b");
	    }	    
	    String str = sb.toString();
	    // System.out.println(i + " " + str);
	    if ( str.length() == N && str.equals(S) ) {
		System.out.println(i);
		return;
	    } else if ( str.length() == N && !str.equals(S) ) {
		System.out.println(-1);
		return;
	    } else if ( str.length() > N ) {
		System.out.println(-1);
		return;
	    }

	}				 
    }
}