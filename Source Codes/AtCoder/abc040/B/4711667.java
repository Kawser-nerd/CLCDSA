import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
	int ans = (int)1e9;
	if ( n == 1 ) {
	    ans = 0;
	    System.out.println(ans);
	    return;
	}
	for ( int i = 1; i < n; i++ ) {
	    for ( int j = 1;i+ j <= n && i * j <= n; j++ ) {
		int x = Math.abs(i-j);
		int v = i*j;
		int res = n-v;
		int sum = x+res;
		if ( res >= 0 && sum < ans ) {
		    ans = sum;
		}
	    }
	}
	System.out.println(ans);
    }
}