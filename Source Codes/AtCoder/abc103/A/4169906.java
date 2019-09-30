import java.util.*;

public class Main {

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int[] xs = new int[3];
		for (int i = 0; i < 3; i++) {
			xs[i] = sc.nextInt();
		}
		Arrays.sort(xs);
		System.out.println(xs[2] - xs[0]);
	}
}