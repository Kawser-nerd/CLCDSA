import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args){
		int n=nextInt(),m=nextInt();
		int[] a=new int[m],b=new int[m];
		SegSumMin ssm=new SegSumMin(n);
		for(int i=0;i<m;i++){
			a[i]=nextInt()-1;
			b[i]=nextInt()-1;
			ssm.add(a[i],b[i],1);
		}
		int[] stack=new int[m];
		int size=0;
		for(int i=0;i<m;i++){
			long min=ssm.min(a[i],b[i]);
			if(min>1) stack[size++]=i;
		}
		pl(size);
		for(int i=0;i<size;i++) pl(stack[i]+1);
		flush();
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
	public static long[] nextLongArray(int i){
		long[] result=new long[i];
		for(int j=0;j<i;j++)  result[j]=nextLong();
		return result;
	}
	public static void nextLongArray(long[]... arrays){
		for(int j=0;j<arrays[0].length;j++)
			for(long[] array:arrays) array[j]=nextLong();
	}
	public static int[] nextIntArray(int i){
		int[] result=new int[i];
		for(int j=0;j<i;j++)  result[j]=nextInt();
		return result;
	}
	public static void nextIntArray(int[]... arrays){
		for(int j=0;j<arrays[0].length;j++)
			for(int[] array:arrays)  array[j]=nextInt();
	}
	public static int ni(){return nextInt();}
	public static long nl(){return nextLong();}
	public static int[] nia(int n){return nextIntArray(n);}
	public static long[] nla(int n){return nextLongArray(n);}
	public static String ne(){return next();}
	
	static StringBuilder sb=new StringBuilder();
	public static void flush(){
		System.out.print(sb);
		sb=new StringBuilder();
	}
	public static void pr(Object o){sb.append(o);}
	public static void pl(Object o){sb.append(o).append("\n");}
	public static void pl(){sb.append("\n");}
}
class SegSumMin{
	int size,n;//size=n*2
	long[] arr;
	long[] lazy;
	public SegSumMin(int n){
		this.n=(n==1)?1:Integer.highestOneBit(n-1)*2;
		size=this.n*2;
		arr=new long[size];
		lazy=new long[size];
		for(int i=this.n+n;i<size;i++) arr[i]=Long.MAX_VALUE/10;
	}
	void add(int left,int right,long v){//right included 0 index
		left+=n;
		right+=n;
		int lc=left,rc=right;
		propagate(left);
		propagate(right);
		
		for(;left<=right;left=(left+1) >> 1 , right=(right-1) >> 1){
			if((left & 1) == 1) lazy[left]+=v;
			if((right & 1) == 0) lazy[right]+=v;
		}
		popUp(lc);
		popUp(rc);
	}
	void popUp(int i){
		for(;i>1;i=(i>>1)) arr[i>>1]=Math.min(arr[i]+lazy[i],arr[i^1]+lazy[i^1]);
	}
	long min(int left,int right){
		left+=n;
		right+=n;
		propagate(left);
		propagate(right);
		
		long res=Long.MAX_VALUE/10;
		for(;left<=right;left=(left+1) >> 1, right=(right-1) >> 1){
			if((left & 1) == 1) res=Math.min(res,arr[left]+lazy[left]);
			if((right & 1 ) == 0) res=Math.min(res,arr[right]+lazy[right]);
		}
		return res;
	}
	void propagate(int i){
		int k=0;
		while((i>>k)>0) k++;
		k--;
		for(;k>=0;k--){
			long v=lazy[(i>>k)];
			lazy[(i>>k)]=0;
			arr[(i>>k)]+=v;
			if(k==0) break;
			lazy[(i>>k)*2]+=v;
			lazy[(i>>k)*2+1]+=v;
		}
	}
}