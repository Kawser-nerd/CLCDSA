import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int total = scanner.nextInt();
    int time = scanner.nextInt();
    
    int remaining = Math.max(0, total - time);
    System.out.println(remaining);
  }
}