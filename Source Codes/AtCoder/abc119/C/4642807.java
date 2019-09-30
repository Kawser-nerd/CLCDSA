import java.util.*;

public class Main {
	
	static int[] bambooLengths;
	static int N;
	static int A;
	static int B;
	static int C;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		A = sc.nextInt();
		B = sc.nextInt();
		C = sc.nextInt();
		
		bambooLengths = new int[N];
		for (int i = 0; i < N; i++) {
			bambooLengths[i] = sc.nextInt();
		}
		
		System.out.println(getMinCost(0, 0, 0, 0, 0));
	}
	
	public static int getMinCost(int i, int a, int b, int c, int cost) {
		if (i == N) {
			return (a != 0 && b != 0 && c != 0) ? cost + Math.abs(A-a) + Math.abs(B-b) + Math.abs(C-c) : Integer.MAX_VALUE;
		}
		int bambooLength = bambooLengths[i];
		int useForA = getMinCost(i+1, a + bambooLength, b, c, a == 0 ? cost : cost + 10);
		int useForB = getMinCost(i+1, a, b + bambooLength, c, b == 0 ? cost : cost + 10);
		int useForC = getMinCost(i+1, a, b, c + bambooLength, c == 0 ? cost : cost + 10);
		int dontUse = getMinCost(i+1, a, b, c, cost);
		
		return Math.min(useForA, Math.min(useForB, Math.min(useForC, dontUse)));
	}
  
}