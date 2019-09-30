import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long x=sc.nextLong();
		
		int[] a=new int[n];
		for(int i=0;i<n;i++)a[i]=sc.nextInt();
		
		Arrays.sort(a);
		
		HashMap<Long,Long> map1=new HashMap<>();
		HashMap<Long,Long> map2=new HashMap<>();
		
		int zen=n/2;
		
		int c=1;
		for(int i=0;i<zen;i++)c*=2;
		for(int i=0;i<c;i++){
			int d=i;
			long v=0;
			for(int j=0;j<zen;j++){
				if(d%2==0)v+=a[j];
				d/=2;
			}
			if(map1.containsKey(v)) map1.put(v,map1.get(v)+1);
			else map1.put(v,1L);
		}
		
		c=1;
		for(int i=zen;i<n;i++)c*=2;
		for(int i=0;i<c;i++){
			int d=i;
			long v=0;
			for(int j=zen;j<n;j++){
				if(d%2==0)v+=a[j];
				d/=2;
			}
			if(map2.containsKey(v)) map2.put(v,map2.get(v)+1);
			else map2.put(v,1L);
		}
		//System.out.println(map1);
		//System.out.println(map2);
		
		long res=0;
		Set<Long> set=map1.keySet();
		for(long lo:set){
			if(map2.containsKey(x-lo)){
				res+=map1.get(lo)*map2.get(x-lo);
			}
		}
		System.out.println(res);
	}
}