import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int ans = N;
		for(int i = 0; i <= N; i++) {
			int a = 0, b = i;
			while(b > 0) {
				a += b % 6;
				b /= 6;
			}
			b = N - i;
			while(b > 0) {
				a += b % 9;
				b /= 9;
			}
			ans = Math.min(ans, a);
		}
		System.out.println(ans);
	}

}