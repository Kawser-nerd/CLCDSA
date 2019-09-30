import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[] a=new int[n-1],b=new int[n-1];
		for(int i=0;i<n-1;i++){
			a[i]=sc.nextInt();
			b[i]=sc.nextInt();
		}
		int k=sc.nextInt();
		HashMap<Integer,Integer> map=new HashMap<>();
		PriorityQueue<Integer> queue=new PriorityQueue<>((x,y) -> map.get(x)-map.get(y));
		for(int i=0;i<k;i++){
			int v=sc.nextInt(),w=sc.nextInt();
			map.put(v,w);
			queue.add(v);
		}
		
		int[][] ad=get(n,a,b);
		while(queue.size()>0){
			int cur=queue.poll();
			int va=map.get(cur)+1;
			for(int ch:ad[cur]){
				if(map.containsKey(ch)){
					if(Math.abs(map.get(ch)-map.get(cur))!=1){
						System.out.println("No");
						return;
					}
				}else{
					map.put(ch,va);
					queue.add(ch);
				}
			}
		}
		
		System.out.println("Yes");
		for(int i=1;i<=n;i++){
			System.out.println(map.get(i));
		}
	}
	static int[][] get(int n,int[] a,int[] b){
		int[][] res=new int[n+1][];
		int[] c=new int[n+1];
		for(int i=0;i<a.length;i++){
			c[a[i]]++;
			c[b[i]]++;
		}
		for(int i=0;i<=n;i++) res[i]=new int[c[i]];
		for(int i=0;i<a.length;i++){
			res[a[i]][--c[a[i]]]=b[i];
			res[b[i]][--c[b[i]]]=a[i];
		}
		return res;
	}
}