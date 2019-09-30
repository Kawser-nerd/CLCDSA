//2019/04/07
import java.util.Scanner;
public class Main{

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();

		int M = sc.nextInt();

		int X = sc.nextInt();

		int[] A = new int[M];

		int r = 0;

		int l = 0;

		for(int i=0;i<M;i++) {

			A[i] = sc.nextInt();

			if(A[i]<X) l++;

			else r++;
		}

		int ans = Math.min(r, l);

		System.out.println(ans);
	}

}