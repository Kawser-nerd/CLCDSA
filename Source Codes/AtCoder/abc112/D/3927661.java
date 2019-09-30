import java.util.Scanner;
public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		long N = sc.nextLong();
		long M = sc.nextLong();
		
		if (M % N == 0) {
			System.out.println(M / N);
			return;
		}
		
		long end = M / N;
		long ans = 0;
		for (long i = 1; i <= end; i++) {
			if ((M - i * (N-1)) % i == 0) {
				ans = i;
			}
			
			if (i * N > M) {
				break;
			}
		}
		
		System.out.println(ans);
	}
}