import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int T = sc.nextInt();
		int[] A = new int[N];
		for(int i = 0;i < N;++i)
			A[i] = sc.nextInt();
		sc.close();
		
		int ans = 0;
		int currentTime = A[0];
		for(int i = 1;i < N;++i) {
			if(currentTime + T < A[i]) {
				ans += T;
			} else {
				ans += A[i] - A[i-1];
			}
			currentTime = A[i];
		}
		ans += T;
		
		System.out.println(ans);
	}
}