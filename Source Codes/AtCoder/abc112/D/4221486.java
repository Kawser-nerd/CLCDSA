import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int ans = 1;
		if(N == 1) {
			System.out.println(M);
			return;
		}
		for(int i = 2; i <= M / N; i++) {
			if(M % i == 0) ans = i;
		}
		System.out.println(ans);
	}
}