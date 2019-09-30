import java.util.Scanner;

public class Main {
	static int N = 0;
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		N = reader.nextInt();;
		reader.close();
		if (execute(0)) {
			System.out.print("Yes");
		} else { 
			System.out.print("No");
		}
	}
	public static boolean execute(int num) {
		if (num < N) {
			return execute(num + 4) || execute(num + 7);
		} else {
			return  (num == N);
		}
	}
}