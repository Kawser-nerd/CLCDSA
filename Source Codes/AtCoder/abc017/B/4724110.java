import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String X = sc.next();
	String x1 = "ch";
	String x2 = "o";
	String x3 = "k";
	String x4 = "u";
	for ( int i = 0; i < X.length(); i++ ) {
	    if ( i <= X.length()-2 && X.substring(i,i+2).equals(x1) ) {
		i++;
	    } else if ( X.substring(i,i+1).equals(x2) ) {
	    } else if ( X.substring(i,i+1).equals(x3) ) {
	    } else if ( X.substring(i,i+1).equals(x4) ) {
	    } else {
		System.out.println("NO");
		return;
	    }
	}
	System.out.println("YES");
    }
}