import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] C = new int[N];
		int[] S = new int[N];
		int[] F = new int[N];
		for(int i = 1; i < N; i++) {
			C[i] = sc.nextInt();
			S[i] = sc.nextInt();
			F[i] = sc.nextInt();
		}
		for(int i = 1; i < N; i++) {
			int ans = S[i] + C[i];
			for(int j = i+1; j < N; j++) {
				if(ans >= S[j]) {
					if((ans-S[j]) % F[j] == 0)
						ans += C[j];
					else
						ans += C[j] + F[j] - (ans-S[j]) % F[j];
				}
				else
					ans = S[j]+C[j];
			}
			System.out.println(ans);
		}
		System.out.println(0);
		
	}

}