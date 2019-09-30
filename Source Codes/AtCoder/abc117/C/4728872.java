import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = Integer.parseInt(sc.next());
		int m = Integer.parseInt(sc.next());
		
		int[] x = new int[m];
		
		for(int i = 0; i < m; i++) {
			x[i] = Integer.parseInt(sc.next());
		}
		
		Arrays.sort(x);
		
		Integer[] d = new Integer[m-1];
		
		for(int i = 0; i < m-1; i++) {
			d[i] = x[i+1] - x[i];
		}
		
		Arrays.sort(d);
		
		int res = 0;
		
		for(int i = 0; i < m-n; i++) {
			res+=d[i];
		}
		
		System.out.println(res);
	}
}