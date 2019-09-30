import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Main {

	public static void main(String[] args) {
		Main main = new Main();
		main.run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int M = sc.nextInt();

		UnionFind uf=new UnionFind(N,"yes","no");

		for (int i = 0; i < M; i++) {
			int A = sc.nextInt()-1;
			int B = sc.nextInt()-1;

			uf.unite(A, B);

		}

		Set<Integer> set=new HashSet<Integer>();

		for (int i = 0; i < N; i++) {
			set.add(uf.root(i));
		}

		pln(set.size()-1);


	}

 class UnionFind {

		int[] par;
		int[] rank;
		String commentYes;
		String commentNO;

		public UnionFind(int MaxN,String yes,String no){
			par=new int[MaxN];
			rank=new int[MaxN];
			init(MaxN);

			commentYes=yes;
			commentNO=no;
		}

		//??????????
		void init(int n) {
			for(int i=0;i<n;i++) {
				par[i]=i;
				rank[i]=0;
			}
		}

		//???????
		public int root(int x) {

			//????????????????
			if(par[x]==x) {
				return x;
			}else {
				//????
				return par[x]=root(par[x]);
			}

		}

		//x?y???????????????????????
		public boolean same(int x,int y) {
			return root(x)==root(y);
		}

		//x?y?????????
		public void unite(int x,int y) {
			x=root(x);
			y=root(y);

			if(x==y) {
				return;
			}

			if(rank[x]<rank[y]) {
				par[x]=y;
			}else {
				par[y]=x;

				if(rank[x]==rank[y]) {
					rank[x]++;
				}
			}
		}

		public void printJudge(int x,int y) {
			if(same(x,y)) {
				System.out.println(commentYes);
			}else {
				System.out.println(commentNO);
			}
		}

		//????????????
		public int getNumOfSet() {
			Set<Integer>set=new TreeSet<Integer>();

			for(int i=0;i<par.length;i++) {
				set.add(par[i]);
			}

			return set.size();
		}

		public void changeComennt(String yes,String no) {
			commentYes=yes;
			commentNO=no;
		}
	}


	//????????

	public static int[] extgcd(int a,int b) {

		int x0=1;
		int x1=0;

		int y0=0;
		int y1=1;

		while(b != 0) {
			int q=a/b;
			int r=a%b;

			int x2=x0-q*x1;
			int y2=y0-q*y1;

			a=b;
			b=r;

			x0=x1;
			x1=x2;

			y0=y1;
			y1=y2;
		}

		return new int[] {a,x0,y0};

	}

	static int gcd(int a,int b) {

		if(b==0) return a;

		if(a<b) {
			int t=a;
			a=b;
			b=t;
		}

		return gcd(b,a%b);

	}

	static int lcm(int a,int b) {
		return a*b/gcd(a,b);
	}

	static void swap(int[] a) {
		int t;

		t=a[0];
		a[0]=a[1];
		a[1]=t;

		return;
	}
	static <T> void output(List<T> list) {

		for (int i = 0; i < list.size(); i++) {
			System.out.print(list.get(i));

			if (i != list.size() - 1) {
				System.out.print(" ");
			} else {
				nl();
			}
		}

	}

	static void output(String[][] str) {

		for (int i = 0; i < str.length; i++) {
			for (int j = 0; j < str[i].length; j++) {
				print(str[i][j]);
			}

			nl();
		}

	}

	static void output(boolean flg, String Yes, String No) {

		if (flg) {
			pln(Yes);
		} else {
			pln(No);
		}

	}

	static void output(String[][] str, int digit) {

		String dig = "%" + String.valueOf(digit) + "s";

		for (int i = 0; i < str.length; i++) {
			for (int j = 0; j < str[i].length; j++) {
				System.out.printf(dig, str[i][j]);
			}
			nl();
		}

	}

	static void pln(String str) {
		System.out.println(str);
	}

	static void pln(int x) {
		System.out.println(x);
	}

	static void print(String str) {
		System.out.print(str);
	}

	static void print(int x) {
		System.out.print(x);
	}

	static void print(String str, int times) {
		for (int i = 0; i < times; i++) {
			print(str);
		}
	}

	static void print(int x, int times) {
		for (int i = 0; i < times; i++) {
			print(x);
		}
	}

	static void nl() {
		System.out.println();
	}

}