import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter; 

class Main{ 

	static void solve(){
		int n = ni();
		long L=ni();
		long ans = 0;
		long[] x = new long[n];
		boolean left[] = new boolean[n];
		for(int i=0;i<n;++i){
			x[i]=ni();
			left[i] = ns().charAt(0)=='L';
		}
		for(int i=0;i<n;++i){
			if(i==0&&left[i]){
				ans += x[i]-1;x[i]=1;
			}else if(left[i]&&left[i-1]){
				ans += x[i]-x[i-1]-1;
				x[i] = x[i-1]+1;
			}
		}
		for(int i=n-1;i>=0;--i){
			if(i==n-1&&!left[i]){
				ans += L-x[i];x[i]=L;
			}else if(!left[i]&&!left[i+1]){
				ans += x[i+1]-x[i]-1;
				x[i] = x[i+1]-1;
			}
		}
		int index = 0;
		while(index<n){
			long r=0, l=0;
			while(index<n && !left[index]){
				++index;
				++r;
			}
			long dis = (index<n ? x[index]:L+1) - (index>0 ? x[index-1]:0)-1;
			while(index<n && left[index]){
				++l;++index;
			}

			ans += Math.max(l,r)*dis;
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