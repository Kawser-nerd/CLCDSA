import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter;
import java.util.PriorityQueue; 

class Main{ 

	static class Node{
		long dis, num;
		Node(long d, long n){dis=d;num=n;}
	}

	static void solve(){ 
		int n = ni();
		long S = nl();
		PriorityQueue<Node> left = new PriorityQueue<>((a,b) -> b.dis-a.dis<0 ? -1:1);
		PriorityQueue<Node> right= new PriorityQueue<>((a,b) -> b.dis-a.dis<0 ? -1:1);
		for(int i=0;i<n;++i){
			long x = nl(), p = nl();
			if(x<S)left.add(new Node(S-x, p));
			else right.add(new Node(x-S, p));
		}
		long sum = 0;
		if(left.isEmpty() || right.isEmpty()){
			if(!left.isEmpty())out.println(left.peek().dis);
			else out.println(right.peek().dis);
			return;
		}
		long ans = 0;
		if(left.peek().num >= right.peek().num)ans=right.peek().dis;
		else ans = left.peek().dis;
		while(true){
			if(left.peek().num>=right.peek().num){
				while(!right.isEmpty() && right.peek().num <= left.peek().num)left.peek().num += right.poll().num;
				ans += left.peek().dis*2;
				if(right.isEmpty())break;
			}else{
				while(!left.isEmpty() && left.peek().num < right.peek().num)right.peek().num += left.poll().num;
				ans += right.peek().dis*2;
				if(left.isEmpty())break;
			}
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