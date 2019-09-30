import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

@SuppressWarnings("unchecked")
class Main{

    static class Node{
        int v;
        long A,B;
        Node(int v,long a,long b){this.v=v;A=a;B=b;}
    }

    static long[] w0;
    static long[] w;

    static int[] pare;
    static int root(int v){
        if(pare[v]<0)return v;
        return pare[v] = root(pare[v]);
    }
    static void unite(int p,int c){
        p=root(p);c=root(c);
        if(p==c)return;
        pare[p]+=pare[c];
        pare[c]=p;
    }
    static boolean same(int u,int v){
        return root(u)==root(v);
    }
    static class Edge{
        int from,to;
        long cost;
        Edge(int from,int to,long cost){this.from=from;this.to=to;this.cost=cost;}
    }
    

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int M = scan.nextInt();
        long[] A = new long[N];
        long[] B = new long[N];
        w0 = new long[N];
        w = new long[N];
        pare=new int[N];
        for(int i=0;i<N;++i){
            A[i]=scan.nextLong();
            B[i]=scan.nextLong();
            w0[i] = Math.max(0, A[i]-B[i]);
            w[i] = B[i];
        }
        Arrays.fill(pare, -1);

        PriorityQueue<Node> nodeQue[] = new PriorityQueue[N];
        for(int i=0;i<N;++i)nodeQue[i]=new PriorityQueue<>((a,b)->(int)(((a.A-a.B)-(b.A-b.B))));
        while(M-->0){
            int u = scan.nextInt()-1;
            int v = scan.nextInt()-1;
            nodeQue[u].add(new Node(v, A[v],B[v]));
            nodeQue[v].add(new Node(u, A[u],B[u]));
        }
        if(N==1){
            System.out.println(Math.max(A[0], B[0]));
            return;
        }
        PriorityQueue<Edge> que = new PriorityQueue<>((a,b)->a.cost-b.cost==0 ? a.from-b.from : a.cost-b.cost<0 ? -1 : 1);
        for(int i=0;i<N;++i){
            Node n = nodeQue[i].peek();
            // System.out.println(i+" "+n.v+" "+Math.max(w0[i], w0[i] + n.A-w[i]));
            que.add(new Edge(i, n.v, Math.max(w0[i], (n.A-n.B)-w[i])));
        }


        while(!que.isEmpty()){
            Edge e = que.poll();
            //System.out.println(e.from+" <<< "+e.to);
            if(same(e.from, e.to) || e.cost != Math.max(w0[root(e.from)], A[e.to]-B[e.to]-w[root(e.from)]))continue;
            // System.out.println("success");
            w0[root(e.from)] = e.cost;
            w[root(e.from)] += w[root(e.to)];
            while(!nodeQue[root(e.to)].isEmpty())nodeQue[root(e.from)].add(nodeQue[root(e.to)].poll());
            unite(e.from, e.to);
            // System.out.println(w0[root(e.from)]+" "+w[root(e.from)]);
            while(!nodeQue[root(e.from)].isEmpty() && same(e.from, nodeQue[root(e.from)].peek().v))nodeQue[root(e.from)].poll();
            if(nodeQue[root(e.from)].isEmpty())break;
            Node next = nodeQue[root(e.from)].peek();
            // System.out.println("add : "+ root(e.from)+" <<< "+next.v);
            que.add(new Edge(root(e.from), next.v, Math.max(w0[root(e.from)], next.A-next.B-w[root(e.from)])));
        }
        long sum = 0;
        for(int i=0;i<N;++i)sum+=B[i];
        // System.out.println();
        // for(int i=0;i<N;++i)System.out.println(root(i));
        System.out.println(w0[root(0)]+sum);
    }
}