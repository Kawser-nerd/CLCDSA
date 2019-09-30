import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) throws FileNotFoundException {

//    Scanner cin = new Scanner(new FileReader("input.txt"));
    Scanner cin = new Scanner(System.in);

    int a = cin.nextInt();
    int b = cin.nextInt();
    int c = cin.nextInt();

    if (b >= c) {
      System.out.println(b+c);
    }
    else {
      int sum = b*2;
      c = c-b;
      if (a>=c) {
        System.out.println(sum+c);
      }
      else {
        System.out.println(sum+a+1);
      }
    }


  }

}