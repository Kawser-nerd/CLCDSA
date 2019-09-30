import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt() * 2;
		long length[] = new long[num];
		for(int i = 0; i < num; i ++) {
			length[i] = sc.nextLong();
		}
		Arrays.sort(length);
		long ans = 0;
		for(int i = 0; i < num; i += 2) {
			ans += length[i];
		}
		System.out.println(ans);
	}
}