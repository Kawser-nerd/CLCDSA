import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// get a integer
		int N = sc.nextInt();
		int K = sc.nextInt();
		int X = sc.nextInt();
		int Y = sc.nextInt();
		
		int total = (N < K )? N*X: (X*K) + Y * (N-K);
		
		System.out.println(total);
	}
}