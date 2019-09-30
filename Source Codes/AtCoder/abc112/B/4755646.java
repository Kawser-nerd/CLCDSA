import java.util.*;
public class Main{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), T = sc.nextInt();
		int c[] = new int[N];
		int t[] = new int[N];
		for(int i = 0; i<N; i++) {
			c[i]=sc.nextInt();
			t[i]=sc.nextInt();
		}
		int mincost = 10000;
		boolean ok = false;
		for(int i = 0; i<N; i++) {
			if(t[i]<=T) {
				if(c[i]<mincost)mincost = c[i];
				ok = true;
			}
		}
		if(ok)System.out.println(mincost);
		else System.out.println("TLE");
		sc.close();

	}
}