import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int []C = new int[N];

		for(int i = 0; i < N; i++) {
			C[i] = scan.nextInt();
		}
		scan.close();

		double ans = 0;
		for(int i = 0; i < N; i++) {
			int cnt = 0;
			for(int j = 0; j < N; j++) {
				if(C[i] % C[j] == 0) {
					if(i != j) {
						cnt ++;
					}
				}
			}
			if(cnt % 2 ==0) {
				ans += (double) (cnt + 2) / (double)(2 * cnt + 2);
			}else {
				ans += 0.5;
			}
		}
		System.out.println(ans);
	}
}