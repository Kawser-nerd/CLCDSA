import java.util.Scanner;

public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        long xs = sc.nextInt();
        long ys = sc.nextInt();
        long xe = sc.nextInt();
        long ye = sc.nextInt();
        long v = sc.nextInt();
        long t = sc.nextInt();

        int N = sc.nextInt();
        
        long total = v * t;
		for (int i = 0; i < N; i++) {
			long x = sc.nextInt();
			long y = sc.nextInt();
			
			long p1 = (xs-x) * (xs-x) + (ys-y) * (ys-y);
			long p2 = (xe-x) * (xe-x) + (ye-y) * (ye-y);
			double d1 = Math.sqrt(p1);
			double d2 = Math.sqrt(p2);
			
			if (d1+d2 <= total) {
				System.out.println("YES");
				return;
			}
		}
		
		System.out.println("NO");
		
    }
}