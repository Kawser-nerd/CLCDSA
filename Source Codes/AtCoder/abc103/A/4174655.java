import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cost[] = new int[3];
		for(int i = 0; i < 3; i ++) {
			cost[i] = sc.nextInt();
		}
		Arrays.sort(cost);
		System.out.println(Math.abs(cost[0] - cost[2]));
	}
}