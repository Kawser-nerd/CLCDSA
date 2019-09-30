import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String A = sc.next();
	String B = sc.next();
	if ( A.length() < B.length() ) {
	    System.out.println(B);
	} else {
	    System.out.println(A);	    
	}
    }
}