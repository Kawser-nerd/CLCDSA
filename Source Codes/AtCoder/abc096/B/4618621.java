import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();
    int k = sc.nextInt();
    int max = Math.max(a, Math.max(b, c));
    for(int i = 0; i < k; i++){
      max *= 2;
    }
    int sum = a + b + c + max - Math.max(a, Math.max(b, c));
    System.out.println(sum);
  }
}