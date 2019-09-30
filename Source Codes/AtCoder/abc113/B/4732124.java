import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		double t = sc.nextInt();
		double a = sc.nextInt();
		double min = 1000_000_000;
		int min_index = 0;
		
		for(int i = 1; i <= n; i++) {
			double x = sc.nextInt();
			x = t - x*0.006;
			if(min > Math.abs(a - x)) {
				min = Math.abs(a - x);
				min_index = i;
			}
		}
		
		System.out.println(min_index);
		sc.close();

	}
}