import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args){
		int n=nextInt(),m=nextInt();
		PersistentUnionFind puf=new PersistentUnionFind(n+1);
		for(int i=0;i<m;i++){
			int a=nextInt(),b=nextInt();
			puf.union(a,b);
		}
		int q=nextInt();
		StringBuilder sb=new StringBuilder();
		for(int i=0;i<q;i++){
			int x=nextInt(),y=nextInt(),z=nextInt();
			int left=1,right=m;
			while(left<right){
				int mid=(left+right)/2+(int)(Math.random()*2);
				if(puf.same(x,y,mid)){
					int v=puf.size(x,mid);
					if(v>=z) right=mid;
					else left=mid+1;
				}else{
					int v=puf.size(x,mid)+puf.size(y,mid);
					if(v>=z) right=mid;
					else left=mid+1;
				}
			}
			sb.append(left).append("\n");
		}
		System.out.println(sb);
	}
	
	private static final byte[] buffer = new byte[1024];
	private static int ptr = 0;
	private static int buflen = 0;
	private static boolean hasNextByte() {
		if (ptr < buflen)  return true;
		else{
			ptr = 0;
			try {
				buflen = System.in.read(buffer);
			} catch (IOException e) {e.printStackTrace();}
			if (buflen <= 0)  return false;
		}
		return true;
	}
	private static int readByte() { return hasNextByte() ? buffer[ptr++] : -1;}
	private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
	private static void skipUnprintable() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;}
	public static boolean hasNext() { skipUnprintable(); return hasNextByte();}
	public static String next() {
		if (!hasNext()) throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		for(int b = readByte();isPrintableChar(b);b = readByte()) {
			sb.appendCodePoint(b);
		}
		return sb.toString();
	}
	public static int nextInt() {return (int)nextLong();}
	public static long nextLong() {
		if (!hasNext()) throw new NoSuchElementException();
		long n = 0;
		boolean minus = false;
		int b = readByte();
		if (b == '-') {
			minus = true;
			b = readByte();
		}
		if (b < '0' || '9' < b)  throw new NumberFormatException();
		while(true){
			if ('0' <= b && b <= '9') n = n * 10 + b-'0';
			else if(b == -1 || !isPrintableChar(b)) return minus ? -n : n;
			else throw new NumberFormatException();
			b = readByte();
		}
	}
}
class PersistentUnionFind{
	int[] par;
	int[] time;
	int[] rank;
	ArrayList<Integer>[] history;
	ArrayList<Integer>[] size;
	int now;
	public PersistentUnionFind(int n){
		par=new int[n];
		for(int i=0;i<n;i++) par[i]=i;
		time=new int[n];
		rank=new int[n];
		Arrays.fill(time,Integer.MAX_VALUE);
		now=0;
		
		history=new ArrayList[n];
		size=new ArrayList[n];
		for(int i=0;i<n;i++){
			history[i]=new ArrayList<Integer>();
			size[i]=new ArrayList<Integer>();
			history[i].add(0);
			size[i].add(1);
		}
	}
	int find(int n,int t){
 		if(time[n] > t){
 			return n;
 		}
		return find(par[n],t);
	}
	void union(int x,int y){
		now++;
		x=find(x,now);
		y=find(y,now);
		if(x==y) return;
		if(rank[x] > rank[y]){
			int z=x;
			x=y;
			y=z;
		}
		
		int sx=size[x].get(size[x].size()-1);
		int sy=size[y].get(size[y].size()-1);
		history[y].add(now);
		size[y].add(sx+sy);
		
		time[x]=now;
		if(rank[x]==rank[y]){
			rank[y]++;
		}
		par[x]=y;
	}
	boolean same(int x,int y,int t){
		return find(x,t) == find(y,t);
	}
	int unionTime(int x,int y){
		if(!same(x,y,now)) return -1;
		
		int res=0;
		while(x!=y){
			if(rank[x]<rank[y]){
				res=Math.max(res,time[x]);
				x=par[x];
			}else{
				res=Math.max(res,time[y]);
				y=par[y];
			}
		}
		return res;
	}
	int size(int x,int t){
		x=find(x,t);
		
		int left=0,right=size[x].size()-1;
		while(left<right){
			int mid=(left+right)/2+(left==(right-1)?1:0);
			if(history[x].get(mid)>t) right=mid-1;
			else left=mid;
		}
		return size[x].get(left);
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.