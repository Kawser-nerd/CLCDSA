import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {


	static ArrayList<Integer>[] ini;
	static ArrayList<Integer> dfs=new ArrayList<Integer>();
	static Heirotree[] V;
	static boolean used[];
//	static HashSet<Integer>[] tree;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		// TODO ???????????????
		Scanner scan = new Scanner(System.in);


		int N=Integer.parseInt(scan.next());
		ini= new ArrayList[N];
		V = new Heirotree[N];
		used = new boolean[N];

		for(int i=0;i<N;i++){
			ini[i]=new ArrayList<Integer>();
		}
		for(int i=0;i<N-1;i++){
			int x=Integer.parseInt(scan.next())-1;
			int y=Integer.parseInt(scan.next())-1;
			ini[x].add(y);
			ini[y].add(x);
		}


		maketree(0);

		PrintWriter out=new PrintWriter(System.out);
		int Q=scan.nextInt();
		for(int i=0;i<Q;i++){
			int a=Integer.parseInt(scan.next())-1;
			int b=Integer.parseInt(scan.next())-1;
			int lca=LCA(a,b);
			out.println(V[a].rank+V[b].rank-2*lca+1);
		}
		out.flush();
	}

	static void maketree(int v){
		if(used[v])return;
		dfs.add(v);
		used[v]=true;

		V[v]=new Heirotree();
		V[v].tree = new ArrayList<Integer>();
		int size=dfs.size();
		V[v].rank=size;
		int two=1;
		while(two<=size){
			V[v].tree.add(dfs.get(size-two));
			two*=2;
		}
		V[v].tree.add(-1);//???-1????
		for(int i=0;i<ini[v].size();i++){
			maketree(ini[v].get(i));
		}
		dfs.remove(dfs.size()-1);
	}

	static int LCA(int v_,int s_){
		//v?s?LCA???
		int v,s;
		if(V[v_].rank>V[s_].rank){
			v=numr(v_,V[s_].rank);
			s=s_;
		}else{
			s=numr(s_,V[v_].rank);
			v=v_;
		}

		int cnt=V[s].tree.size()-1;
		int ans;

		while(true){
			if(cnt<1){
				if(V[v].tree.get(cnt)!=V[s].tree.get(cnt)){
					//?????????????
					ans =V[v].rank-1;
				}else{
					ans=V[v].rank;
				}
				break;
			}
			if(V[v].tree.get(cnt)!=V[s].tree.get(cnt)){
				v=V[v].tree.get(cnt);
				s=V[s].tree.get(cnt);
				cnt=V[s].tree.size()-1;
				continue;
			}
			cnt--;
		}
		return ans;

	}
	static int numr(int v,int rank_){
		//v?rank_??????
		int dis=V[v].rank-rank_+1;//???????
		int two=1;
		int cnt=0;
		while(two<=dis){
			cnt++;//dis=1??cnt=1;
			two*=2;
		}
		two/=2;
		if(two==dis){
			//????
			return V[v].tree.get(cnt-1);
		}else{
			int v_=V[v].tree.get(cnt-1);
			return numr(v_,rank_);
		}
	}
}

class Heirotree{
	int rank;
	ArrayList<Integer> tree;
}

//Set, HashMap ????
// Set?????????????????

//...??????LCA???????????????
//DFS????????????