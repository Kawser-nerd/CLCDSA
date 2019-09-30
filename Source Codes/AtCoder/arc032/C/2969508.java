import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.List; 

class Main{ 
	static class Node{
		int id, start, end;
		Node(int id,int start, int end){this.id=id;this.start=start;this.end=end;}
	}

	static void solve(){
		 int n = ni();
		 List<Node> nodes = new ArrayList<>();
		 nodes.add(new Node(0, 2000000, 2000000));
		 for(int i=1;i<=n;++i){
			 int s = ni(), e=ni();
			 nodes.add(new Node(i, s, e));
		 }
		 Collections.sort(nodes, (a,b)->b.start-a.start);
		 int[] size = new int[n+1];
		 List<Integer>[] sizeList = new ArrayList[n+1];
		 for(int i=0;i<=n;++i)sizeList[i]=new ArrayList<>();
		 int[] maxSize = new int[n+1];
		 for(int i=1;i<=n;++i){
			 // i???end???start?index???
			 int l=0,r=i;
			 while(r-l>1){
				int c = (l+r)/2;
				if(nodes.get(i).end>nodes.get(c).start)r=c;
				else l=c;
			 }
			 size[i] = maxSize[l]+1;
			 sizeList[size[i]].add(i);
			 maxSize[i] = Math.max(size[i], maxSize[i-1]);
		 }
		 Deque<Integer> que = new ArrayDeque<>();
		 int bef=-1;
		 for(int i=maxSize[n];i>0;--i){
			 int min = n+1;
			 int next=0;
			 for(int v: sizeList[i])if(nodes.get(v).start>=bef && nodes.get(v).id<min){
				min=nodes.get(v).id;next=nodes.get(v).end;
			 }
			 que.addLast(min);
			 bef=next;
		 }
		 out.println(maxSize[n]);
		 while(!que.isEmpty()){
			 out.print(que.removeFirst());
			 out.print((que.isEmpty() ? "\n":" "));
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.