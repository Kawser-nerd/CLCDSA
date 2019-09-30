import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		long array[] = new long[num + 5];
		for(int i = 1; i <= num; i ++) {
			array[i] = i == 1 || i == 2 ? 0
				: i == 3 ? 1
				: array[i - 1] + array[i - 2] + array[i - 3];
			array[i] = mod(array[i]);
		}
		System.out.println(array[num]);
	}
	static long divisor = 10007;
	public static long mod(long i) {
		return i % divisor + ((i % divisor) < 0 ? divisor : 0);
	}
}