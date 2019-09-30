import java.util.*;
class Main{
  
  static class Node{
    long a,b,sub;
    Node(long a, long b){this.a=a;this.b=b;sub=a-b;}
  }
  
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    PriorityQueue<Node> minus = new PriorityQueue<>((x,y)->x.a-y.a<0?-1:1);
    PriorityQueue<Node> plus = new PriorityQueue<>((x,y)->y.a-x.a<0?-1:1);
    long zeroa = 0;
    for(int i=0;i<N;++i){
      long a=sc.nextLong();
      long b=sc.nextLong();
      if(a==b)zeroa=Math.max(zeroa, a);
      else if(a>b)plus.add(new Node(a,b));
      else minus.add(new Node(a,b));
    }
    long ans = 0;
    long val = 0;
    while(!minus.isEmpty()){
      Node n = minus.poll();
      ans = Math.max(ans, val + n.a);
      val +=n.sub;
    }
    ans = Math.max(ans, val + zeroa);
    long max=0;
    long pval=0;
    while(!plus.isEmpty()){
      Node n = plus.poll();
      if(pval+n.a>max)max =Math.min(pval+n.a, Math.max(max + n.sub, n.a));
      pval += n.sub;
    }
    System.out.println(Math.max(ans, val+max));
  }
}