import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter;
import java.util.Arrays; 

class Main{ 

	static void solve(){
		int n = ni(), m = ni();
		int[][] dis = new int[n][n];
		for(int[] arr: dis)Arrays.fill(arr, Integer.MAX_VALUE/10);
		for(int i=0;i<n;++i)dis[i][i]=0;
		for(int i=0;i<m;++i){
			int a = ni()-1, b=ni()-1, c=ni();
			dis[a][b]=dis[b][a]=c;
		}
		for(int k=0;k<n;++k)for(int i=0;i<n;++i)for(int j=0;j<n;++j)dis[i][j]=Math.min(dis[i][j], dis[i][k]+dis[k][j]);
		long sum = 0;
		for(int i=0;i<n;++i)for(int j=i+1;j<n;++j)sum+=dis[i][j];
		int k = ni();
		while(k-->0){
			int x=ni()-1, y=ni()-1, z=ni();
			if(dis[x][y]>z){
				for(int i=0;i<n;++i)for(int j=0;j<n;++j){
					if(dis[i][j]>dis[i][x]+z+dis[y][j]){
						sum -= dis[i][j]-(dis[i][x]+z+dis[y][j]);
						dis[i][j] = dis[j][i] = dis[i][x]+z+dis[y][j];
					}
				}
			}
			out.println(sum);
		}
 
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