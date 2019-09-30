import java.util.Scanner;

	public class Main {
	       public static void main(String[] args){
					Scanner sc = new Scanner(System.in);
					double a = sc.nextDouble();
					double b = sc.nextDouble();
					double x = 0;
					if(1 <= a && b <= 100) {x = (a + b)/2;}
					x = Math.ceil(x);
					System.out.println((int)x);
	       }}