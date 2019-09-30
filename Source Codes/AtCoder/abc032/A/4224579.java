import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		for(int i = sc.nextInt(); ; i ++) {
			if(i % a == 0 && i % b == 0) {
				System.out.println(i);
				break;
			}
		}
	}
}