import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		StringBuilder sb = new StringBuilder();
		sb.append(1);
		for (int i = 0; i < n - 1; i++) {
			sb.append(0);
		}
		sb.append(7);
		System.out.println(sb);
 	}
}