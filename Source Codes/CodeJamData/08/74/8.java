
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class D {

	static int nr,nc;
	static int w[][][];
	
	private static int solve(int conf, int r, int c) {
		if (w[conf][r][c]!=-1) return w[conf][r][c];
		w[conf][r][c]=0;
		for (int rr=r-1; rr<=r+1; rr++)
			for (int cc=c-1; cc<=c+1; cc++) {
				if (0<=rr&&rr<nr && 0<=cc&&cc<nc) {
					if ((conf&(1<<(rr*nc+cc)))==0) {
						if (solve(conf+(1<<(rr*nc+cc)), rr,cc)==0) {
							w[conf][r][c]=1;
						}
					}
				}
			}
		return w[conf][r][c];
	}
	
	private static String solve(BufferedReader br) throws Exception {
		String s[] = br.readLine().split(" ");
		nr = Integer.parseInt(s[0]);
		nc = Integer.parseInt(s[1]);
		int sr=0,sc=0;
		int ini=0;
		for (int i=0; i<nr; i++) {
			String a = br.readLine();
			for (int j=0; j<nc; j++) {
				if (a.charAt(j)=='K') {sr=i;sc=j;}
				if (a.charAt(j)!='.') ini+=1<<(i*nc+j);
			}
		}
		
		w = new int[1<<(nr*nc)][nr][nc];
		for (int i=0; i<(1<<(nr*nc)); i++)
			for (int j=0; j<nr; j++)
				for (int k=0; k<nc; k++)
					w[i][j][k]=-1;
		
		return solve(ini,sr,sc)==1?"A":"B";
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int ncases = Integer.parseInt(br.readLine().trim());
		for (int i=0; i<ncases; i++) {
			System.out.println("Case #"+(i+1)+": "+solve(br));
		}
	}

}
