import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		
		int[] map = new int[M+1];
		long pointSum = 0;
		for (int i = 0; i < N; i++) {
			int l = sc.nextInt();
			int r = sc.nextInt();
			int point = sc.nextInt();
			pointSum += point;
			map[l-1] += point;
			map[r] += -point;
		}
		
		long min = Long.MAX_VALUE;
		long now = 0;
		for (int i = 0; i < M; i++) {
			now += map[i];
			min = Math.min(now, min);
		}
		
		System.out.println(pointSum - min);
	}
}