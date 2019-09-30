import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue; 

class Main{ 

	static void solve(){ 
		int n = ni();
		long a = nl(), b=nl();
		long[] arr = nla(n);
		Arrays.sort(arr);
		if(a==1){
			for(long l: arr)out.println(l);
			return;
		}
		long maxele = arr[n-1];
		PriorityQueue<Long> que = new PriorityQueue<>();
		for(int i=0;i<n;++i)que.add(arr[i]);
		while(b>0 && que.peek()<maxele){
			que.add(que.poll()*a);
			--b;
		}
		int cnt = (int)(b/n);
		int amari = (int)(b%n);
		List<Long> ans = new ArrayList<>();
		long mod = (long)1e9+7;
		while(amari-->0){
			long p = que.poll()%mod;
			long mul = a;
			for(int i=0;i<32;++i){
				if((((cnt+1)>>i)&1)==1)p = (p*mul)%mod;
				mul = (mul*mul)%mod;
			}
			ans.add(p);
		}
		List<Long> ans2 = new ArrayList<>();
		while(!que.isEmpty()){
			long p = que.poll()%mod;
			long mul = a;
			for(int i=0;i<32;++i){
				if((((cnt)>>i)&1)==1)p = (p*mul)%mod;
				mul = (mul*mul)%mod;
			}
			ans2.add(p);
		}
		for(Long l: ans2)out.println(l%mod);
		for(Long l: ans)out.println(l%mod);
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