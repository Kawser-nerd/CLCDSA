import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = Integer.parseInt(sc.next());
		
		int[] yen = new int[n];
		
		for(int i = 0; i < n; i++) {
			yen[i] = Integer.parseInt(sc.next());
		}
		
		Arrays.sort(yen);
		
		yen[n-1] = yen[n-1]/2;
		
		System.out.println(Arrays.stream(yen).sum());
	}
}