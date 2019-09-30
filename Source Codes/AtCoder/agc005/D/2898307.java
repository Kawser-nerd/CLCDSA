import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List; 

class Main{ 

	static long mod =924844033;
	static long[] fact;
	static long[][] dp;
	static int w,n;

	static void solve(){ 
		n = ni();
		int k=ni();
		fact = new long[n+1];
		fact[0]=1;
		for(int i=1;i<=n;++i)fact[i]=(fact[i-1]*i)%mod;
		// dp[i][j] : ???i????j?????
		dp = new long[n+1][n+1];
		dp[1][0]=dp[2][0]=dp[2][1]=1;
		for(int i=3;i<=n;++i)for(int j=0;j<i;++j){
			if(j==0)dp[i][j]=1;
			else dp[i][j]=(dp[i-1][j]+dp[i-2][j-1])%mod;
		}
		List<Integer> sets = new ArrayList<>();
		for(int i=1;i<=Math.min(n, k);++i){
			int size = 0;
			for(int j=i;j<=n;j+=k)++size;
			sets.add(size);
			sets.add(size);
		}

		long[][] dp2 = new long[sets.size()+1][n+1];
		dp2[0][0]=1;
		for(int i=0;i<sets.size();++i){
			for(int j=0;j<=n;++j){
				for(int l=0;l<=sets.get(i);++l){
					if(j-l<0)break;
					dp2[i+1][j] = (dp2[i+1][j] + (dp2[i][j-l]*dp[sets.get(i)][l])%mod)%mod;
				}
			}
		}
		int m = sets.size();

		long ans = 0;
		for(int i=0;i<=n;++i){
			ans = (ans + ((fact[n-i]*dp2[m][i]%mod)*(i%2==1 ? -1:1)+mod)%mod)%mod;
		}
		out.println(ans);
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