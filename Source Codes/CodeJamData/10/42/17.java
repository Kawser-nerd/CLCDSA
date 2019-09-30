import java.util.*;
public class B {
	static int [] M;
	static int [][] PR;
	static long [][][] dp;
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int TT = Integer.parseInt(sc.nextLine());
		for (int ii = 1; ii<=TT; ++ii) {
			int P = sc.nextInt();
			M = new int [1<<P];
			for (int i = 0; i<M.length; ++i) M[i] = sc.nextInt();
			PR = new int [P][1<<P];
			for (int i = 1; i<=P; ++i) {
				for (int j = 0; j<(1<<(P-i)); ++j) PR[i-1][j] = sc.nextInt();
			}
			//dp = new long [11][11][1<<10];
			long ans = recurse(0, 0, (1<<P)-1, 0, P-1);
			System.out.printf("Case #%d: %s\n",ii,ans+"");
		}
	}
	public static long recurse (int index, int start, int finish, int minus, int lvl) {
		if (lvl == -1) return 0;
		boolean canreduce = true;
		for (int i = start; i<=finish; ++i) if (M[i] - minus <= 0) canreduce = false;
		long best = Long.MAX_VALUE;
		
		if (canreduce) {
			long tmp = 0;
			tmp +=  recurse(index<<1, start, (start+finish)/2, minus+1, lvl-1);
			tmp += recurse((index<<1) + 1, (start+finish)/2+1,finish, minus+1, lvl-1);
			if (tmp < best) best = tmp;
		}
		long tmp = PR[lvl][index];
		tmp += recurse(index<<1, start, (start+finish)/2, minus, lvl-1);
		tmp += recurse((index<<1) + 1, (start+finish)/2+1,finish, minus, lvl-1);
		if (tmp < best) best = tmp;
		return best;
	}	
}