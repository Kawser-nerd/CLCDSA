import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		int m = cin.nextInt();
		long[] x = new long[n];
		long[] y = new long[m];
		for (int i=0;i<n;i++){
			x[i] = cin.nextLong();
		}
		for (int i=0;i<m;i++){
			y[i] = cin.nextLong();
		}
		long segmax = 0;
		long segmay = 0;
		for (int i=0;i<n;i++){
			segmax -= (n-i-1)*x[i];
			segmax += i*x[i];
		}
		segmax %= 1000000007;
		for (int i=0;i<m;i++){
			segmay -= (m-i-1)*y[i];
			segmay += i*y[i];
		}
		segmay %= 1000000007;
		System.out.println(segmax * segmay % 1000000007);
	} 
	
}