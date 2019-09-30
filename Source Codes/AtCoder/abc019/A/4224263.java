import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = 3;
		long a[] = new long[num];
		for(int i = 0; i < num; i ++) {
			a[i] = sc.nextLong();
		}
		Arrays.sort(a);
		System.out.println(a[1]);
	}
}