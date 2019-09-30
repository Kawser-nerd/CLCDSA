import java.util.Scanner;

public class Main {
	public static int N;
	public static int K;
	public static int[][] T;
	
	public static void main(String[] args) {
		readInput();
		
		boolean hasBug = xor(0, 0, 0);
		
		if(hasBug) {
			System.out.println("Found");
		}else {
			System.out.println("Nothing");
		}
		
	}
	
	public static void readInput() {
		try(Scanner sc = new Scanner(System.in)){
			N = sc.nextInt();
			K = sc.nextInt();
			
			// ??????????1???????0????????????0???
			// xor(0,0,0)????
			T = new int[N+1][K+1];
			
			for(int i = 1; i<=N; i++) {
				for(int j = 1; j<=K; j++) {
					T[i][j] = sc.nextInt();
				}
			}
		}
	}
	
	public static boolean xor(int i, int j, int sum) {
		if(i > N) {
			if(sum == 0) {
				return true;
			}else {
				return false;
			}
		}
		sum ^= T[i][j];
		
		boolean hasBug = false;
		
		for(int k = 1; k <= K; k++) {
			hasBug = hasBug || xor(i+1, k, sum);
		}
		
		return hasBug;
	}

}