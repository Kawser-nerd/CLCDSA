import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    long L0 = 2;
    long L1 = 1;
    int n = sc.nextInt();
    long sum = L1;
    for(int i = 2; i <= n; i++){
      sum = L0 + L1;
      L0 = L1;
      L1 = sum;
    }
    System.out.println(sum);
  }
}