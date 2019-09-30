import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int A = sc.nextInt();
	int B = sc.nextInt();
	int C = sc.nextInt();
	int plus = 0;
	int minus = 0;
	boolean f1 = false,f2 = false;
	if ( A + B == C ) {
	    f1 = true;
	}
	if ( A - B == C ) {
	    f2 = true;
	}

	if (f1 && !f2) System.out.println("+");
	else if ( !f1 && f2 )System.out.println("-");
	else if ( f1 && f2 ) System.out.println("?");
	else if ( !f1 && !f2 ) System.out.println("!");
    }
}