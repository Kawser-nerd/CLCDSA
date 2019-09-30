import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		double n = 0;
		if(b == 100) {
			n = Math.pow(100, a) * b + Math.pow(100, a);
		}else {
			n = Math.pow(100, a)*b;
		}
		System.out.println((int)n);
	}
}