import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class A {

	final static long MOD=1000002013;

	long calc(int o, int e, int n){
		if(o==e)return 0;
		long count=e-o;
		return (n*1l*count-count*(count-1)/2)%MOD;
	}

	void solve() throws IOException {
		int t=nextInt();
		for(int testCase=0;testCase<t;testCase++){
			int n=nextInt();
			int m=nextInt();
			int[] e=new int[m+1];
			int[] o=new int[m+1];
			int[] p=new int[m+1];
			long total=0;
			for(int i=0;i<m;i++){
				o[i]=nextInt();
				e[i]=nextInt();
				p[i]=nextInt();
				total+=calc(o[i],e[i],n)*p[i];
				total=total%MOD;
			}
			for(int i=1;i<m;i++)
				for(int j=0;j<m-i;j++)
					if(o[j]>o[j+1]||(o[j]==o[j+1]&&e[j]>e[j+1])){
						int tmp=o[j];
						o[j]=o[j+1];
						o[j+1]=tmp;
						tmp=e[j];
						e[j]=e[j+1];
						e[j+1]=tmp;
						tmp=p[j];
						p[j]=p[j+1];
						p[j+1]=tmp;
					}
			e[m]=n+1;
			o[m]=n+1;
			p[m]=0;
			TreeMap<Integer,Long> exit=new TreeMap<Integer, Long>();
			TreeMap<Integer,Long> enter=new TreeMap<Integer, Long>();
			long cheat=0;
			for(int i=0;i<=m;){
				int cur=o[i];
				while(exit.size()!=0&&exit.firstKey()<cur){
					int curE=exit.firstKey();
					long curC=exit.get(curE);
					while(curC!=0){
						int CurEn=enter.lastKey();
						long curCe=enter.get(CurEn);
						if(curC>=curCe){
							enter.remove(CurEn);

							curC-=curCe;
							curCe%=MOD;
							cheat+=calc(CurEn,curE,n)*curCe;
						}
						else{
							enter.put(CurEn,curCe-curC);
							curC%=MOD;
							cheat+=calc(CurEn,curE,n)*curC;
							curC=0;
						}
						cheat%=MOD;
					}
					exit.remove(curE);
				}
				while(i<=m&&o[i]==cur){
					if(exit.containsKey(e[i]))
						exit.put(e[i],exit.get(e[i])+p[i]);
					else
						exit.put(e[i],(long)p[i]);

					if(enter.containsKey(o[i]))
						enter.put(o[i],enter.get(o[i])+p[i]);
					else
						enter.put(o[i],(long)p[i]);
					i++;
				}
			}
			long ans=total-cheat;
			if(ans<0)ans+=MOD;
			out.printf("Case #%d: %d\n",testCase+1,ans);
		}

	}

	public static void main(String[] args) throws IOException {
		new A().run();
	}

	void run() throws IOException {
//		reader = new BufferedReader(new InputStreamReader(System.in));
//
//		out = new PrintWriter(new OutputStreamWriter(System.out));
		reader = new BufferedReader(new FileReader("input.txt"));

		out = new PrintWriter(new FileWriter("output.txt"));
		tokenizer = null;
		solve();
		reader.close();
		out.flush();

	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter out;

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
}
