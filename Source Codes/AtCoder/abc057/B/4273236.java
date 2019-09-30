import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		
		long[][] map = new long[N][2];
		for (int i = 0; i < N; i++) {
			long a = sc.nextLong();
			long b = sc.nextLong();
			map[i][0] = a;
			map[i][1] = b;
		}
		
		long[][] points = new long[M][2];
		for (int i = 0; i < M; i++) {
			long c = sc.nextLong();
			long d = sc.nextLong();
			points[i][0] = c;
			points[i][1] = d;
		}
		
		for (int i = 0; i < N; i++) {
			long a = map[i][0];
			long b = map[i][1];
			int point = -1;
			long min = Long.MAX_VALUE;
			for (int j = 0; j < M; j++) {
				long c = points[j][0];
				long d = points[j][1];
				long km = Math.abs(a-c) + Math.abs(b-d);
				if (min > km) {
					point = j+1;
					min = km;
				}
			}
			
			System.out.println(point);
		}
	}
	
}