import java.util.*;
public class Main {
	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	long[]a = new long[87];
	a[0]=2;a[1]=1;
	int N = sc.nextInt();
	for(int i=2;i<=N;i++) {
		a[i] = a[i-1] + a[i-2];
	   }
	System.out.println(a[N]);
	}
}