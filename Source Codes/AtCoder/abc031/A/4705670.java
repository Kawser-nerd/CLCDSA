import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int A = sc.nextInt();
	int D = sc.nextInt();
	if ( (A+1)*D >= A*(D+1) ) {
	    System.out.println((A+1)*D);
	} else {
	    System.out.println(A*(D+1));
	}
    }
}