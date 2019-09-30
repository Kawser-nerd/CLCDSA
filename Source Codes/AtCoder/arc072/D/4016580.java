import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args){
		int n=nextInt();
		long L=nextLong();
		
		long[] queue=new long[n*3];
		int head=0,tail=0;
		double[] queue2=new double[n*3];
		int head2=0,tail2=0;
		long cur=0;
		double netu=0;
		for(int i=0;i<n;i++){
			double t=nextLong();
			long v=nextLong();
			
			cur+=v;
			while(cur>L){
				long hiku=Math.min(cur-L,queue[head]);
				queue[head]-=hiku;
				cur-=hiku;
				netu-=hiku*queue2[head2];
				if(queue[head]==0){
					head++;
					head2++;
				}
			}
			cur-=v;
			while((tail!=head) && (queue2[tail2-1]>t)){
				double nt=(t*v+queue2[tail2-1]*queue[tail-1])/(v+queue[tail-1]);
				t=nt;
				v=v+queue[tail-1];
				cur-=queue[tail-1];
				netu-=queue[tail-1]*queue2[tail2-1];
				tail--;
				tail2--;
			}
			cur+=v;
			queue[tail++]=v;
			queue2[tail2++]=t;
			netu+=v*t;
			pl(netu/L);
		}
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