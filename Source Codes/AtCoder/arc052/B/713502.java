import java.util.Scanner;

public class Main {
	
	public static double calc(double r, double h){
		return Math.PI * r * r * h / 3.0;
	}
	
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		
		final int N = sc.nextInt();
		final int Q = sc.nextInt();
		
		int[] xs = new int[N];
		int[] rs = new int[N];
		int[] hs = new int[N];
		
		for(int i = 0; i < N; i++){
			final int x = sc.nextInt();
			final int r = sc.nextInt();
			final int h = sc.nextInt();
			
			xs[i] = x; rs[i] = r; hs[i] = h;
		}
		
		for(int q = 0; q < Q; q++){
			final int A = sc.nextInt();
			final int B = sc.nextInt();
			
			double sum = 0;
			for(int i = 0; i < N; i++){
				final int max_x = xs[i] + hs[i];
				final int min_x = xs[i];
				
				if(max_x <= A){ continue; }
				if(min_x >= B){ continue; }
				
				final double lower_h = max_x - Math.max(min_x, A);
				final double lower_r = (lower_h / hs[i]) * rs[i];
				final double upper_h = Math.max(0, max_x - B);
				final double upper_r = (upper_h / hs[i]) * rs[i];
				
				
				sum += calc(lower_r, lower_h) - calc(upper_r, upper_h);
			}
			
			System.out.printf("%.9f\n", sum);
		}
	}
}