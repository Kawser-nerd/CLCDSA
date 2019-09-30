import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	double A = sc.nextDouble();
	double B = sc.nextDouble();
	double C = sc.nextDouble();
	double D = sc.nextDouble();
	if ( B/A > D/C ) {
	    System.out.println("TAKAHASHI");
	} else if( B/A < D/C ) {
	    System.out.println("AOKI");
	} else {
	    System.out.println("DRAW");
	}
    }
}