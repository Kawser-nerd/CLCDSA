import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		String s=sc.next();
		int n=s.length();
		
		int[] kosu=new int[26];
		for(int i=0;i<n;i++){
			char ch=s.charAt(i);
			kosu[(int)(ch-'a')]++;
		}
		
		int kisu=0;
		for(int i:kosu) kisu+=i%2;
		if(kisu>1){
			System.out.println(-1);
			return;
		}
		
		long[] b=new long[s.length()];
		int[] kosu2=new int[26];
		long[] zen=new long[n/2],kou=new long[n/2];
		int zsize=0,ksize=0;
		for(int i=0;i<s.length();i++){
			char ch=s.charAt(i);
			int ich=(int)(ch-'a');
			kosu2[ich]++;
			if(kosu[ich] == (2*kosu2[ich]-1)){
				b[i]=1;
			}else if(kosu[ich]/2 >= kosu2[ich]){
				b[i]=0;
				zen[zsize++]=ich;
			}else{
				b[i]=2;
				kou[ksize++]=ich;
			}
		}
		long res=inversion(b);
		
		long[] kkou=new long[n/2];
		for(int i=0;i<n/2;i++) kkou[i]=kou[n/2-i-1];
		long res2=countSort(zen,kkou);
		System.out.println(res+res2);
	}
	static long countSort(long[] a,long[] b){// a wo b ni surutameno sort kaisuu
		int n=a.length;
		HashMap<Long,PriorityQueue<Integer>> map=new HashMap<>();
		for(int i=0;i<n;i++){
			PriorityQueue<Integer> queue=(map.containsKey(a[i]))?map.get(a[i]):new PriorityQueue<>();
			queue.add(i);
			map.put(a[i],queue);
		}
		
		long[] c=new long[n];
		for(int i=0;i<n;i++){
			c[i]=map.get(b[i]).poll();
		}
		return inversion(c);
	}
	static long inversion(long[] a){// count i>j && a[i]<a[j]
		int n=a.length;
		HashMap<Long,Integer> map=new HashMap<>();
		long[] b=Arrays.copyOf(a,a.length);
		Arrays.sort(b);
		int num=0;
		for(int i=0;i<n;i++){
			if(!map.containsKey(b[i])) map.put(b[i],num++);
		}
		BIT bit=new BIT(n);
		long res=0;
		for(int i=n-1;i>=0;i--){
			int c=map.get(a[i]);
			res+=bit.sum(c);
			bit.add(c+1,1);
		}
		return res;
	}
}
class BIT{
	int size;
	long[] arr;
	public BIT(int n){
		size=n+1;
		arr=new long[size+1];
	}
	void add(int i,long v){//0 indexed
		i++;
		for(int x=i;x<=size;x+=(x & (-x))) arr[x]+=v;
	}
	long sum(int i){// h[0]+...+h[i]
		i++;//arr[1]+...+arr[i+1]
		long res=0;
		for(int x=i;x>0;x-=(x & (-x))) res+=arr[x];
		return res;
	}
}