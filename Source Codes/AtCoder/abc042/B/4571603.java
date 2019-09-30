import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int count = scanner.nextInt();
    int length = scanner.nextInt();
    
    List<String> strings = new ArrayList<>();
    for (int ix = 0; ix < count; ix++) {
      strings.add(scanner.next());
    }
    
	Collections.sort(strings);
    StringBuilder builder = new StringBuilder();
    for (String string : strings) {
      builder.append(string);
    }
    
    System.out.println(builder);
  }
}