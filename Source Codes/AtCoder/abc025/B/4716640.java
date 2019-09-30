import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int A = sc.nextInt();
	int B = sc.nextInt();
	int X = 0;
	for ( int i = 0; i < N; i++ ) {
	    String s = sc.next();
	    int d = sc.nextInt();
	    if ( s.equals("East") ) {
		if ( A <= d && d <= B ) {
		    X += d;
		} else if ( d < A ) {
		    X += A;
		} else if ( d > B ) {
		    X += B;
		}
	    } else {
		if ( A <= d && d <= B ) {
		    X -= d;
		} else if ( d < A ) {
		    X -= A;
		} else if ( d > B ) {
		    X -= B;
		}		
	    }
	}
	if ( X == 0 ) {
	    System.out.println(0);
	} else if ( X > 0 ) {
	    System.out.print("East ");
	    System.out.println(X);
	} else if ( X < 0 ) {
	    System.out.print("West ");
	    System.out.println(Math.abs(X));	    
	}
    }
}