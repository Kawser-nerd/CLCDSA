import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int i;
    int add = 0;
    for(i = 1;i <= n;i++){
      add = add + i;
    }
    System.out.println(add);
  }
}