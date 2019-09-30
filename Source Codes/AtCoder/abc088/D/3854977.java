import java.util.*;
import java.io.*;

/*
   AtCoder contest code
   coder : yoichidon
 */
import java.util.*;
import java.lang.*;
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
}
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int W = sc.nextInt();
        boolean[][] board = new boolean[H][W];
        int black = 0;
        for(int h=0; h<H; h++){
            String line = sc.next();
            for(int w=0; w<W; w++){
                board[h][w] = (line.charAt(w)=='.');
                black += (board[h][w] ? 0 : 1);
            }
        }

        Graph G = new Graph(H*W);
        //(h,w) <-> h*W+w
        for(int h=0; h<H; h++) for(int w=0; w<W; w++){
            if(!board[h][w]) continue;
            if(w+1<W && board[h][w+1]){
                G.addEdge(h*W+w, h*W+w+1);
            }
            if(h+1<H && board[h+1][w]){
                G.addEdge(h*W+w, (h+1)*W+w);
            }
        }

        try{
            List<Integer> route = G.dijkstra(0, H*W-1);
            System.out.println(H*W - black - route.size());
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println(-1);
        }
    }
}