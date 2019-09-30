import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] a = new int[n+1];
    boolean[] b = new boolean[n+1];
    for(int i = 1; i < n+1; i++){
      a[i] =sc.nextInt();
    }
    int i = 1,count = 0;
    while(true){
      if(i == 2){
        System.out.println(count);
        break;
      }
      if(b[i]){
        System.out.println(-1);
        break;
      }
      b[i] = true;
      i = a[i];
      count++;
    }
  }
}