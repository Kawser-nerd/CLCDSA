import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int max = 0;
		int min = 1000000000;
		int[] b = new int[n];
		
		for(int i = 0 ; i < n ; i++) {
			int a = sc.nextInt();
			b[i] = a;
			if(max < b[i]) {
				max = b[i];
			}
			if(b[i] < min) {
				min = b[i];
			}
		}
		
		System.out.println(Math.abs(max-min));
		
	}

}