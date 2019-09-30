import java.util.Scanner;

public class Main {
	public static final int MAX_NUM = 100000;
	
	public static int N;
	public static int[] A;

	public static void main(String[] args) {
		readInput();
	}

	public static void readInput() {
		try(Scanner sc = new Scanner(System.in)){
			N = sc.nextInt();

			int[] sum = new int[MAX_NUM+1];

			for(int i = 0; i<N; i++) {
				int a = sc.nextInt();
				sum[a]++;
			}

			int ans = 0;

			for(int i = 1; i<=MAX_NUM; i++) {
				if(sum[i] > 0) {
					ans += sum[i] - 1;
				}
			}
			
			System.out.println(ans);
		}
	}

}