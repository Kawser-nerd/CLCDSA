import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int[] a = new int[3];
    a[0] = sc.nextInt();
    a[1] = sc.nextInt();
    a[2] = sc.nextInt();
    Arrays.sort(a);
    String str = ((a[0]+a[1]) == a[2]) ? "Yes" : "No";
    System.out.println(str);
  }
}