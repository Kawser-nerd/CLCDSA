import java.util.*;

public class Main{
    public static void main(String[] args ) {
	Scanner sc = new Scanner(System.in);
	int A = sc.nextInt();
	int B = sc.nextInt();
	int C = sc.nextInt();
	if ( A > B && A > C ) {
	    System.out.println(1);
	    if ( B > C ) {
	    System.out.println(2);
	    System.out.println(3);	    
	    } else {
	    System.out.println(3);
	    System.out.println(2);	    		
	    }
	} else if ( B > A && B > C ) {
	    if ( A > C ) {
	    System.out.println(2);
	    System.out.println(1);
	    System.out.println(3);			    
	    } else if ( A < C ) {
	    System.out.println(3);
	    System.out.println(1);
	    System.out.println(2);			    		
	    }
	} else if ( C > A && C > B ) {
	    if ( A > B ) {
	    System.out.println(2);
	    System.out.println(3);
	    System.out.println(1);			    		
	    } else if ( A < B ) {
	    System.out.println(3);
	    System.out.println(2);
	    System.out.println(1);			    		
	    }
	}
    }
}