import java.util.Scanner;

public class Main{
  public static void main(String [] args){
    Scanner scanner = new Scanner(System.in);
    int number = Integer.parseInt( scanner.nextLine() );
    
    if (number == 3 || number ==5 || number == 7){
      System.out.println("YES");
    }
    else{
      System.out.println("NO");
    }

    scanner.close();
  }
}