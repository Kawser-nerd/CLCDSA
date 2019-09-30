import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int M = sc.nextInt();
	int D = sc.nextInt();
	if ( M % D == 0 ) {
	    System.out.println("YES");
	} else {
	    System.out.println("NO");	    
	}
    }
}