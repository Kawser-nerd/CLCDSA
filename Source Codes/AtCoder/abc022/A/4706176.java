import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int S = sc.nextInt();
	int T = sc.nextInt();
	int A[] = new int [1010];
	for ( int i = 0; i < N; i++ ) {
	    A[i] = sc.nextInt();
	}
	int sum = 0;
	int cnt = 0;
	for ( int i = 0; i < N; i++ ) {
	    sum += A[i];
	    if ( S <= sum && sum <= T ) cnt++;
	}
	System.out.println(cnt);
    }
}