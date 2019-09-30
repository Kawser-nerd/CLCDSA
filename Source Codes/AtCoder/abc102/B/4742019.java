import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int max = 0;
    int min = Integer.MAX_VALUE;
    for(int i = 0; i < n; i++){
      int tmp = sc.nextInt();
      max = Math.max(max, tmp);
      min = Math.min(min, tmp);
    }
    System.out.println(max - min);
  }
}