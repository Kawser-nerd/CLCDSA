import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args){
		int n=nextInt(),m=nextInt();
		long[] a=new long[n-1];
		for(int i=0;i<n-1;i++) a[i]=nextLong();
		int[][] ta=new int[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++) ta[i][j]=nextInt();
		}
		long[] dist=new long[n];
		for(int i=1;i<n;i++){
			dist[i]=dist[i-1]+a[i-1];
		}
		
		HashMap<Integer,Long> map=new HashMap<>();
		int[] ext=new int[n];
		RMQ rmq=new RMQ(ext);
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				ext[j]=ta[j][i];
			}
			rmq.renew(ext);
			fill(map,ext,rmq,0,n-1);
			//if(i%50==0)System.gc();
		}
		
		
		long total = Runtime.getRuntime().totalMemory();
        long free = Runtime.getRuntime().freeMemory();
        long used = total - free;/*
        System.out.println("total => " + total / 1024 + "KB");
        System.out.println("free  => " + free / 1024 + "KB");
        System.out.println("used  => " + (total - free) / 1024 + "KB");*/
		long[] dp=new long[n];
		long[] ndp=new long[n];
		long res=0;
		for(int i=0;i<n;i++){
			long sum=0;
			for(int j=0;j<n;j++){
				Long ad=map.get(6000*i+j);
				if(ad==null) ad=0L;
				sum+=ad;
				ndp[j]=sum+dp[j];
				
				if(i>j) continue;
				long kou=ndp[j]-(dist[j]-dist[i]);
				res=Math.max(res,kou);
			}
			long[] te=ndp;
			ndp=dp;
			dp=te;
			
			total = Runtime.getRuntime().totalMemory();
        	free = Runtime.getRuntime().freeMemory();
        	used = total - free;
			if(used >= (1024*1024*150)) System.gc();
		}
		System.out.println(res);
		/*
		total = Runtime.getRuntime().totalMemory();
        free = Runtime.getRuntime().freeMemory();
        used = total - free;
        System.out.println("total => " + total / 1024 + "KB");
        System.out.println("free  => " + free / 1024 + "KB");
        System.out.println("used  => " + (total - free) / 1024 + "KB");*/
	}
	static void fill(HashMap<Integer,Long> map,int[] ext,RMQ rmq,int left,int right){
		if(left>right)return;
		int ind=rmq.rangeMax(left,right);
		add(map,left,ind,ext[ind]);
		add(map,ind+1,right+1,ext[ind]);
		add(map,ind+1,ind,-ext[ind]);
		add(map,left,right+1,-ext[ind]);
		
		fill(map,ext,rmq,left,ind-1);
		fill(map,ext,rmq,ind+1,right);
	}
	static void add(HashMap<Integer,Long> map,int x,int y,long v){
		int key=x*6000+y;
		if(map.containsKey(key)) map.put(key,map.get(key)+v);
		else map.put(key,v);
	}
	static long get(HashMap<Integer,Long> map,int x,int y){
		int key=x*6000+y;
		if(!map.containsKey(key)) return 0;
		else return map.get(key);
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
class RMQ{//return index
	int[] arr;
	int[] hai;
	int size,n;
	int inf=Integer.MIN_VALUE/10;
	RMQ(int[] hai){
		this.n=(hai.length==1?1:2*Integer.highestOneBit(hai.length-1));
		size=2*n;
		this.hai=new int[n];
		arr=new int[size];
		Arrays.fill(this.hai,inf);
		for(int i=0;i<hai.length;i++){
			this.hai[i]=hai[i];
		}
		for(int i=0;i<n;i++){
			arr[n+i]=i;
		}
		for(int i=n-1;i>0;i--){
			arr[i]=(this.hai[arr[2*i]]<this.hai[arr[2*i+1]])?arr[2*i+1]:arr[2*i];
		}
	}
	void renew(int[] hai){//same size
		Arrays.fill(this.hai,inf);
		for(int i=0;i<hai.length;i++){
			this.hai[i]=hai[i];
		}
		for(int i=0;i<n;i++){
			arr[n+i]=i;
		}
		for(int i=n-1;i>0;i--){
			arr[i]=(this.hai[arr[2*i]]<this.hai[arr[2*i+1]])?arr[2*i+1]:arr[2*i];
		}
	}
	int rangeMax(int left,int right){//right included
		if(left>right)return -1;
		int res=left;
		left+=n;
		right+=n;
		
		for(;left<=right;left=(left+1)>>1,right=(right-1)>>1){
			if((left&1)==1){
				res=(hai[res]<hai[arr[left]])?arr[left]:res;
			}
			if((right&1)==0){
				res=(hai[res]<hai[arr[right]])?arr[right]:res;
			}
		}
		return res;
	}
}