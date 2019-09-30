import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double ans = sc.nextDouble();
		int num = 0;
		while(true) {
			num++;
			double pownum = Math.pow(num, 4);
			if(pownum == ans) {
				System.out.println(num);
				break;
			}
		}
	}
}