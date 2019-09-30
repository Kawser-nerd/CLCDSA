import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
	long a[] = new long[1000001];
	a[1] = 0;
	a[2] = 0;
	a[3] = 1;
	for ( int i = 4; i <= n; i++ ) {
	    a[i] = a[i-1]+a[i-2]+a[i-3];
	    a[i] %= 10007;
	}
	System.out.println(a[n]);
    }
}