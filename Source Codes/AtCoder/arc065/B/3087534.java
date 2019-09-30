import java.util.*;
import java.lang.*;
import java.io.*;
class Pair<E,F>{
    E first;
    F second;
    public Pair(E first, F second){
        this.first=first;
        this.second=second;
    }
    public E getFirst(){return first;}
    public F getSecond(){return second;}
    public String toString(){
        return "<"+first.toString()+","+second.toString()+">";
    }
    public int hashCode(){
        return first.hashCode()*30011+second.hashCode()+2;
    }
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Pair another = (Pair) obj;
        return this.getFirst().equals(another.getFirst())&&this.getSecond().equals(another.getSecond());
    }
}
class Counter<T> extends HashMap<T,Integer>{
    public Counter(){
        super();
    }
    public Integer get(Object elm){
        return getOrDefault(elm,0);
    }
    public void add(T elm){
        put(elm, get(elm)+1);
    }
}
class UnionFind{
    int size;
    int[] parent;
    int[] height;
    public UnionFind(int size){
        this.size = size;
        parent = new int[size];
        height = new int[size];
        for(int i=0;i<size;i++){
        	parent[i]=i;
        	height[i]=0;
        }
    }
    private boolean isRoot(int node){
        return node==parent[node];
    }
    public int getRoot(int node){
        if(isRoot(node)) return node;
        else{
        	parent[node] = getRoot(parent[node]);
        	return parent[node];
        }
    }
    public void union(int node1, int node2){
        if(height[node1]>height[node2])parent[getRoot(node2)] = getRoot(node1);
        else parent[getRoot(node1)] = getRoot(node2);
    }
    public boolean find(int node1, int node2){
        return getRoot(node1)==getRoot(node2);
    }
    public int countGroup(){
        int ans = 0;
        for(int i=0;i<size;i++) if(isRoot(i)) ans++;
        return ans;
    }
}
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int L = sc.nextInt();
        UnionFind road = new UnionFind(N);
        UnionFind rail = new UnionFind(N);
        for(int k=0;k<K;k++){
        	int p = sc.nextInt()-1;
        	int q = sc.nextInt()-1;
        	road.union(p,q);
        }
        for(int l=0;l<L;l++){
        	int r = sc.nextInt()-1;
        	int s = sc.nextInt()-1;
        	rail.union(r,s);
        }
        
        Counter<Pair<Integer,Integer>> count = new Counter<>();
        for(int n=0;n<N;n++){
        	Pair<Integer,Integer> root = new Pair<>(road.getRoot(n),rail.getRoot(n));
        	count.add(root);
        }
        for(int n=0;n<N;n++){
        	Pair<Integer,Integer> root = new Pair<>(road.getRoot(n),rail.getRoot(n));
        	System.out.print(count.get(root));
        	if(n==N-1)System.out.println();
        	else System.out.print(" ");
        }
    }
}