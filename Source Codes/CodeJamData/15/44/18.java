import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.*;



import static java.lang.Math.*; 
import static java.util.Arrays.*;
import static java.lang.Character.*;  


public class D {
	
	Scanner scan;
	public D(Scanner s) {
		this.scan = s;
	}
	int[][]M;int n; int m;
	int[][]block;
	
	int res =0;
	
	
	int[][]D = {{-1,0},{1,0}, {0, -1}, {0,1}};
	
	ArrayList<int[][]>Res = new ArrayList<>();
	
	int[][]clone(int[][]M){
		int[][]r = new int[n][m];
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)r[i][j]=M[i][j];
		return r;
	}
	
	void addRes(int[][]M){
		boolean ok = true;
		for(int[][]E:Res){
			for(int off = 0;off<m;off++){
				boolean match = true;
				for(int i=0;i<n;i++)for(int j=0;j<m;j++){
					if(M[i][j]!=E[i][(off+j)%m])match = false;
				}
				if(match)ok = false;
			}

		}
		if(ok)Res.add(clone(M));
	}
	boolean can(int a, int b, int v) {
		return (block[a][b]&(1<<v))==0;
	}
	
	void block(int a, int b, int v){
		block[a][b] |= (1<<v);
	}
	void unblock(int a, int b, int v){
		block[a][b] ^= (1<<v);
	}
	
	void doit(int a, int b){
		if(a==n){
			addRes(M);
			return;
		}
		int nexta=a;int nextb=b+1;
		if(nextb==m){nexta=a+1;nextb=0;}
		int org =M[a][b];
		for(int v =1;v<4;v++) {
			int match =0;
			if(org!=0 && org!=v)continue;
			M[a][b]=v;
			ArrayList<int[]>free = new ArrayList<>();
			if(!can(a,b,v))continue;
			for(int[]d:D){
				int x = a+d[0];int y = b+d[1];
				if(x<0 || x==n)continue;
				y = (m+y)%m;
				if(M[x][y]==0 && can(x,y,v)) {
					free.add(new int[]{x,y});
				} else if(M[x][y]==v){
					match++;
				}
			}
			int freeCount = free.size();
			if(match>v)continue;
			if(match==v) {
				for(int[]f:free)block(f[0],f[1],v);
				doit(nexta, nextb);
				for(int[]f:free)unblock(f[0],f[1],v);
			} else {
				int missing = v - match;
				if(missing>free.size())continue;
				if(missing==free.size()){
					for(int[]f:free)M[f[0]][f[1]]=v;
					doit(nexta, nextb);
					for(int[]f:free)M[f[0]][f[1]]=0;
				} else {
					int toChose = missing;

					for(int mask =0;mask<(1<<freeCount);mask++){
						if(Integer.bitCount(mask)!=toChose)continue;
						for(int i=0;i<freeCount;i++) {
							boolean chosen;
							if((mask&(1<<i))!=0) chosen = true;
							else chosen = false;
							int x = free.get(i)[0];int y = free.get(i)[1];
							if(chosen)M[x][y]=v;
							else block(x,y,v);
						}
						doit(nexta, nextb);
						for(int i=0;i<freeCount;i++) {
							boolean chosen;
							if((mask&(1<<i))!=0) chosen = true;
							else chosen = false;
							int x = free.get(i)[0];int y = free.get(i)[1];
							if(chosen)M[x][y]=0;
							else unblock(x,y,v);
						}
					}
				}
			}
				
			
		}
		M[a][b]=org;
	}
	
	public String solve() {
		n=scan.nextInt();m =scan.nextInt();
		M = new int[n][m];
		block = new int[n][m];
		doit(0,0);
		return ""+Res.size();
	}
	int intLine(){
		return Integer.parseInt(scan.nextLine());
	}
	public static void main(String[] args) throws Exception{
		Locale.setDefault(Locale.US);
		String cn = D.class.getName();
		String sampleName = cn+"-sample.in";
		String smallName = cn+"-small-attempt1.in";
		String largeName = cn+"-large.in";
		String name = smallName;
		String outName = name.substring(0, name.indexOf('.'))+".out";
		InputStream in = new BufferedInputStream(new FileInputStream(name));
		PrintStream out = new PrintStream(new File(outName));
		//PrintStream out = System.out;
		Scanner scan = new Scanner(in);
		
		int N = Integer.parseInt(scan.nextLine());
		for(int c=1;c<=N;c++) {
			String res = new D(scan).solve();
			out.printf("Case #%d: %s\n",c, res);
			if(out!=System.out)System.err.println(c + " done");
		}
		if(out!=System.out)System.err.println("All done");
		
	}

}


