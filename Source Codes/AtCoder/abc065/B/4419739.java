import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    int N = Integer.parseInt(sc.nextLine());
    
    int[] a = new int[N];
    for(int i = 0; i < N; i++){
      a[i] = Integer.parseInt(sc.nextLine());
    }
    int count = 0;
    int n = 0;
    boolean c = false;
    for(int i = 0; i < N;i++){
      if(n+1 == 2){
        c = true;
        break;
      }
      n = a[n] - 1;
      count++;
    }
    
    if(c){
      System.out.println(count);
    }else{
      System.out.println(-1);
    }
  }
}