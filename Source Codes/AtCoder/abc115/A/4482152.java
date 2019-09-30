import java.util.*;

public class Main {

  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {

    int D = sc.nextInt();
    String S = "";
    switch (D) {
      case 22: S = "Christmas Eve Eve Eve"; break;
      case 23: S = "Christmas Eve Eve"; break;
      case 24: S = "Christmas Eve"; break;
      case 25: S = "Christmas"; break;
    }

    System.out.println(S);

  }
}