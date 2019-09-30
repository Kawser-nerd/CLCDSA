import java.util.*;

class Edge{
	int a,b,c;
	public Edge(int A,int B,int C){
		a=A;
		b=B;
		c=C;
	}
}
class Main{
	static Scanner s=new Scanner(System.in);

	static int gInt(){
		return Integer.parseInt(s.next());
	}

	public static void main(String[]$){
		final long INIT=Long.MAX_VALUE;

		TreeMap<Integer,List<Edge>>a=new TreeMap<>();
		int n=gInt(),m=gInt();
		long[] pos=new long[n];
		Arrays.fill(pos,INIT);

		for(int q=0;q<m;++q){
			int l=gInt()-1,r=gInt()-1,d=gInt();
			a.computeIfAbsent(l,(i)->new ArrayList<>(1)).add(new Edge(l,r,d));
			a.computeIfAbsent(r,(i)->new ArrayList<>(1)).add(new Edge(r,l,-d));
		}

		Deque<Edge> d=new ArrayDeque<>();
		while(!a.isEmpty()){
			d.addAll(a.pollFirstEntry().getValue());
			while(!d.isEmpty()){
				Edge o=d.poll();
				if(pos[o.a]==INIT){
					pos[o.a]=0;
				}
				if(pos[o.b]==INIT){
					pos[o.b]=pos[o.a]+o.c;
					List<Edge> v=a.remove(o.b);
					if(v!=null)
						d.addAll(v);
				}
				if(pos[o.b]-pos[o.a]!=o.c){
					System.out.println("No");
					return;
				}
			}
		}
		System.out.println("Yes");
	}
}