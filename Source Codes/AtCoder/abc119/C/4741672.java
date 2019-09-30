import java.util.*;
import static java.lang.Math.*;

public class Main {

	static int A, B, C, N;
	static List<Integer> lList;

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		N= sc.nextInt();
		A= sc.nextInt();
		B= sc.nextInt();
		C= sc.nextInt();

		lList = new ArrayList<>();

		int i;

		for(i=0; i<N; i++){
			lList.add(sc.nextInt());
		}
		sc.close();

		System.out.println(dfs(0, 0, 0, 0));
	}

	static int dfs(int n, int a, int b, int c){
		if(n==N) {
			return  (min(min(a,b),c) > 0) ? abs(A-a) + abs(B-b) + abs(C-c) -30 : 9999999;
		}

		int mp0 = dfs(n+1, a, b, c);
		int mp1 = dfs(n+1, a+lList.get(n), b, c) + 10;
		int mp2 = dfs(n+1, a, b+lList.get(n), c) + 10;
		int mp3 = dfs(n+1, a, b, c+lList.get(n)) + 10;

		return min(min(mp0, mp1),min(mp2, mp3));
	}
}