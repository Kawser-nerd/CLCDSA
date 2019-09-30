import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????
		Mincut mincut =new Mincut();
		Scanner scan = new Scanner(System.in);
		mincut.setdata(scan);



		int cut=0;
		while(mincut.DFS(0)){
			cut++;
			mincut.passed = new boolean[mincut.N+1];
/*			for(int i=0;i<mincut.N+1;i++){
				for(int j=0;j<mincut.Ge[i].size();j++){
					System.out.print(mincut.Ge[i].get(j).used);
				}
				System.out.println();
			}
			System.out.println();*/
		}
		System.out.println(cut);


	}

}

class Mincut{

	int N;
	int G;
	int E;
	int[] p;
	ArrayList<Edge>[] Ge;

	boolean[] passed;

	void setdata(Scanner scan){
		N=scan.nextInt();
		G=scan.nextInt();
		E=scan.nextInt();
		Ge = new ArrayList[N+1];
		p= new int[G];
		passed= new boolean[N+1];//???????
		for(int i=0;i<N+1;i++){
			Ge[i]=new ArrayList<Edge>();
		}

		//??????N????????
		Edge e;
		for(int i=0;i<G;i++){
			p[i]=scan.nextInt();
			Ge[p[i]].add(new Edge(N,0));
			Ge[N].add(new Edge(p[i],0));
		}

		for(int i=0;i<E;i++){
			int from =scan.nextInt();
			int to = scan.nextInt();
			e =new Edge(to,0);
			Ge[from].add(e);
			e =new Edge(from,0);
			Ge[to].add(e);
		}
	}


	//DFS???????
	boolean DFS(int v){
		if(v==N){//?????
			return true;
		}
		//DFS???????????????
		passed[v]=true;
		for(int i=0;i<Ge[v].size();i++){
			Edge e =Ge[v].get(i);
			Edge e_=Ge[v].get(i);
			for(int j=0;j<Ge[e.to].size();j++){
				if(Ge[e.to].get(j).to==v){
					e_=Ge[e.to].get(j);
				}
			}


			if(!passed[e.to]){//??????????????
				if(e.used-e_.used<1){//?????????????????
					if(DFS(e.to)){
						e.used=1;
						return true;
					}
				}

			}
		}
		return false;
	}


}
class Edge {
	int to;
	int used;
	Edge(int to_,int used_){
		to=to_;
		used=used_;
	}

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.