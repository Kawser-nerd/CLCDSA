import java.util.*;
public class Main {
	static int N;
	static int K;
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		K = sc.nextInt();
		int T[][] = new int[N][K];
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < K; j++) {
				T[i][j] = sc.nextInt();
			}
		}
		
		boolean flag = false;
		int cnt = 0;
		if(findBug(cnt, flag, T, 0)) {
			System.out.println("Found");
		} else {
			System.out.println("Nothing");
		}
	}
	
	public static boolean findBug(int cnt, boolean flag, int T[][], int num) {
		if(cnt == N) {
			if(num == 0) {
				//System.out.println("te");
				flag = true;
			}
			return flag;
		}
		
		for(int i = 0; i < K; i++) {
			if(cnt == 0) {
				num = T[0][i];
				flag = findBug(cnt + 1, flag, T, num);
			} else {
				//System.out.println(num);
				if(cnt < N) {
					flag = findBug(cnt + 1, flag, T, num ^ T[cnt][i]);
				}
			}
		}
		return flag;
	}
}