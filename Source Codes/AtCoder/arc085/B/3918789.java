import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long x=sc.nextLong(),y=sc.nextLong();
		long[] a=new long[n];
		for(int i=0;i<n;i++) a[i]=sc.nextLong();
		
		System.out.println(max(a,0,y));
	}
	static HashMap<Long,Long> minmap=new HashMap<>();
	static long min(long[] a,int teban,long taro){
		long res=Math.abs(a[a.length-1]-taro);
		long key=taro*10000+teban;
		if(minmap.containsKey(key)) return minmap.get(key);
		for(int i=teban;i<a.length-1;i++){
			res=Math.min(res,max(a,i+1,a[i]));
		}
		minmap.put(key,res);
		return res;
	}
	static HashMap<Long,Long> maxmap=new HashMap<>();
	static long max(long[] a,int teban,long ziro){
		long res=Math.abs(a[a.length-1]-ziro);
		long key=ziro*10000+teban;
		if(maxmap.containsKey(key)) return maxmap.get(key);
		for(int i=teban;i<a.length-1;i++){
			res=Math.max(res,min(a,i+1,a[i]));
		}
		maxmap.put(key,res);
		return res;
	}
}