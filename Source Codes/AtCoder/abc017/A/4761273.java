import java.util.Scanner;

public class Main {
  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);
    String[] s1 = sc.nextLine().split(" ",0);
    String[] s2 = sc.nextLine().split(" ",0);
    String[] s3 = sc.nextLine().split(" ",0);
    int sum = (((Integer.parseInt(s1[0])*100)*Integer.parseInt(s1[1]))/1000) +
      		  (((Integer.parseInt(s2[0])*100)*Integer.parseInt(s2[1]))/1000) +
      		  (((Integer.parseInt(s3[0])*100)*Integer.parseInt(s3[1]))/1000);
    System.out.println(sum);
  }
}