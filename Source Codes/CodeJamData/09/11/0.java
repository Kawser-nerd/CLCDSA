import java.io.*;
import java.util.*;
public class A {
	static int[][] ishappy = new int[11][1000];
	static boolean happy(int num, int base) {

		while (num>=base && num>=1000) {
			int ret = 0;
			while (num>0) {
				ret += (num%base)*(num%base);
				num/=base;
			}
			num = ret;
		}
		return ishappy[base][num]==1;
	}
	static int getnext(int num, int base) {
		int ret = 0;
		while (num>0) {
			ret += (num%base)*(num%base);
			num/=base;
		}
		return ret;
	}
	static boolean solve(int base, int num) {
		if (ishappy[base][num]==1) return true;
		if (ishappy[base][num]==0) return false;
		ishappy[base][num]=0;
		if (solve(base,getnext(num,base))) ishappy[base][num]=1;
		return ishappy[base][num]==1;
	}
	static int[] ans = new int[1<<9];
	public static void main(String[] args) throws IOException {
		for (int i=0; i<1000; i++)
		for (int j=0; j<11; j++) ishappy[j][i]=-1;

		for (int j=2; j<=10; j++) {
			Arrays.fill(ishappy[j],-1);
			ishappy[j][1]=1;
			for (int k=2; k<1000; k++) {
				solve(j,k);
			}
		}

		for (int i=1; i<(1<<9); i++) {
			int ti = i;
			int numbases = 0;
			while (ti>0) {
				numbases+=ti%2;
				ti/=2;
			}
			int[] bases = new int[numbases];

			int bb = 0;

			int firstbit = 0;
			for (int j=0; j<9; j++) {
				if ((i&(1<<j))!=0) {bases[bb++]=j+2;firstbit=j;}
			}

			int start = (numbases==1?2:ans[i&~(1<<firstbit)]);
			loop: for (int j=start;;j++) {
				for (int k : bases) {
					if (!happy(j,k)) continue loop;
				}
				ans[i]=j;
				break;
			}
		}
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine().trim());
		int t=0;
		while (T-->0) {
			t++;
			String[] parts = br.readLine().trim().split("\\s++");
			int[] bases = new int[parts.length];
			for (int i=0 ;i<parts.length; i++) bases[i] = Integer.parseInt(parts[i]);

			int state = 0;
			for (int x : bases) state|=1<<(x-2);


			System.out.println("Case #"+t+": "+ans[state]);

		}
	}
}