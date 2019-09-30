import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue; 

class Main{ 

	static class Node{
		int c;
		long w;
		Node(int c,long w){this.c=c;this.w=w;}
	}

	static void solve(){ 
		int n = ni();
		long x = nl(), y=nl();
		mod = (long)1e9+7;
		int[] c = new int[n];
		long[] w = new long[n];
		for(int i=0;i<n;++i){
			c[i]=ni()-1;
			w[i]=nl();
		}
		long[] cTominw = new long[n];
		Arrays.fill(cTominw, Integer.MAX_VALUE);
		for(int i=0;i<n;++i){
			cTominw[c[i]]=Math.min(cTominw[c[i]], w[i]);
		}
		for(int i=0;i<n;++i)if(w[i]+cTominw[c[i]]<=x)w[i]=cTominw[c[i]];
		PriorityQueue<Node> que = new PriorityQueue<>((a,b)->a.w-b.w<0 ? -1:1);
		for(int i=0;i<n;++i)if(cTominw[i]<Integer.MAX_VALUE)que.add(new Node(i, cTominw[i]));
		Map<Integer, Integer> cton = new HashMap<>();
		int minc = que.peek().c;
		long minw = que.peek().w;
		for(int i=0;i<n;++i)if(c[i]!=minc && w[i]+minw<=y)w[i]=minw;
		que.poll();
		if(que.isEmpty()){
			out.println(1);return;
		}
		int nextc = que.peek().c;
		long nextw = que.peek().w;
		for(int i=0;i<n;++i)if(c[i]==minc && w[i]+nextw<=y)w[i]=minw;
		if(minw*2>y){
			out.println(1);return;
		}
		int all = 0;
		for(int i=0;i<n;++i)if(w[i]==minw){
			++all;
			cton.put(c[i], cton.getOrDefault(c[i], 0)+1);
		}
		fact = new long[n+1];
		fact[0]=1;
		for(int i=1;i<=n;++i)fact[i]=(fact[i-1]*i)%mod;
		inv = new long[n+1];
		for(int i=0;i<=n;++i)inv[i]=fact[i];
		for(int i=0;i<=n;++i){
			long res = 1;
			for(int j=0;j<32;++j){
				if((((mod-2)>>j)&1)==1)res=(res*inv[i])%mod;
				inv[i]=(inv[i]*inv[i])%mod;
			}
			inv[i]=res;
		}
		long ans = fact[all];
		for(int cnt: cton.values()){
			ans=(ans*inv[cnt])%mod;
		}
		out.println(ans);
	} 
	static long[] fact;
	static long[] inv;
	static long mod;
	static long comb(int n, int m){
		return ((fact[n]*inv[m]%mod)*inv[n-m])%mod;
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