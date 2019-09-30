import java.util.Scanner;
public class Main{
public static void main(String[] args){
Scanner sc = new Scanner(System.in);
  int A = sc.nextInt();
  int B = sc.nextInt();
  int C = sc.nextInt();
  
  int sum = 2*(A*B+B*C+A*C);
  System.out.println(sum);
}
}