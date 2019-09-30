import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter; 

class Main{ 

	static void solve(){ 
		int n = ni(), k=ni();
		int[][] w = new int[n][n];
		for(int i=0;i<n;++i)for(int j=0;j<n;++j)w[i][j]=ni();
		int[] sum = new int[(1<<n)];
		for(int i=0;i<(1<<n);++i){
			for(int j=0;j<n;++j){
				if(((i>>j)&1)==0)continue;
				for(int m=j;m<n;++m)if(((i>>m)&1)==1)sum[i]+=w[j][m];
			}
		}
		int[] dp = new int[(1<<n)];

		for(int i=1;i<=n;i++){
			for(int comb = (1<<i)-1;comb<(1<<n);comb = ((comb&~(comb+(comb&-comb)))/(comb&-comb)>>1)|comb+(comb&-comb)){
				dp[comb] =k;
				for(int m=((1<<n)-1)&comb;m>0;--m){
					m&=comb;
					dp[comb] = Math.max(dp[comb], dp[m] + dp[comb&(~m)] - (sum[comb] - sum[m] - sum[comb&(~m)]));
				}
			}
		}
		out.println(dp[(1<<n)-1]);

	} 
 
 
 
 
	public static void main(String[] args){ 
		 solve(); 
		 out.flush(); 
	 } 
	 private static InputStream in = System.in; 
	 private static PrintWriter out = new PrintWriter(System.out); 
 
	 private static final byte[] buffer = new byte[1<<15]; 
	 private static int ptr = 0; 
	 private static int buflen = 0; 
	 private static boolean hasNextByte(){ 
		 if(ptr<buflen)return true; 
		 ptr = 0; 
		 try{ 
			 buflen = in.read(buffer); 
		 } catch (IOException e){ 
			 e.printStackTrace(); 
		 } 
		 return buflen>0; 
	 } 
	 private static int readByte(){ if(hasNextByte()) return buffer[ptr++]; else return -1;} 
	 private static boolean isSpaceChar(int c){ return !(33<=c && c<=126);} 
	 private static int skip(){int res; while((res=readByte())!=-1 && isSpaceChar(res)); return res;} 
 
	 private static double nd(){ return Double.parseDouble(ns()); } 
	 private static char nc(){ return (char)skip(); } 
	 private static String ns(){ 
		 StringBuilder sb = new StringBuilder(); 
		 for(int b=skip();!isSpaceChar(b);b=readByte())sb.append((char)b); 
		 return sb.toString(); 
	 } 
	 private static int[] nia(int n){ 
		 int[] res = new int[n]; 
		 for(int i=0;i<n;++i)res[i]=ni(); 
		 return res; 
	 } 
	 private static long[] nla(int n){ 
		 long[] res = new long[n]; 
		 for(int i=0;i<n;++i)res[i]=nl(); 
		 return res; 
	 } 
	 private static int ni(){ 
		 int res=0,b; 
		 boolean minus=false; 
		 while((b=readByte())!=-1 && !((b>='0'&&b<='9') || b=='-')); 
		 if(b=='-'){ 
			 minus=true; 
			 b=readByte(); 
		 } 
		 for(;'0'<=b&&b<='9';b=readByte())res=res*10+(b-'0'); 
		 return minus ? -res:res; 
	 } 
	 private static long nl(){ 
		 long res=0,b; 
		 boolean minus=false; 
		 while((b=readByte())!=-1 && !((b>='0'&&b<='9') || b=='-')); 
		 if(b=='-'){ 
			 minus=true; 
			 b=readByte(); 
		 } 
		 for(;'0'<=b&&b<='9';b=readByte())res=res*10+(b-'0'); 
		 return minus ? -res:res; 
	} 
}