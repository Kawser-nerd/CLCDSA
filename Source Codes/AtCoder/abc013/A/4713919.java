import java.util.Scanner;

public class Main {
  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);
    char a = 'A';
    int j = (int)a;
    String s = sc.nextLine();
    char b = s.charAt(0);
    int i = (int)b;
    System.out.println(i - j + 1);
    
  }
}