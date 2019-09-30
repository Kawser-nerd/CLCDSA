import java.io.*;
import java.util.*;


class Main {
    static final int A=18;
    static void depth(int[]d,ArrayList<Integer>[]ch,int v,int a){
        d[v]=a;
        for(int w:ch[v])
            depth(d,ch,w,a+1);
    }
    static int lca(int[][]lca,int[]d,int a,int b){
        if(d[a]>d[b]){
            int t=a;
            a=b;
            b=t;
        }
        for(int i=A-1;i>=0;--i)
            if(d[b]-d[a]>=1<<i)
                b=lca[i][b];
        if(a==b)return a;
        for(int i=A-1;i>=0;--i){
            if(lca[i][a]==lca[i][b])continue;
            a=lca[i][a];
            b=lca[i][b];
        }
        return lca[0][a];
    }
    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int n=sc.nextInt();
        int m=sc.nextInt();
        ArrayList<Integer>[]g=new ArrayList[n];
        Arrays.setAll(g,x->new ArrayList<Integer>());
        for(int i=0;i<m;++i){
            int x=sc.nextInt()-1;
            int y=sc.nextInt()-1;
            g[x].add(y);
            g[y].add(x);
        }
        final int A=18;
        int[]comp=new int[n];
        int[]tree=TwoEdgeComponent.solve(g,comp);
        int l=tree.length;
        int[][]lca=new int[A][l];
        for(int i=0;i<l;++i)lca[0][i]=tree[i]==-1?i:tree[i];
        for(int i=1;i<A;++i)
            for(int j=0;j<l;++j)
                lca[i][j]=lca[i-1][lca[i-1][j]];
        int[]d=new int[l];
        ArrayList<Integer>[]ch=new ArrayList[l];
        Arrays.setAll(ch,x->new ArrayList<Integer>());
        for(int i=0;i<l;++i)
            if(tree[i]!=-1)
                ch[tree[i]].add(i);
        depth(d,ch,0,0);
        int q=sc.nextInt();
        for(int i=0;i<q;++i){
            int a=sc.nextInt()-1;
            int b=sc.nextInt()-1;
            int c=sc.nextInt()-1;
            a=comp[a];
            b=comp[b];
            c=comp[c];
            int ab=lca(lca,d,a,b);
            int bc=lca(lca,d,b,c);
            int ac=lca(lca,d,a,c);
            out.println(d[a]+2*d[b]+d[c]-2*d[ab]-2*d[bc]==d[a]+d[c]-2*d[ac]?"OK":"NG");
        }
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
    }
}
class TwoEdgeComponent {
    ArrayList<Integer>[] graph;
    int[] order, lowlink;
    int count;
    int[] comp;
    boolean[] visited;
    int[] tree;
    boolean dfs(int v) {
	return dfs(v, -1);
    }
    boolean dfs(int v, int par) {
	if (this.order[v] >= 0) {
	    return false;
	}
	this.order[v] = count;
	count++;
	int lowlink = this.order[v];
	for (int w: this.graph[v]) {
	    if (par == w) {
		continue;
	    }
	    boolean result = dfs(w, v);
	    if (result) {
		lowlink = Math.min(lowlink, this.lowlink[w]);
	    } else {
		lowlink = Math.min(lowlink, this.order[w]);
	    }
	}
	this.lowlink[v] = lowlink;
	return true;
    }
    void dfs2(int v, int par, int compId) {
	if (this.visited[v]) {
	    return;
	}
	this.visited[v] = true;
	if (par >= 0 && this.order[par] < this.lowlink[v]) {
	    // Hasi
	    compId = this.count;
	    this.count++;
	    this.tree[compId] = this.comp[par];
	}
        this.comp[v] = compId;
        for (int w: this.graph[v]) {
	    dfs2(w, v, compId);
	}
    }
    TwoEdgeComponent(ArrayList<Integer>[] graph) {
	int n = graph.length;
	this.graph = graph;
	this.order = new int[n];
	this.lowlink = new int[n];
	Arrays.fill(this.order, -1);
	Arrays.fill(this.lowlink, -1);
	this.count = 0;
	dfs(0);
	this.count = 1;
	this.comp = new int[n];
	this.visited = new boolean[n];
	this.tree = new int[n];
	Arrays.fill(this.tree, -1);
	dfs2(0, -1, 0);
    }
    public static int[] solve(ArrayList<Integer>[] graph, int[] array) {
	TwoEdgeComponent comp = new TwoEdgeComponent(graph);
	for (int i = 0; i < graph.length; ++i) {
	    array[i] = comp.comp[i];
	}
	return Arrays.copyOfRange(comp.tree, 0, comp.count);
    }
}