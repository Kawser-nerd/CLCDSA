import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.TreeMap; 

class Main{ 

	static void solve(){ 
		int w=ni(), h=ni(), q=ni();
		TreeMap<Integer, PriorityQueue<Integer> > xaxis = new TreeMap<>();
		TreeMap<Integer, PriorityQueue<Integer> > yaxis = new TreeMap<>();
		long[] dpx = new long[w+2];
		dpx[0]=dpx[w+1]=Long.MAX_VALUE/10;
		long[] dpy = new long[h+2];
		dpy[0]=dpy[h+1]=Long.MAX_VALUE/10;
		while(q-->0){
			int t = ni(), d = ni(), x=ni();
			if(d==0){
				if(!xaxis.containsKey(t))xaxis.put(t, new PriorityQueue<>(Collections.reverseOrder()));
				xaxis.get(t).add(x);
			}else{
				if(!yaxis.containsKey(t))yaxis.put(t, new PriorityQueue<>(Collections.reverseOrder()));
				yaxis.get(t).add(x);
			}
		}
		for(Map.Entry<Integer, PriorityQueue<Integer>> entry: xaxis.descendingMap().entrySet()){
			PriorityQueue<Integer> que = entry.getValue();
			while(!que.isEmpty()){
				int r = que.poll();
				int l = r;
				while(!que.isEmpty() && que.peek()==l-1)l=que.poll();
				for(int i=l;i<=r;++i)dpx[i] = Math.min(dpx[l-1]+i-(l-1), dpx[r+1]+(r+1)-i);
			}
		}
		for(Map.Entry<Integer, PriorityQueue<Integer>> entry: yaxis.descendingMap().entrySet()){
			PriorityQueue<Integer> que = entry.getValue();
			while(!que.isEmpty()){
				int r = que.poll();
				int l = r;
				while(!que.isEmpty() && que.peek()==l-1)l=que.poll();
				for(int i=l;i<=r;++i)dpy[i] = Math.min(dpy[l-1]+i-(l-1), dpy[r+1]+(r+1)-i);
			}
		}
		long minx = Long.MAX_VALUE/10, miny=Long.MAX_VALUE/10;
		for(int i=0;i<=w;++i)minx=Math.min(minx, dpx[i]);
		for(int i=0;i<=h;++i)miny=Math.min(miny, dpy[i]);
		out.println(minx+miny > Integer.MAX_VALUE ? -1:minx+miny);

 
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