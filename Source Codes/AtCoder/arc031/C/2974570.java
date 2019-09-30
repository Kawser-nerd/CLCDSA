import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter;
import java.util.*;

class Main{
	static class BIT{
		int n;
		int[] data;
		BIT(int nn){
			n=nn;
			data = new int[n+1];
		}
		void add(int i, int v){
			for(;i<=n;i+=i&(-i))data[i]+=v;
		}
		int get(int i){
			int res = 0;
			for(;i>0;i-=i&(-i))res+=data[i];
			return res;
		}
	}

	static class Node{
		int pos, v;
		Node(int p, int v){pos=p;this.v=v;}
	}

	static void solve(){
		int n = ni();
		BIT bit = new BIT(n);
		List<Node> nodes = new ArrayList<>();
		for(int i=1;i<=n;++i)nodes.add(new Node(i, ni()));
		Collections.sort(nodes, (a,b)->b.v-a.v);
		long ans = 0;
		for(Node node: nodes){
			ans += (long)Math.min(bit.get(node.pos-1), bit.get(n)-bit.get(node.pos));
			bit.add(node.pos, 1);
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