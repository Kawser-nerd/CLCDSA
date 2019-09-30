import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int N = reader.nextInt();
		int ans = N/3;



		System.out.print(ans);
		reader.close();
	}
}