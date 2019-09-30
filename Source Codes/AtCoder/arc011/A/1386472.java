import java.util.Scanner;
public class Main{
 public static void main(String args[]) {
  int m = 0;
  int n = 0;
  int N = 0;
  int sum = 0;
  int temp = 0;
  int amari = 0;

  Scanner sc = new Scanner(System.in);
  m = sc.nextInt();
  n = sc.nextInt();
  N = sc.nextInt();
  sum = N;

  while (N >= m) {

   temp = (N / m) * n;
   amari = N % m;
   sum += temp;
   N = temp + amari;

   // System.out.println(N);
   // System.out.println(amari_sum);
  }
  System.out.println(sum);
 }
}