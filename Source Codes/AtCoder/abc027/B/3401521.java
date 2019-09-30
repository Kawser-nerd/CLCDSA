import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int[]a = new int[N];
		int sum = 0;
		for(int i = 0; i < N; i++) {
			a[i] = scan.nextInt();
			sum += a[i];
		}
		scan.close();
		if(sum % N != 0) {
			System.out.println(-1);
			System.exit(0);
		}
		int k = sum / N;
		int t = 0;
		int ans = 0;
		for(int i = 0; i < N; i++) {
			t += a[i];
			if(t != (i + 1) * k) {
				ans++;
			}
		}
		System.out.println(ans);

	}
}