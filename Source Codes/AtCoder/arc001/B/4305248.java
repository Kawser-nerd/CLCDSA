import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int change[] = {10, 5, 1};
		double border[] = {7.5, 3.5, 0.5};
		int need = Math.abs(sc.nextInt() - sc.nextInt());
		int count = 0;
		for(int i = 0; i < 3; i ++) {
			while(need >= border[i]) {
				need = Math.abs(need - change[i]);
				count ++;
			}
		}
		System.out.println(count);
	}
}