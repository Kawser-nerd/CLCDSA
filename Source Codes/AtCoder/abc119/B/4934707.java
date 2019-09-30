import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		double btc = 380000.0; 
		double sum = 0;
		for(int i = 0; i < n; i++) {
			sum += sc.nextDouble() * (sc.next().equals("BTC") ? btc : 1);
		}
		System.out.println(sum);
	}
}