import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args){
		int n=nextInt(),q=nextInt();
		int a=nextInt(),b=nextInt();
		int[] x=new int[q];
		for(int i=0;i<q;i++) x[i]=nextInt();
		SegSumMin ssm1=new SegSumMin(n+1);
		SegSumMin ssm2=new SegSumMin(n+1);
		
		ssm1.add(a,a,0-a);
		ssm2.add(a,a,0+a);
		ssm1.add(0,a-1,Long.MAX_VALUE/10);
		ssm1.add(a+1,n,Long.MAX_VALUE/10);
		ssm2.add(0,a-1,Long.MAX_VALUE/10);
		ssm2.add(a+1,n,Long.MAX_VALUE/10);
		int prev=b;
		long sum=0;
		for(int i=0;i<q;i++){
			//0 to x[i]-1
			long min=ssm1.min(0,x[i]-1)+sum+x[i];
			//x[i] to n
			min=Math.min(min,ssm2.min(x[i],n)+sum-x[i]);
			sum+=Math.abs(x[i]-prev);
			ssm1.add(prev,prev,-ssm1.min(prev,prev)-sum +min-prev);
			ssm2.add(prev,prev,-ssm2.min(prev,prev)-sum +min+prev);
			
			prev=x[i];
		}
		long res=Long.MAX_VALUE/10;
		for(int i=0;i<=n;i++) res=Math.min(res,i+ssm1.min(i,i));
		System.out.println(res+sum);
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
		if(left>right) return;
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
		
		long res=Long.MAX_VALUE/2;
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
			try{
			lazy[(i>>k)*2]+=v;
			lazy[(i>>k)*2+1]+=v;
				}catch(Exception e){System.out.println(i+" "+k);}
		}
	}
}