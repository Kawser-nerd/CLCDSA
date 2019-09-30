package round2;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;

public class P1 {
	private static final int INF = 1000000;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("round2/p1.in"));
		
		FileWriter out = new FileWriter("p1.out");
		
		int n = Integer.parseInt(br.readLine());
		for (int i=1; i<=n; i++) {
			
			int res = solveOne(br);
			System.out.println("Case #" + i + ": " + (res>=INF?"IMPOSSIBLE":res));
			out.write("Case #" + i + ": " + (res>=INF?"IMPOSSIBLE":res) + "\n");
		}
		br.close();
		out.close();
	}

	private static int m, m2;
	private static int val[];
	private static int op[];
	private static int ch[];

	
	private static int solveOne(BufferedReader br) throws Exception {
		String[] mv = br.readLine().split("\\s+");
		m = Integer.parseInt(mv[0]);
		m2 = (m-1)/2;
		int v = Integer.parseInt(mv[1]);
		
		val = new int[m];
		op = new int[m];
		ch = new int[m];
		for (int l=0; l<m; l++) {
			String parts[] = br.readLine().split("\\s+");
			if (l<m2) {
				val[l] = -1;
				op[l] = Integer.parseInt(parts[0]);
				ch[l] = Integer.parseInt(parts[1]);
			} else {
				val[l] = Integer.parseInt(parts[0]);
				op[l] = -1;
				ch[l] = -1;
			}
		}
		doCalc(0);
		
		if (val[0]==v) return 0;
			
		return changeCost(0);
	}


	private static void doCalc(int i) {
		if (i>=m2) return;
		doCalc(i*2+1);
		doCalc(i*2+2);
		val[i] = (op[i]==0)?(val[i*2+1]|val[i*2+2]):(val[i*2+1]&val[i*2+2]);
	}

	private static int changeCost(int i) {
		if (i>=m2) return INF;
		int best = INF;
		for (int co=0; co<2; co++) {
			if (co==1 && ch[i]==0) 
				continue;
			
			for (int c1=0; c1<2; c1++)
				for (int c2=0; c2<2; c2++) {
					int i1 = val[i*2+1] ^ c1;
					int i2 = val[i*2+2] ^ c2;
					int o = op[i] ^ co;
					//0 = or
					int r = (o==0?(i1|i2):(i1&i2));
					if (r==val[i]) continue;
					
					int cost = co + (c1==1?changeCost(i*2+1):0) +
						(c2==1?changeCost(i*2+2):0);
					if (cost<best)
						best = cost;
				}
		}
		
		return best;
	}
}
