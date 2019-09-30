import java.util.*;

public class Main{
  static int N;
  static int[] a;
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    N = sc.nextInt();
    a = new int[N];
    for(int i = 0; i<N; i++){
      a[i] = sc.nextInt();
    }
    if(N==1){
      System.out.println(1);
      return;
    }
    int l = 0;
    int r = 0;
    boolean[] con = new boolean[100010];
    int res = 0;
    while(r!=N){
      int cur = a[r];
      if(!con[cur]){
        con[cur] = true;
        r++;
        int clen = r-l;
        res = Math.max(res, clen);
      }else{
        con[a[l]] = false;
        l++;
      }
    }
    System.out.println(res);
  }
}