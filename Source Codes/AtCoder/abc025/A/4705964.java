import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String S = sc.next();
	int N = sc.nextInt();
	String ans = "";
	if (  N <= 5 ) {
	    ans += S.charAt(0);
	    N--;
	    ans += S.charAt(N);
	} else if ( N <= 10 ) {
	    ans += S.charAt(1);
	    N -=6;
	    ans += S.charAt(N);
	} else if ( N <= 15 ) {
	    ans  += S.charAt(2);
	    N -=11;
	    ans += S.charAt(N);	    
	} else if ( N <= 20 ) {
	    ans  += S.charAt(3);
	    N -= 16;
	    ans += S.charAt(N);	    
	} else if ( N <= 25 ) {
	    ans  += S.charAt(4);
	    N -= 21;
	    ans += S.charAt(N);	    
	}
	System.out.println(ans);
    }
}