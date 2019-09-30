import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int sum = sc.nextInt();
		for(int i = (int)Math.floor(sum / num); i >= 1; i --) {
			if(sum % i == 0) {
				System.out.println(i);
				break;
			}
		}
	}
}