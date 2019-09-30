import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		int n= sc.nextInt();
		double max = 0;
		for(int i = 0; i < n; i++) {
			max = Math.max(max, (sc.nextDouble()+sc.nextDouble()+sc.nextDouble()+sc.nextDouble())+(sc.nextDouble()*110/(double)900));
		}
		System.out.println(max);
	}
}