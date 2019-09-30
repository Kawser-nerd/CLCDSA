import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int ans = 0;
	for ( int i = 0; i < N; i++ ) {
	    int a = sc.nextInt();
	    if ( a == 5 ) {
		ans+=2;
	    } else if ( a % 2 == 0 ) {
		ans++;
		a--;
		if ( a == 5 ) {
		    ans += 2;
		}
	    }
	}
	System.out.println(ans);
    }
}