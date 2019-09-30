import java.util.*;
public class B{
	public static void main(String[]args){
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for(int i = 1; i <= cases; i++) {
			double rate = 2;
			double c = in.nextDouble();
			double f = in.nextDouble();
			double x = in.nextDouble();
			double best = x/rate;
			double base = 0;
			double next = best;
			while(next <= best) {
				if( next < best) best = next;
				base += c/rate;
				rate += f;
				next = base + x/rate;
			}
			System.out.printf("Case #%d: %.7f\n", i, best);
		}
	}
}