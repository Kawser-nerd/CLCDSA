//2019/3/15
//????
import java.util.Scanner;
public class Main {

	static int N, A, B, C;

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();

		A = sc.nextInt();

		B = sc.nextInt();

		C = sc.nextInt();

		int[] l = new int[N];

		for(int i=0;i<N;i++) {

			l[i] = sc.nextInt();
		}
		System.out.println(dfs(0,0,0,0,l));
	}

	static int dfs(int cur, int a, int b, int c, int[] l) {

		if(cur==N) {

			if((Math.min(Math.min(a, b),c)>0))

				return (Math.abs(A-a) + Math.abs(B-b) + Math.abs(C-c) - 30);

			else return 1000000000;
		}

		int res0 = dfs(cur+1,a,b,c,l);

		int res1 = dfs(cur+1,a+l[cur],b,c,l)+10;

		int res2 = dfs(cur+1,a,b+l[cur],c,l)+10;

		int res3 = dfs(cur+1,a,b,c+l[cur],l)+10;

		int min0 = Math.min(res0, res1);

		int min1 = Math.min(res2, res3);

		return Math.min(min0, min1);
	}

}