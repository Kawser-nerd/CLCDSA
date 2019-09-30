import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        String [][]a=new String[m][2];
        for(int i=0;i<m;i++){
            a[i][0]=sc.next();
            a[i][1]=sc.next();
        }
        int ans=0;
        for(int i=0;i<m;i++){
            Graph g=new Graph();
            for(int j=0;j<n;j++)g.add((j+1)+"");
            for(int j=0;j<m;j++){
                if(i!=j)g.add(a[j][0],a[j][1]);
            }
            if(g.connectedCompo()!=1)ans++;
        }
        System.out.println(ans);
    }
}
class Graph {
	Map<String, ArrayList<String>> edge ;
	Map<String, Integer> vertex ;
	public Graph() {
		edge = new HashMap<String, ArrayList<String>>();
		vertex=new HashMap<String,Integer>();
	}
	public void add(String a) {
		if (!edge.containsKey(a)) {
			ArrayList<String>cont=new ArrayList<>();
			edge.put(a,cont);
			vertex.put(a,1);
		}
	}
	public void add(String a, String b) {
		if (edge.containsKey(a)) {
			edge.get(a).add(b);
			vertex.put(a,vertex.get(a)+1);
		} else {
			ArrayList<String>cont=new ArrayList<>();
			cont.add(b);
			edge.put(a, cont);
			vertex.put(a,1);
		}
		if (edge.containsKey(b)) {
			edge.get(b).add(a);
			vertex.put(b,vertex.get(b)+1);
		} else {
			ArrayList<String>cont=new ArrayList<>();
			cont.add(a);
			edge.put(b, cont);
			vertex.put(b,1);
		}
	}
	public int connectedCompo() {
		Map<String,Integer>copyV=new HashMap<>(vertex);
		int count=0;
		while(copyV.size()!=0) {
			count++;
			String a="";
			for(String key:copyV.keySet()) {
				a=key;
				break;
			}
			copyV.remove(a);
			ArrayList<String>queue=new ArrayList<>();
			queue.add(a);
			Map<String,Boolean>check=new HashMap<String,Boolean>();
			check.put(a,false);
			while(queue.size()!=0) {
				ArrayList<String>cont=edge.get(queue.get(0));
				queue.remove(0);
				for(int i=0;i<cont.size();i++) {
					if(!check.containsKey(cont.get(i))) {
						copyV.remove(cont.get(i));
						queue.add(cont.get(i));
						check.put(cont.get(i),false);
					}
				}
			}
		}
		return count;
	}

}