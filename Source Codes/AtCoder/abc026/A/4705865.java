import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int A = sc.nextInt();
	int ans = 0;
	for ( int i = 1; i <= 100; i++ ) {
	    for ( int j = 1; j <= 100; j++ ) {
		if ( i + j == A ) {
		    ans = Math.max(ans,i*j);
		}
	    }
	}
	System.out.println(ans);
    }
}