import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
	int X = sc.nextInt();
	int a[] = new int[n];
	for ( int i = 0; i < n; i++ ) {
	    a[i] = sc.nextInt();
	}
	int sum = 0;
	for ( int i = 0; i < n; i++ ) {
	    if ( (X & (1 << i)) != 0 ) {
		sum += a[i];
	    }
	}
	System.out.println(sum);
    }
}