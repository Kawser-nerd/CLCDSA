import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int N = reader.nextInt();
		int[] arr = new int[N];
		for (int i = 0; i < N; i++) {
			arr[i] = reader.nextInt();
		}
		reader.close();
		int tmp = arr[0];
		for (int i = 1; i < N; i++) {
			tmp = gcd(tmp, arr[i]);
		}
		System.out.print(tmp);
	}

	private static int gcd(int x, int y) {

	   if (y > x) {
	   	int tmp = y;
	     y = x;
	     x = tmp;
	   }
	   int next;
	   while ((next = x % y) != 0) {
	     x = y;
	     y = next;

	   }
	   return y;
	 }
}