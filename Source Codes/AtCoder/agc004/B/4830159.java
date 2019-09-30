import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;
class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		int N=sc.nextInt();
		int x=sc.nextInt();
		long min=Long.MAX_VALUE;
		Segtree sg=new Segtree(N);
		sg.fill(Integer.MAX_VALUE);
		for(int i=0; i<N; i++) {
			int tmp=sc.nextInt();
			sg.update(i,tmp);
		}
		for(int i=0; i<N; i++) {//???????
			long tmp=((long)i)*((long)x);
			long ts=0;
			for(int j=0; j<N; j++) {
				if(j-i<0) {
					//?????????
					int a1=0;
					int a2=j;
					int b1=N+(j-i);
					int b2=N;
					ts+=((long)Math.min(sg.getmin(a1,a2, 0, 0, (sg.length()+1)/2), sg.getmin(b1,b2, 0, 0, (sg.length()+1)/2)));
				}
				else {
					ts+=((long)sg.getmin(j-i, j, 0, 0, (sg.length()+1)/2));
				}
			}
			tmp+=ts;
			min=Math.min(min, tmp);
		}
		pl(min);
	}
	static class Segtree{
		int[] Segtree;
		public Segtree(int vol){
			int truevol=calc_vol(vol);		//vol????????2??????
			Segtree=new int[truevol*2-1];
			for(int i=0; i<truevol*2-1; i++) {
				Segtree[i]=0;
			}
			//pl(truevol*2-1);
		}
		public void fill(int num) {		//??????????
			for(int i=0; i<Segtree.length; i++) {
				Segtree[i]=num;
				//pl(i+" "+Segtree[i]);
			}
		}
		public void update(int elem,int num) {
			int leaf=elem-1+(length()+1)/2;	//?????????
			Segtree[leaf]=num;
			boolean zero=false;	//0?????????
			while(leaf>0) {
				leaf=getParent(leaf);	//??????????
				Segtree[leaf]=Math.min(Segtree[leaf*2+1],Segtree[leaf*2+2]);
			}
		}
		public int getmin(int a,int b,int k,int l,int r) {
			//pl(a+" "+b+" "+k+" "+l+" "+r);
			if(r <= a || b < l) return Integer.MAX_VALUE; //????????????0
			if(a <= l && r-1 <= b) return Segtree[k]; //[l,r)????[a,b)??????????????????
			else {
				int vl = getmin(a, b, k*2+1, l, (l+r)/2);
				int vr = getmin(a, b, k*2+2, (l+r)/2, r);
				return Math.min(vl , vr);
			}
		}
		public int calc_vol(int vol) {	//2?????????????
			int beki=0;
			int tmp=1;
			while(vol>=tmp) {
				tmp*=2;
				if(tmp==vol) {
					break;
				}
				beki++;
			}
			return tmp;
		}
		public int getParent(int num) {	//???
			return (num-1)/2;
		}
		public int getChild(int num) {	//???
			return num*2+1;	//??2???????????????
		}
		public void add(int elem,int num) {	//elem??????num??(elem?0????)
			int leaf=elem-1+(length()+1)/2;	//??????????
			boolean zero=false;	//0?????????
			while(!zero && leaf>=0) {
				//pl(leaf);
				Segtree[leaf]+=num;
				if(leaf==0) {
					zero=true;
				}
				leaf=getParent(leaf);	//??????????
			}
		}
		public int sum(int a, int b, int k, int l, int r) {//sum(a, b, 0, 0, seg.tree.length/2)
			//[a,b]?????????
			//pl(a+" "+b+" "+k+" "+l+" "+r);
			if(r <= a || b < l) return 0; //????????????0
			if(a <= l && r-1 <= b) return Segtree[k]; //[l,r)????[a,b)??????????????????
			else {
				int vl = sum(a, b, k*2+1, l, (l+r)/2);
				int vr = sum(a, b, k*2+2, (l+r)/2, r);
				return vl + vr;
			}
		}
		public int length() {
			return Segtree.length;
		}
	}
	static class SC {
		private BufferedReader reader = null;
		private StringTokenizer tokenizer = null;
		public SC(InputStream in) {
			reader = new BufferedReader(new InputStreamReader(in));
		}
		public String next() {
			if (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new UncheckedIOException(e);
				}
			}
			return tokenizer.nextToken();
		}
		public int nextInt() {
			return Integer.parseInt(next());
		}
		public long nextLong() {
			return Long.parseLong(next());
		}
	}
	public static void pl(Object o) {
		System.out.println(o);
	}
	public static void pl() {
		System.out.println();
	}
	public static void p(Object o) {
		System.out.print(o);
	}
}