import java.util.*;
import java.io.*;

class Pair<E extends Comparable<E>,F extends Comparable<F>> implements Comparable<Pair<E,F>>{
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

    public int compareTo(Pair<E,F> another){
        if(this.getFirst().equals(another.getFirst())){
            return this.getSecond().compareTo(another.getSecond());
        }
        return this.getFirst().compareTo(another.getFirst());
    }

}
class Edge implements Comparable<Edge>{
    Node end;
    double weight;
    public Edge(Node end, double weight){
        this.end = end;
        this.weight = weight;
    }
    public Edge(Node end){
        this.end = end;
        this.weight = 1;
    }
    public double getWeight(){
        return weight;
    }
    public Node getEnd(){
        return end;
    }
    public int compareTo(Edge another){
        if(this.getWeight()==another.getWeight()) return this.getEnd().compareTo(another.getEnd());
        else return (new Double(this.getWeight())).compareTo(new Double(another.getWeight()));
    }
    public String toString(){
        return "->"+end.toString()+"["+weight+"]";
    }
}
class Node implements Comparable<Node>{
    int id;
    List<Edge> edges;
    public Node(int id){
        this.id = id;
        this.edges = new LinkedList<>();
    }
    public void addEdge(Edge e){
        edges.add(e);
    }
    public void addEdge(Node n, double weight){
        this.addEdge(new Edge(n,weight));
    }
    public void addEdge(Node n){
        this.addEdge(n,1);
    }
    public void connect(Node n, double weight){
        edges.add(new Edge(n,weight));
    }
    public void connect(Node n){
        edges.add(new Edge(n));
    }
    public int getID(){
        return id;
    }
    public List<Edge> getEdges(){
        return edges;
    }
    public List<Node> getNeighbors(){
        LinkedList<Node> neighbors = new LinkedList<>();
        for(Edge e:this.getEdges()){
            neighbors.add(e.getEnd());
        }
        return neighbors;
    }
    public int compareTo(Node another){
        return this.getID()-another.getID();
    }
    public String toString(){
        return "N"+id;
    }
}
class Graph{
    int size;
    List<Node> nodes;//nodes[i] have ID "i"
    int edgeNum;
    public Graph(int size){
        this.size = size;
        nodes = new ArrayList<>(size);
        for(int i=0;i<size;i++){
            nodes.add(new Node(i));
        }
        this.edgeNum=0;
    }
    public void addNode(){
        nodes.add(new Node(size));
        size++;
    }
    public void addDirectionalEdge(int i, int j, double w){ // i->j
        if(i>=size || j>=size)return;
        nodes.get(i).addEdge(nodes.get(j),w);
        edgeNum++;
    }
    public void addDirectionalEdge(int i, int j){ // i->j
        if(i>=size || j>=size)return;
        nodes.get(i).addEdge(nodes.get(j));
        edgeNum++;
    }
    public void addEdge(int i, int j, double w){
        addDirectionalEdge(i,j,w);
        addDirectionalEdge(j,i,w);
    }
    public void addEdge(int i, int j){
        addDirectionalEdge(i,j);
        addDirectionalEdge(j,i);
    }
    public int getSize(){
        return size;
    }
    public List<Edge> getEdges(int i){
        return nodes.get(i).getEdges();
    }
    public List<Node> getNeighbors(int i){
        return nodes.get(i).getNeighbors();
    }
    public double getDistance(int i, int j){
        double ans = Double.POSITIVE_INFINITY;
        for(Edge e:this.getEdges(i)){
            if(e.getEnd().getID()==j) ans = Math.min(ans,e.getWeight());
        }
        return ans;
    }
    public double pathDistance(int[] nodes){
        double ans = 0;
        for(int n=1;n<nodes.length;n++){
            ans += this.getDistance(nodes[n-1],nodes[n]);
        }
        return ans;
    }
    public double pathDistance(Integer[] nodes){
        double ans = 0;
        for(int n=1;n<nodes.length;n++){
            ans += this.getDistance(nodes[n-1],nodes[n]);
        }
        return ans;
    }
    public double pathDistance(List<Integer> nodes){
        return pathDistance(nodes.toArray(new Integer[0]));
    }
    public List<Integer> queueDijkstra(int start, int end){
        double[] distance = new double[size];
        for(int n=0;n<size;n++) distance[n]=Double.POSITIVE_INFINITY;
        distance[start]=0;
        int[] prev = new int[size];
        for(int n=0;n<size;n++) prev[n]=-1;

        PriorityQueue<Pair<Double,Integer>> A = new PriorityQueue<>();
        A.add(new Pair<>(distance[start],start));
        while(A.size()>0){
            Pair<Double,Integer> pair = A.poll();
            int u = pair.getSecond();
            if(pair.getFirst()>distance[u])continue;
            for(Edge e:getEdges(u)){
                int v = e.getEnd().getID();
                double newDistance = distance[u] + e.getWeight();
                if(distance[v]>newDistance){
                    A.remove(new Pair<>(distance[v],v));
                    distance[v] = newDistance;
                    prev[v] = u;
                    A.add(new Pair<>(distance[v],v));
                }
            }
        }
        LinkedList<Integer> ans = new LinkedList<>();
        ans.push(end);
        int cur = end;
        while(cur!=start){
            ans.push(prev[cur]);
            cur = prev[cur];
        }
        return ans;
    }
    public List<Integer> normalDijkstra(int start, int end){
        double[] distance = new double[size];
        for(int n=0;n<size;n++) distance[n]=Double.POSITIVE_INFINITY;
        distance[start]=0;
        int[] prev = new int[size];
        for(int n=0;n<size;n++) prev[n]=-1;

        LinkedList<Integer> A = new LinkedList<>();
        A.add(start);
        while(A.size()>0){
            int best = A.peek();
            for(int p:A){
                if(distance[p]<distance[best]) best=p;
            }
            if(best==end) break;
            A.remove(new Integer(best));
            for(Edge e:getEdges(best)){
                int w = e.getEnd().getID();
                if(distance[w]==Double.POSITIVE_INFINITY){
                    distance[w] = distance[best] + e.getWeight();
                    A.add(w);
                    prev[w] = best;
                }else if(distance[best]+e.getWeight() < distance[w]){
                    distance[w] = distance[best]+e.getWeight();
                    prev[w] = best;
                }
            }
        }
        LinkedList<Integer> ans = new LinkedList<>();
        ans.push(end);
        int cur = end;
        while(cur!=start){
            ans.push(prev[cur]);
            cur = prev[cur];
        }
        return ans;
    }
    public List<Integer> dijkstra(int start, int end){
        if(size*size < 2 * edgeNum + size * Math.log(size)) return normalDijkstra(start,end);
        else return queueDijkstra(start,end);
    }
    public double[] bellmanford(int start) throws IllegalArgumentException {
        double[] distance = new double[size];
        for(int i=0;i<size;i++) distance[i]=Double.POSITIVE_INFINITY;
        distance[start]=0;
        for(int time=0;time<size-1;time++){
            for(Node u:nodes)for(Edge e:u.getEdges()){
                Node v = e.getEnd();
                if(distance[v.getID()]>distance[u.getID()]+e.getWeight()){
                    distance[v.getID()] = distance[u.getID()]+e.getWeight();
                }
            }
        }
        for(Node u:nodes)for(Edge e:u.getEdges()){
            Node v = e.getEnd();
            if(distance[u.getID()]+e.getWeight()<distance[v.getID()])
                throw new IllegalArgumentException();
        }
        return distance;
    }

    public Graph toRootedTree(int root){
        Graph tree = new Graph(size);
        LinkedList<Integer> toCheck = new LinkedList<>();
        Set checked = new HashSet<Integer>();
        toCheck.add(root);
        while(!toCheck.isEmpty()){
            int x = toCheck.pop();
            checked.add(x);
            for(Node ng : this.getNeighbors(x)){
                if(!checked.contains(ng.getID())){
                    toCheck.add(ng.getID());
                    tree.addDirectionalEdge(x,ng.getID());
                }
            }
        }
        return tree;
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
    boolean isRoot(int node){
        return node==parent[node];
    }
    private int getRoot(int node){
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
    public static void possible(){
        System.out.println("Yes");
        System.exit(0);
    }
    public static void impossible(){
        System.out.println("No");
        System.exit(0);
    }


    static int nextIntersection(Graph G, int currentID, int prevID ){
        if(G.getEdges(currentID).size() > 2) return currentID;
        if(G.getEdges(currentID).get(0).end.getID()==prevID) return nextIntersection(G, G.getEdges(currentID).get(1).end.getID(), currentID);
        else return nextIntersection(G, G.getEdges(currentID).get(0).end.getID(), currentID);
    }
    static  Pair<Integer, Integer> closestIntersections(Graph G, int nodeID){
        return new Pair<>(nextIntersection(G, nodeID, G.getEdges(nodeID).get(1).end.getID()),nextIntersection(G, nodeID, G.getEdges(nodeID).get(0).end.getID()));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int V = sc.nextInt();
        int E = sc.nextInt();
        Graph G = new Graph(V);
        for(int e=0;e<E;e++){
            int u = sc.nextInt()-1;
            int v = sc.nextInt()-1;
            G.addEdge(u,v);
        }

        for(int v=0; v<V; v++){
            if(G.nodes.get(v).getEdges().size() %2!=0) impossible();
        }

        if(E >= V+3) possible();
        if(E <= V+1) impossible();

        Set<Integer> fourEdgeNode = new HashSet<>();
        for(int v=0; v<V; v++){
            if(G.nodes.get(v).getEdges().size() ==6) possible();
            if(G.nodes.get(v).getEdges().size() ==4) fourEdgeNode.add(v);
        }

        UnionFind simpleConnection = new UnionFind(V);
        for(Node n:G.nodes) {
            if(fourEdgeNode.contains(n.getID())) continue;
            for(Node m: G.getNeighbors(n.getID())){
                if(fourEdgeNode.contains(m.getID())) continue;
                simpleConnection.union(m.getID(),n.getID());

            }
        }

        for(int v=0; v<V; v++){
            if(!fourEdgeNode.contains(v) && simpleConnection.isRoot(v)){
                Pair<Integer,Integer> end = closestIntersections(G, v);
                if(end.getFirst().equals(end.getSecond())){
                    possible();
                }
            }
        }

        impossible();



    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.