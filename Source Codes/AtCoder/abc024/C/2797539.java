import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int D = scan.nextInt();
		int K = scan.nextInt();
		int[]L = new int[D];
		int[]R = new int[D];
		int[]S = new int[K];
		int[]T = new int[K];
		for(int i = 0; i < D; i++) {
			L[i] = scan.nextInt();
			R[i] = scan.nextInt();
		}
		for(int i = 0; i < K; i++) {
			S[i] = scan.nextInt();
			T[i] = scan.nextInt();
		}
		scan.close();
		int[]d = new int[K];
		for(int i = 0; i < K; i++) {
			int t = S[i];
			for(int j = 0; j < D; j++) {
				if(t >= L[j] && t <= R[j]) {
					if(T[i] >= L[j] && T[i] <= R[j]) {
						d[i] = j + 1;
						break;
					}else {
						if(T[i] > S[i]) {
							t = R[j];
						}else {
							t = L[j];
						}
					}
				}
			}
		}
		N = N + 1;
		for(int i = 0; i < K; i++) {
			System.out.println(d[i]);
		}

	}
}