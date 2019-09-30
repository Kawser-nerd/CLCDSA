import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner scan = new Scanner(System.in);
    int N = scan.nextInt();
		scan.close();
    System.out.print(1);
    for(int i = 0; i < N-1; i++) System.out.print(0);
    System.out.println(7);
  }
}