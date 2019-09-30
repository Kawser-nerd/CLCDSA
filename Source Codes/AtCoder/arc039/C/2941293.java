import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter; 
import java.util.*;
class Main{

	static long pos(int x, int y){
		return ((long)x+200001)*1000000000 + (long)y+(200001);
	}
	static class Node{
		int x,y;
		Node(int x, int y){this.x=x;this.y=y;}
		Node l=null,r=null,u=null,d=null;
	}
	static Map<Long, Node> posnode = new HashMap<>();

	static Node dfs(Node node, char dir){
		if(dir=='U'){
			if(node.u!=null)return node.u = dfs(node.u, dir);
			if(posnode.containsKey(pos(node.x, node.y+1))){
				node.u=posnode.get(pos(node.x, node.y+1));
				return node.u = dfs(node.u, dir);
			}
			return node;
		}else if(dir=='D'){
			if(node.d!=null)return node.d = dfs(node.d, dir);
			if(posnode.containsKey(pos(node.x, node.y-1))){
				node.d=posnode.get(pos(node.x, node.y-1));
				return node.d = dfs(node.d, dir);
			}
			return node;
		}else if(dir=='L'){
			if(node.l!=null)return node.l = dfs(node.l, dir);
			if(posnode.containsKey(pos(node.x-1, node.y))){
				node.l=posnode.get(pos(node.x-1, node.y));
				return node.l = dfs(node.l, dir);
			}
			return node;
		}else{
			if(node.r!=null)return node.r = dfs(node.r, dir);
			if(posnode.containsKey(pos(node.x+1, node.y))){
				node.r=posnode.get(pos(node.x+1, node.y));
				return node.r = dfs(node.r, dir);
			}
			return node;
		}
	}

	static void solve(){
		int k = ni();
		String s = ns();
		posnode.put(pos(0,0), new Node(0,0));

		int x = 0, y=0;
		for(int i=0;i<k;++i){
			Node node = dfs(posnode.get(pos(x,y)), s.charAt(i));
			x = node.x; y=node.y;
			if(s.charAt(i)=='U')++y;
			else if(s.charAt(i)=='D')--y;
			else if(s.charAt(i)=='L')--x;
			else ++x;
			posnode.put(pos(x,y), new Node(x,y));
		}
		out.println(x+" "+y);
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