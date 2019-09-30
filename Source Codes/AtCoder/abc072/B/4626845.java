import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    String line = scanner.nextLine();
    
    StringBuilder builder = new StringBuilder();
    for (int ix = 0; ix < line.length(); ix++) {
      if (ix % 2 == 0) {
        builder.append(line.charAt(ix));
      }
    }
    
    System.out.println(builder);
  }
}