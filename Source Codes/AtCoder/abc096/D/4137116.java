import java.util.ArrayList;
import java.util.Scanner;

class Main{


	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//?????
		int n = sc.nextInt();
		ArrayList<Integer> data = new ArrayList<Integer>();
		for(int i = 2;i <= 55555;i++){
			boolean ok = true;
			for(int j = 2; j*j <= i;j++){
				if(i%j == 0){
					ok = false;
					break;
				}
			}
			if(ok){
				if((i - 1) % 10 == 0){
					data.add(i);
				}
			}
		}
		for(int i = 0;i < n;i++){
			System.out.println(data.get(i));
		}




	}





}

class UnionFind{
	int[] parent;
	public UnionFind(int N){
		this.parent = new int[N];
		for(int i = 0; i < N;i++){
			parent[i] = i;
		}
	}
	public int root(int x){			//??????
		if(parent[x] == x){			//????
			return x;
		}else{
			return parent[x] = root(parent[x]);    	//??????????
		}
	}
	public void unite(int x,int y){ 	//??????
		if(same(x,y)){					//???????
			return;
		}
		int xroot = root(x);
		int yroot = root(y);
		parent[xroot] = yroot;			//??
		return;

	}

	public boolean same(int x,int y){			//???????????????????????
		return(root(x) == root(y));
	}
}



class Pair implements Comparable{
	int from;		//p
	int end;		//y
	int num;
	int bango;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return end - otherpair.end;
	}
}