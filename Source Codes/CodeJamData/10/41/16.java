import java.util.*;
public class A {
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		for (int ii = 1; ii<=T; ++ii) {
			//Something
			int k = sc.nextInt();
			int [][] d = new int [k][k];
			for (int i = 0; i < 2*k-1; ++i) {
				int n = (i <= k-1) ? i+1 : k-(i - (k-1));
				int init = (i<=k-1)?0:(i-(k-1));
				for (int s = init; s < n+init; ++s) d[i-s][s] = sc.nextInt()+1;
				
			}
			for (int i = 0; i<k; ++i) {
				for (int j = 0; j<k; ++j) System.err.print(d[i][j]+ " ");
				System.err.println();
			}
			int MIN = k;
			int MAX = 2*k;
			while (MIN < MAX) {
				int piv = (MIN+MAX)/2;
				if (piv == MAX) piv--;
				boolean t = false;
				for (int offset = 0; offset <= piv - k; ++offset) {
					for (int offsetj = 0; offsetj<=piv-k; ++offsetj) {
						if (check(d,offset,offsetj,piv)) {t=true;break;}
					}
				}
				if (t) {
					System.err.println(piv + " : Works");
					MAX = piv;
				} else {
					System.err.println(piv + " : Doesnt Work");
					MIN = piv+1;
				}
			}
			System.out.printf("Case #%d: %s\n",ii,(MIN*MIN-k*k)+"");
		}
	}
	public static boolean check(int [][] d, int o1, int o2, int k2) {
		int k = d.length;
		int [][] d2 = new int [k2][k2];
		for (int i = o1; i<o1+d.length; ++i) 
			for (int j = o2; j<o2+d.length; ++j) d2[i][j] = d[i-o1][j-o2];
				
		for (int i = 0; i<k2; ++i) {
			for (int j = 0; j<k2; ++j) {
				int i1 = k2-j-1;
				int j1 = k2-i-1;
				int i2 = j;
				int j2 = i;
				//System.err.println("Checking " + i + " , " + j + " ,, " + i1 + " , " + j1 + " ,, " + i2 + " ,, " + j2);
				if (d2[i1][j1] != 0) {
					if (d2[i][j] == 0) d2[i][j] = d2[i1][j1];
					if (d2[i][j] != d2[i1][j1]) return false;
					if (d2[i2][j2] == 0) d2[i2][j2] = d2[i1][j1];
					if (d2[i][j] != d2[i2][j2]) return false;
				}
				if (d2[i2][j2] != 0) {
					if (d2[i][j] == 0) d2[i][j] = d2[i2][j2];
					if (d2[i][j] != d2[i2][j2]) return false;
					if (d2[i1][j1] == 0) d2[i1][j1] = d2[i][j];
					if (d2[i][j] != d2[i1][j1]) return false;
				}
			}
		}
		return true;
	}
}