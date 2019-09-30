import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String S = sc.next();
	if ( S.charAt(S.length()-1) == 'T' ) {
	    System.out.println("YES");
	} else {
	    System.out.println("NO");
	}
    }
}