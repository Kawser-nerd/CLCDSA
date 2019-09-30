import java.util.*;

public class Main {
  public static void main(String[] args) {
    int count = new Scanner(System.in).nextInt();
    
    int total = 0;
    for (int ix = 1; ix <= count; ix++) {
      total += ix;
    }
    
    System.out.println(total);
  }
}