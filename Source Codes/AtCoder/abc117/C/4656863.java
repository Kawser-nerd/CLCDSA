import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] x = new int[m];
		for(int i = 0; i < m; i++) {
			x[i] = sc.nextInt();
		}
		Arrays.sort(x);
		int[] distance = new int[m-1];
		for(int i = 0; i < m-1; i++) {
			distance[i] = x[i+1] - x[i];
		}
		Arrays.sort(distance);
		int answer = 0;
		for(int i = 0; i < m-n; i++) {
			answer += distance[i];
		}
		if(n >= m) System.out.println("0");
		else System.out.println(answer);
	}

}