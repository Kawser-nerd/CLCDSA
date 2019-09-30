import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),m=sc.nextInt();
		int[] a=new int[m],b=new int[m],c=new int[m];
		for(int i=0;i<m;i++){
			a[i]=sc.nextInt();
			b[i]=sc.nextInt();
			c[i]=sc.nextInt();
		}
		
		HashMap<Long,Integer> map=new HashMap<>();
		int num=1;
		for(int i=0;i<m;i++){
			long as=a[i]+c[i]*100001L,bs=b[i]+c[i]*100001L;
			if(!map.containsKey((long)a[i])) map.put((long)a[i],num++);
			if(!map.containsKey((long)b[i])) map.put((long)b[i],num++);
			if(!map.containsKey(as)) map.put(as,num++);
			if(!map.containsKey(bs)) map.put(bs,num++);
		}
		
		//System.out.println((Runtime.getRuntime().totalMemory()-Runtime.getRuntime().freeMemory())/1024/1024);
		//System.out.println(num);
		UF uf=new UF(num+1);
		for(int i=0;i<m;i++){
			long as=a[i]+c[i]*100001L,bs=b[i]+c[i]*100001L;
			int asi=map.get(as),bsi=map.get(bs);
			
			uf.union(asi,bsi);
		}
		//System.out.println((Runtime.getRuntime().totalMemory()-Runtime.getRuntime().freeMemory())/1024/1024);
		
		int[] na=new int[m*2],nb=new int[m*2];
		int ind=0;
		HashSet<Long> set=new HashSet<>();
		for(int i=0;i<m;i++){
			long as=a[i]+c[i]*100001L,bs=b[i]+c[i]*100001L;
			int asi=map.get(as),bsi=map.get(bs);
			int ai=map.get((long)a[i]),bi=map.get((long)b[i]);
			int root=uf.find(asi);
			
			if(!set.contains(ai+root*100000L)){
				set.add(ai+root*100000L);
				na[ind]=ai;
				nb[ind++]=root;
			}
			if(!set.contains(bi+root*100000L)){
				set.add(bi+root*100000L);
				na[ind]=bi;
				nb[ind++]=root;
			}
		}
		na=Arrays.copyOf(na,ind);
		nb=Arrays.copyOf(nb,ind);
		//System.out.println(ind);
		
		int[][] ad=get(na,nb,num-1);
		
		try{
			int start=map.get(1L);
			int goal=map.get((long)n);
			int res=dijkstra(start,goal,ad);
			System.out.println(res==Integer.MAX_VALUE?-1:res/2);
		}catch(Exception e){
			System.out.println(-1);
		}
		//System.out.println((Runtime.getRuntime().totalMemory()-Runtime.getRuntime().freeMemory())/1024/1024);
	}
	static int[][] get(int[] a,int[] b,int n){
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
	static int dijkstra(int start,int goal,int[][] ad){
		int n=ad.length;
		int[] res=new int[n];
		Arrays.fill(res,Integer.MAX_VALUE);
		res[start]=0;
		
		PriorityQueue<Integer> queue=new PriorityQueue<>((x,y)->res[x]-res[y]);
		queue.add(start);
		while(queue.size()>0){
			int cur=queue.poll();
			for(int ch:ad[cur]){
				int dist=res[cur]+1;
				if(dist<res[ch]){
					res[ch]=dist;
					queue.add(ch);
				}
			}
		}
		return res[goal];
	}
}

class UF {
    private int[] parent;
    private byte[] rank;   // rank[i] = rank of subtree rooted at i (never more than 31)
    private int count;     // number of components

    public UF(int n) {
        count = n;
        parent = new int[n];
        rank = new byte[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    public int find(int p) {
    	if(p==parent[p])return p;
    	parent[p]=find(parent[p]);
        return parent[p];
    }

    public int count() {
        return count;
    }
  
    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }
  
    public void union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;

        // make root of smaller rank point to root of larger rank
        if      (rank[rootP] < rank[rootQ]) parent[rootP] = rootQ;
        else if (rank[rootP] > rank[rootQ]) parent[rootQ] = rootP;
        else {
            parent[rootQ] = rootP;
            rank[rootP]++;
        }
        count--;
    }
}