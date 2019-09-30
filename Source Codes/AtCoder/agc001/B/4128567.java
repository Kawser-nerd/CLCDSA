import java.util.Scanner;

public class Main {
	
	public long solve(long N, long X) {
		long longEdge = Math.max(X, N-X);
		long shortEdge = Math.min(X, N-X);
		
		long length = X + N - X;
		
		long times = 1;
		while (shortEdge > 0) {
			long num = longEdge / shortEdge;
			long left = longEdge - (shortEdge * num);

			length += (shortEdge * num * 2);
			longEdge = shortEdge;
			shortEdge = left;
			
			times++;
		}
		length -= longEdge;
		
		return length;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long N = in.nextLong();
		long X = in.nextLong();
		in.close();
		
		Main main = new Main();
		long result = main.solve(N, X);
		
		System.out.println(result);
	}
}