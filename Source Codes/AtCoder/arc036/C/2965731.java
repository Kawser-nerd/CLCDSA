import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter; 

class Main{ 

	static void solve(){ 
		int n = ni(), k=ni();
		String s = ns();
		long[][][] dp = new long[n+1][k+1][2];
		long mod = (long)1e9+7;
		dp[0][0][1]=1;
		for(int i=1;i<=k;++i)dp[0][i][0]=1;
		for(int i=0;i<n;++i){
			for(int j=0;j<=k;++j){
				for(int f=0;f<2;++f){
					if(s.charAt(i)=='1'){
						if(j>0)dp[i+1][j][f]=(dp[i+1][j][f] + dp[i][j-1][f])%mod;
						else dp[i+1][j][f]=0;
					}else if(s.charAt(i)=='0'){
						if(j<k){
							if(j==0&&f==0)continue;
							else if(j==0&&f==1)dp[i+1][j][f] = ((dp[i+1][j][f] + dp[i][j+1][0])%mod + dp[i][j+1][1])%mod;
							else dp[i+1][j][f] = (dp[i+1][j][f] + dp[i][j+1][f])%mod;
						}else dp[i+1][j][f]=0;
					}else{
						if(j>0)dp[i+1][j][f] = (dp[i+1][j][f] + dp[i][j-1][f])%mod;
						if(j<k){
							if(j==0&&f==0)continue;
							else if(j==0&&f==1)dp[i+1][j][f] = ((dp[i+1][j][f] + dp[i][j+1][0])%mod + dp[i][j+1][1])%mod;
							else dp[i+1][j][f] = (dp[i+1][j][f] + dp[i][j+1][f])%mod;
						}
					}
				}
//				System.out.println(i+" "+j+" , : "+ dp[i+1][j][0]+" " +dp[i+1][j][1]);
			}
		}
		long ans = 0;
		for(int i=0;i<=k;++i){
			ans = (ans + dp[n][i][1])%mod;
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