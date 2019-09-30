import java.util.*;

public class Main {
	
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		
		int[] points = new int[M];
		for (int i = 0; i < M; i++) {
			points[i] = sc.nextInt();
		}
		
		Arrays.sort(points);
		int[] segments = new int[M-1];
		for (int i = 0; i < M-1; i++) {
			segments[i] = points[i+1] - points[i];
		}
		
		Arrays.sort(segments);
		long distance = 0;
		for (int i = 0; i < M-N; i++) {
			distance += segments[i];
		}
		
		System.out.println(distance);
	}
}