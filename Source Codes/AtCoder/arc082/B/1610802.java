import java.util.Scanner;

public class Main{
  static int n;
  static int[] p;

  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    n = sc.nextInt();
    p = new int[n];
    for(int i = 0; i < n; i++){
      p[i] = sc.nextInt();
    }

    int count = 0;
    for(int i = 0; i < n; i++){
      if(p[i] != i + 1){
        continue;
      }
      if(i + 1 < n && p[i + 1] == (i + 1) + 1){
        ++i;
      }
      ++count;
    }

    System.out.println(count);
  }
}