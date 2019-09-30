package D;

import java.util.*;
class Edge{
  int src , dst;
  Edge(int a , int b){
    src = a;
    dst = b;
  }
  @Override
  public String toString() {
    return src+" - " + dst;
  }
}
public class D {
  
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int C = sc.nextInt();
    for(int i = 1 ; i <= C ; i++){
      int N = sc.nextInt();
      List<Edge> elist = new ArrayList<Edge>();
      boolean large[][] = new boolean[N][N];
      for(int j = 0 ; j < N - 1 ; j++){
        int a = sc.nextInt();
        int b = sc.nextInt();
        a--;b--;
        elist.add(new Edge(a , b));
        large[a][b] = large[b][a] = true;
      }
      int M = sc.nextInt();
      List<Edge> smallelist = new ArrayList<Edge>();
      for(int j = 0 ; j < M - 1 ; j++){
        int a = sc.nextInt();
        int b = sc.nextInt();
        a--;b--;
        smallelist.add(new Edge(a , b));
      }
      boolean f = false;
      for(int j = 0 ; j < (1 << N ) ; j++){
        if(Integer.bitCount(j) != M)continue;
        List<Edge> uedge = new ArrayList<Edge>();
        int num[] = new int[N];
        for(int k = 0 ; k < elist.size() ; k++){
          Edge e = elist.get(k);
          if((j & (1 << e.src)) != 0 && (j & (1 << e.dst)) != 0){            
            uedge.add(e);
            num[e.src]++;
            num[e.dst]++;
          }
        }
        if(uedge.size() != smallelist.size())continue;
//        System.out.println(uedge+" "+smallelist);         
        int P[] = new int[M];
        int in = 0;
        for(int k = 0 ; k < num.length ; k++){
          if(num[k] == 0)continue;
          P[in++] = k;
        }
//        System.out.println(Arrays.toString(P));
        do {
          f = true;
          for(Edge s : smallelist){
            int a = P[s.src];
            int b = P[s.dst];
            if(large[a][b]){
              continue;
            }
            f = false;
            break;
          }
          if(f)break;
        } while (nextPermutation(P));
        if(f)break;
      }
      if(f){
        System.out.printf("Case #%d: YES\n", i);
      }else{
        System.out.printf("Case #%d: NO\n", i);        
      }
    }
  }
  static void swap(int i , int j , int a[]){
    int t = a[i]; 
    a[i] = a[j]; a[j] = t;
  }
  public static boolean nextPermutation(int a[]){
    int n = a.length;
    int i = n - 2;
    for(;i >= 0 ; i--)
      if(a[i] < a[i + 1])break;
    if(i < 0)return false;
    for(int j = n - 1 ; j >= i ; j--)
      if(a[i] < a[j]){
        swap(i, j, a);
        break;
      }
    for(int j = i + 1 ; j < (n + i + 1) / 2 ; j++){
      swap(j , n + i - j , a);
    }
    return true;
  }

}
