import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int value = N;
		int sum=0;
		while(value != 0) {
			sum +=  (value % 10);
			value /= 10;
		}
		if(N%sum == 0) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
	}
}