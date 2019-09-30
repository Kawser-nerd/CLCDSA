import static java.lang.Math.*;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.*;

public class C {
	Scanner scan;

	public C(Scanner s) {
		scan = s;
	}
	
	int intLine(){
		return Integer.parseInt(scan.nextLine());
	}
	
	
	String ts(char[][]B){
		String res ="";
		for(int i=0;i<B.length;i++){
			res += new String(B[i]);
			if(i+1<B.length)res+="\n";
		}
		return res;
	}
	
	static class Sh{
		int r; int c;
		static int it=0;
		char fix = '?';
		int id=it++;
		@Override
		public String toString() {
			return "("+r+","+c+"): "+fix;
		}
		@Override
		public boolean equals(Object obj) {
			Sh o = (Sh)obj;
			return o.r==r && o.c==c;
		}
		@Override
		public int hashCode() {
			return (r+","+c).hashCode();
		}
	}
	
	char[][]B;
	boolean vc(int row, int c1, int c2){
		for(int i=min(c1,c2);i<max(c1,c2);i++){
			if(B[row][i]=='#')return false;
		}
		return true;
	}
	
	boolean hc(int col, int r1, int r2){
		for(int i=min(r1,r2);i<max(r1,r2);i++){
			if(B[i][col]=='#')return false;
		}
		return true;
	}
	
	void doit(int p,int[]R,boolean[][]G,int n,boolean[]U){
		if(U[p])return;
		U[p]=true;
		if(p<n)R[p]=1;else R[p-n]=-1;
		for(int q=0;q<G.length;q++){
			if(G[p][q])doit(q,R,G,n,U);
		}
	}
	
	boolean solve(ArrayList<Sh[]>pairs){
		HashMap<Sh, Integer>C = new HashMap<>();
		for(Sh[]s:pairs){
			Sh x = s[0];
			if(!C.containsKey(x)){
				C.put(x,C.size());
			}
			x = s[1];
			if(!C.containsKey(x)){
				C.put(x,C.size());
			}
		}
		int n = C.size();
		boolean[][]G = new boolean[2*n][2*n];
		for(Sh[]s:pairs){
			Sh row = s[0];Sh col = s[1];
			int rId = C.get(row);int cId = C.get(col);
			G[rId][cId]=true;
			G[cId+n][rId+n]=true;
		}
		for(int k=0;k<n*2;k++)for(int i=0;i<n*2;i++)for(int j=0;j<n*2;j++){
			if(G[i][k]&&G[k][j])G[i][j]=true;
		}
		for(int i=0;i<n;i++){
			if(G[i][i+n]||G[i+n][i])return false;
		}
		int[]R = new int[n];
		Arrays.fill(R, 0);
		for(int i=0;i<n;i++){
			if(R[i]==0){
				doit(i,R,G,n,new boolean[2*n]);
			}
		}
		for(Sh s:C.keySet()){
			int id = C.get(s);
			if(R[id]<0)s.fix='|';
			else s.fix='-';
		}
		return true;
	}
	
	
	boolean validate(ArrayList<Sh> S) {
		for (int r = 0; r < B.length; r++)
			for (int c = 0; c < B[0].length; c++) {
				if (B[r][c] == '.') {
					boolean ok = false;
					for (Sh s : S) {
						if (s.r == r && vc(r, s.c, c)) {
							if (s.fix == '-') {
								ok = true;
								break;
							}
						}
						if (s.c == c && hc(c, s.r, r)) {
							if (s.fix == '|') {
								ok = true;
								break;
							}
						}
					}
					if(!ok)return false;
				}
			}

		return true;
	}

	public String solve() {
		String imp = "IMPOSSIBLE";
		int R = scan.nextInt();
		int C = scan.nextInt();
		B = new char[R][];
		for(int i=0;i<R;i++){
			B[i]=scan.next().toCharArray();
		}
		ArrayList<Sh>S = new ArrayList<>();
		for(int r=0;r<R;r++)for(int c=0;c<C;c++){
			if(B[r][c]=='|' || B[r][c]=='-'){
				Sh s = new Sh();s.r=r;s.c=c;
				S.add(s);
			}
		}
		for(int i=0;i<S.size();i++)for(int j=i+1;j<S.size();j++){
			Sh s1=S.get(i);Sh s2=S.get(j);
			if(s1.r==s2.r && vc(s1.r, s1.c,s2.c)){
				s1.fix = '|';s2.fix='|';
			}
		}
		for(int i=0;i<S.size();i++)for(int j=i+1;j<S.size();j++){
			Sh s1=S.get(i);Sh s2=S.get(j);
			if(s1.c==s2.c && hc(s1.c, s1.r, s2.r)){
				if(s1.fix=='|'||s2.fix=='|')return imp;
				s1.fix=s2.fix='-';
			}
		}
		ArrayList<Sh[]>pairs = new ArrayList<>();
		while (true) {
			boolean set = false;

			for (int r = 0; r < R; r++)
				for (int c = 0; c < C; c++) {
					if (B[r][c] == '.') {
						boolean ok = false;
						Sh row = null;
						Sh col = null;
						for (Sh s : S) {
							if (s.r == r && vc(r, s.c, c)) {
								if (s.fix == '-') {
									ok = true;
									break;
								} else if (s.fix == '?') {
									row = s;
								}
							}
							if (s.c == c && hc(c, s.r, r)) {
								if (s.fix == '|') {
									ok = true;
									break;
								} else if (s.fix == '?') {
									col = s;
								}
							}
						}
						if (!ok) {
							if (row == null && col == null)
								return imp;
							else if (row != null && col == null){
								row.fix = '-';
								set = true;
							}
							else if (col != null && row == null){
								col.fix = '|';
								set=true;
							}
							else {
								pairs.add(new Sh[] { row, col });
							}
						}
					}
				}
			if (!set)
				break;
		}
		
	
		if(!solve(pairs))return imp;
		for(Sh s:S){
			if(s.fix=='?')s.fix='|';
			B[s.r][s.c]=s.fix;
		}
		if(!validate(S)){
			System.err.println("ERROR!");
		}
		String res ="POSSIBLE\n"+ts(B);
		return res;
	}
	
	
	public static void main(String[] args) throws Exception{
		Locale.setDefault(Locale.US);
		String cn = "src/"+C.class.getName();
		String sampleName = cn+"-sample.in";
		String smallName = cn+"-small-attempt2.in";
		String largeName = cn+"-large.in";
		
		String name = smallName;
		
		String outName = name.substring(0, name.indexOf('.'))+".out";
		InputStream in = new BufferedInputStream(new FileInputStream(name));
		PrintStream out =null;
		out = new PrintStream(new File(outName));
		if(out==null) out = System.out;
		Scanner scan = new Scanner(in);
		
		int N = Integer.parseInt(scan.nextLine());
		for(int c=1;c<=N;c++) {
			String res = new C(scan).solve();
			out.printf("Case #%d: %s\n",c, res);
			if(out!=System.out)System.err.println(c + " done");
		}
		if(out!=System.out)System.err.println("All done");
		
	}
}
