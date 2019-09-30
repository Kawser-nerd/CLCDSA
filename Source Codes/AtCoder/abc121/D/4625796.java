import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) throws FileNotFoundException {

//    Scanner cin = new Scanner(new FileReader("input.txt"));
    Scanner cin = new Scanner(System.in);

    long a = cin.nextLong();
    long b = cin.nextLong();

    long res = 0;

    if (a%2==1&&b%2==0) {
      res = a^b;
      a++;
      b--;
    }
    else if (a%2==1&&b%2==1) {
      res = a;
      a++;
    }
    else if (a%2==0&&b%2==0) {
      res = b;
      b--;
    }

    long diff = (b-a+1)/2;
    int mark = 0;
    if (diff%2==1) {
      mark = 1;
    }
    System.out.println(res^mark);

  }

}