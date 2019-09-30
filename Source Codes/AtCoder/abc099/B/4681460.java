import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int n = b - a;
    int x = 0;
    for(int i = 1;i <= n;i++){
      x += i;
    }
    System.out.println(x - b);
  }
}