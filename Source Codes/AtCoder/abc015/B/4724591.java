import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int A[] = new int[100];
	double cnt = 0;
	double sum = 0;
	for ( int i = 0; i < N; i++ ) {
	    A[i] = sc.nextInt();
	    if ( A[i] > 0 ) cnt++;
	    sum += A[i];
	}
	sum /= cnt;
	sum = Math.ceil(sum);
	int ans = (int)sum;
	System.out.println(ans);
    }
}