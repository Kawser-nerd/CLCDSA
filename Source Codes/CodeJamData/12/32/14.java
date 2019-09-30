import java.util.Scanner;

public class Gas {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int C = 1; C <= T; C++) {
			System.out.printf("Case #%d:\n", C);
			double D = sc.nextDouble();
			int N = sc.nextInt();
			int A = sc.nextInt();

			if (N==1) {
				sc.nextDouble();
				sc.nextDouble();
				for (int i=0;i<A;i++) {
					
					double a = sc.nextDouble();
					System.out.println(Math.sqrt(2*D/a));
				}
				continue;
			}
			// N == 2 !
			double t1 = sc.nextDouble();
			double d1 = sc.nextDouble();
			double t2 = sc.nextDouble();
			double d2 = sc.nextDouble();
			double v = (d2-d1)/t2;
			
			
			
			
			for (int i=0;i<A;i++) {
				double a = sc.nextDouble();
				
				double t_meet = (v+Math.sqrt(v*v+2*a*d1))/a;
				double d_meet = d1 + v * t_meet;
				
				if (d_meet >= D) {
					System.out.println(Math.sqrt(2*D/a));
				} else {
					System.out.println(t_meet + (D-d_meet)/v);
				}
			}
			
			
		}
	}
}
