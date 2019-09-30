import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		
		if (a*c <=b ) {
			System.out.println(c);
		}else {
			int count = 0;
			for (int i = 1; i <= c ; i++) {
				if(i*a <= b) {
					count++;
				}else {
					break;
				}
			}
			System.out.println(count);
		}
		sc.close();
	}
}