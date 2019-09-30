import java.io.*;
import java.util.*;


class Main {
    static final int f(char c){
        if('0'<=c&&c<='9')return c-'0';
        return c-'A'+10;
    }
    static long calc(String a,String b){
        int n=a.length();
        UnionFind uf=new UnionFind(36);
        int[]nz=new int[2];
        int nzpos=0;
        boolean[] used=new boolean[36];
        for(int i=0;i<n;++i){
            int x=f(a.charAt(i));
            int y=f(b.charAt(i));
            uf.unify(x,y);
            if(i==0){
                if(x>=10)nz[nzpos++]=x;
                if(y>=10)nz[nzpos++]=y;
            }
        }
        for(int i=0;i<10;++i){
            for(int j=0;j<i;++j){
                if(uf.root(i)==uf.root(j))return 0;
            }
        }
        long ans=1;
        for(int i=0;i<n;++i){
            int v=f(a.charAt(i));
            if(v<10)continue;
            int r=uf.root(v);
            if(used[r])continue;
            boolean found=false;
            for(int j=0;j<10;++j){
                if(uf.root(j)==uf.root(v)){
                    found=true;
                    break;
                }
            }
            used[r]=true;
            if(!found)ans*=i==0?9:10;
        }
        return ans;
    }
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int n=sc.nextInt();
        String a=sc.next();
        String b=sc.next();
        out.println(calc(a,b));
        out.close();
    }
    // http://codeforces.com/blog/entry/7018
    //-----------PrintWriter for faster output---------------------------------
    public static PrintWriter out;
    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;
        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
        double nextDouble() {
            return Double.parseDouble(next());
        }
        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
        int[] nextIntArray(int n){
            int[]r=new int[n];
            for(int i=0;i<n;++i)r[i]=nextInt();
            return r;
        }
    }
}
class UnionFind {
    int[] parent;
    int[] rank;
    UnionFind(int n) {
	this.parent = new int[n];
	this.rank = new int[n];
	this.clear();
    }
    void clear() {
	int n = this.parent.length;
	for (int i = 0; i < n; ++i) {
	    this.parent[i] = i;
	    this.rank[i] = 0;
	}
    }
    void unify(int x, int y) {
	int rootX = this.root(x);
	int rootY = this.root(y);
	if (rootX == rootY) {
	    return;
	}
	if (this.rank[rootX] < this.rank[rootY]) {
	    this.parent[rootX] = rootY;
	} else {
	    this.parent[rootY] = rootX;
	    if (this.rank[rootX] == this.rank[rootY]) {
		this.rank[rootX]++;
	    }
	}
    }
    int root(int x) {
	if (this.parent[x] == x) {
	    return x;
	}
	return this.parent[x] = this.root(this.parent[x]);
    }
}