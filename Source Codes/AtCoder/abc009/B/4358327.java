import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		long price[] = new long[num];
		for(int i = 0; i < num; i ++) {
			price[i] = sc.nextLong();
		}
		Arrays.sort(price);
		for(int i = num - 1; i > 0; i --) {
			if(price[i] > price[i - 1]) {
				System.out.println(price[i - 1]);
				break;
			}
		}
	}
}