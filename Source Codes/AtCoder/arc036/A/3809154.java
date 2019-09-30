import java.util.*;

public class Main {
  public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int K = scanner.nextInt();
    int[] t = new int[N];
    for(int i= 0; i < N; i++){
      t[i] = scanner.nextInt();
    }
    int[] a = new int[N];
    boolean flag = false;
    int index = -1;
    for(int i = 0; i < N-2; i++){
      a[i] = t[i] + t[i+1] + t[i+2];
      if(a[i] < K){
        flag = true;
        index = i+2;
        break;
      }
    }
    if(flag){
      System.out.println(index+1);
    }else{
      System.out.println(-1);
    }
  }
}