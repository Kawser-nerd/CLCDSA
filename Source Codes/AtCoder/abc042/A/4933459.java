import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    
    String[] str = sc.nextLine().split(" ");
    int fiveCount = 0;
    int sevenCount = 0;
    
    for (String val : str) {
      if (val.equals("5")) fiveCount++;
      if (val.equals("7")) sevenCount++;
    }
    
    System.out.println((fiveCount == 2 && sevenCount == 1) ? "YES": "NO");
  }
}