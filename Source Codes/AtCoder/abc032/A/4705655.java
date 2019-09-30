import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int a = sc.nextInt();
	int b = sc.nextInt();
	int n = sc.nextInt();
	int ans = 0;
	for ( int i = n; i <= 2000000; i++ ) {
	    if ( i % a == 0 && i % b == 0 ) {
		ans = i;
		break;
	    }
	}
	System.out.println(ans);
    }
}