import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long point = 0;
		for(int i = 0; i < 3; i ++) {
			point += sc.nextLong() * sc.nextLong() / 10;
		}
		System.out.println(point);
	}
}