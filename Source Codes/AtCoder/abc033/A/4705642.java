import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String N = sc.next();
	if ( N.charAt(0) == N.charAt(1) &&
	     N.charAt(1) == N.charAt(2) &&
	     N.charAt(2) == N.charAt(3) ) {
	    System.out.println("SAME");
	} else {
	    System.out.println("DIFFERENT");
	}
    }
}