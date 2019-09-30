import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter; 
import java.util.*;

class Main{ 

	static class RMQ{
		int n;
		long[] data;
		RMQ(int nn){
			n=1;
			while(n<nn)n*=2;
			data = new long[n*2];
			Arrays.fill(data, Long.MAX_VALUE/10);
		}
		void set(int i, long v){
			i+=n-1;data[i]=v;
			for(i/=2;i>0;i/=2)data[i]=Math.min(data[2*i], data[2*i+1]);
		}
		long getMin(int a,int b){
			return getMin(a, b, 1, 1, n+1);
		}
		long getMin(int a, int b, int k, int l, int r){
			if(r<=a||b<=l)return Long.MAX_VALUE/10;
			if(a<=l&&r<=b)return data[k];
			return Math.min(getMin(a,b,2*k,l,(l+r)/2), getMin(a,b,2*k+1,(l+r)/2, r));
		}
	}

	static void solve(){
		int n = ni();
		long E = nl(), T=nl();
		long[] x = new long[n+3];
		for(int i=0;i<n;++i)x[i+2]=nl();
		x[n+2] = E;
		long[] dp = new long[n+2];
		RMQ larea = new RMQ(n+3);
		RMQ tarea = new RMQ(n+3);
		larea.set(1, -2*x[2]);
		tarea.set(1, T);
		int index = 1;
		for(int i=2;i<n+2;++i){
			while((x[i]-x[index+1])*2 > T)++index;
			dp[i] = Math.min(larea.getMin(1, index)+3*x[i], tarea.getMin(index, i)+x[i]);
			dp[i] = Math.min(dp[i], dp[i-1] + x[i]-x[i-1] + T);
			larea.set(i, dp[i]-2*x[i+1]-x[i]);
			tarea.set(i, dp[i]-x[i]+T);
		}
		out.println(dp[n+1] + E-x[n+1]);
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