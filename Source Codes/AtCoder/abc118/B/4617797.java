import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), M = sc.nextInt();
		int[] b = new int[M];
		for (int i = 0; i < N; i++) {
			int K = sc.nextInt();
			for (int j = 0; j < K; j++) {
				int a = sc.nextInt()-1;
				b[a]++;
			}
		}
		int count = 0;
		for (int i = 0; i < M; i++) {
			if (b[i] == N) count++;
		}
		System.out.println(count);
	}

}