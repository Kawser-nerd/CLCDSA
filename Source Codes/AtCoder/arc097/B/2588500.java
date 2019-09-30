import java.util.ArrayList;
import java.util.*;

class Main{
	public static void main(String[] args){

		//permutation
		List<Integer> perm = new ArrayList<>();
		//swap pair
		UnionFind unionFind;

		//Count
		int count = 0;

		Scanner scan = new Scanner(System.in);

		//permutation size
		int permMax = Integer.parseInt(scan.next());
		unionFind = new UnionFind(permMax);
		//pair size
		int pairMax = Integer.parseInt(scan.next());

		//string to int
		for(int i = 0; i < permMax; i++){
			perm.add(Integer.parseInt(scan.next()));
		}

		//set pair
		for(int i = 0; i < pairMax; i++){

			int x = Integer.parseInt(scan.next()) - 1;
			int y = Integer.parseInt(scan.next()) - 1;
			unionFind.union(x, y);
		}

		//sum
		for(int x = 0; x < perm.size(); x++){

			int value = x + 1;
			//????????????
			if(value == perm.get(x)){
				count++;
				continue;

			}

			//?????????
			//swap?????????????	
			if(unionFind.same(x, perm.get(x) - 1)){
				count++;
				continue;
			}
		}

		System.out.println(count);

	}
}

class UnionFind{
	int par[];
	int rank[];

	public UnionFind(int size){
		par = new int[size];
		rank = new int [size];

		for(int i = 0; i < size; i++){
			par[i] = i;
			rank[i] = 0;
		}
	}

	/**
	 *root??????????
	 *
	 */
	int find(int x){
		if(x == par[x]){
			return x;
		}else{
			par[x] = find(par[x]);
			return par[x];
		}
	}

	/**
	 * ????????????
	 */
	void union(int x, int y){

		int rootX = find(x);
		int rootY = find(y);

		//???????x?y??????
		if(rootX == rootY){
			return;
		}	

		//??????
		if(rank[rootX] > rank[rootY]){
			//x???y??????????
			//y???x???????
			par[rootY] = rootX;
		}else{
			//?????
			//x???y???????
			par[rootX] = rootY;

			//x?y????????
			//y?????????
			if(rank[rootX] == rank[rootY]){
				rank[rootY]++;
			}
		}
	}

	/**
	 * ?????????????
	 */
	boolean same(int x, int y){
		int rootX = find(x);
		int rootY = find(y);
		return rootX == rootY;
	}
}