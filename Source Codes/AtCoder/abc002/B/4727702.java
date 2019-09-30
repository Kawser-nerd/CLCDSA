import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String W = sc.next();
	for ( int i = 0; i < W.length(); i++ ) {
	    if ( W.charAt(i) == 'a' ||
		 W.charAt(i) == 'i' ||
		 W.charAt(i) == 'u' ||
		 W.charAt(i) == 'e' ||
		 W.charAt(i) == 'o')continue;
	    else System.out.print(W.charAt(i));
		
	}
	System.out.println();
    }
}