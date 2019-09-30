import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int d = sc.nextInt();
		int sumL, sumR;
		sumL = a + b;
		sumR = c + d;
		if(sumL > sumR) {
			System.out.println("Left");
		}else if(sumL < sumR) {
			System.out.println("Right");
		}else {
			System.out.println("Balanced");
		}
	}
}