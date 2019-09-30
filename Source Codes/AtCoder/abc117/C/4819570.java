import java.util.Arrays;
import java.util.Scanner;


public class Main {
	static int N,M;
	static int[] points;
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		 N = sc.nextInt();
		 M = sc.nextInt();
		 points = new int[M];

		 for(int i = 0 ; i < M ; i++){
			 points[i] = sc.nextInt();
		 }

		 sc.close();
		 Arrays.sort(points);

		 int[] minus = new int[M-1];

		 for(int k = 1 ; k < M ; k++){
			minus[k-1] = points[k]-points[k-1];
		 }

		 Arrays.sort(minus);

		 int ans = 0 ;

		 for(int l = 0 ; l < minus.length - N + 1 ; l++){
			 ans += minus[l];
		 }

		 System.out.println(ans);
	}
}