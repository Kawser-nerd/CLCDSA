import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int total = scanner.nextInt();
    
    int sum = 0;
    for (int ix = 1; ix <= total; ix++) {
      sum += ix;
    }
    
    System.out.println(sum);
  }
}