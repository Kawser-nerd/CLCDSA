import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    int[] a = new int [n];
    int[] b = new int [n];
    int[] c = new int [m];
    int[] d = new int [m];
    for(int i = 0; i < n; i++){
      a[i] = sc.nextInt();
      b[i] = sc.nextInt();
    }
    for(int i = 0; i < m; i++){
      c[i] = sc.nextInt();
      d[i] = sc.nextInt();
    }
    int dist = 0;
    int num = 1;
    for(int i = 0; i < n; i++){
      dist = Math.abs(c[0] - a[i]) + Math.abs(d[0] - b[i]);
      for(int j = m - 1; j >= 0; j--){
        if(dist >= (Math.abs(c[j] - a[i]) + Math.abs(d[j] - b[i]))){
          num = j + 1;
          dist = Math.abs(c[j] - a[i]) + Math.abs(d[j] - b[i]);
        }
      }
      System.out.println(num);
    }
  }
}