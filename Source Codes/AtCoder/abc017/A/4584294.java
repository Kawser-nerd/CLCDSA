import java.util.Scanner;

public class Main {
		public static void main(String[] args){
			Scanner sc = new Scanner(System.in);

			int a = sc.nextInt();
			double b = sc.nextInt()*0.1;
			double n = a*b;

			int c = sc.nextInt();
			double d = sc.nextInt()*0.1;
			double m = c*d;

			int e = sc.nextInt();
			double f = sc.nextInt()*0.1;
			double l = e*f;
			
			int sum = (int)(n+m+l);

			System.out.println(sum);

		}
}