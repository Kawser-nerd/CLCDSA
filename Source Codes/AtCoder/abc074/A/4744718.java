import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int length = scanner.nextInt();
    int white = scanner.nextInt();
    int square = length * length;
    
    System.out.println(square - white);
  }
}