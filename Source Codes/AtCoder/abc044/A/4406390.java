import java.util.*;


public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int k = sc.nextInt();
    int x = sc.nextInt();
    int y = sc.nextInt();
    int add = 0;
    int i,j;
    if(n - k > 0){
      for(i = 0;i < k;i++){
        add = add + x;
      }
    }
    else{
      for(i = 0;i < n;i++){
        add = add + x;
      }
    }
    for(j = 0;j < n-k;j++){
      add = add + y;
    }
    System.out.println(add);
  }
}