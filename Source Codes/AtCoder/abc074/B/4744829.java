import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int count = scanner.nextInt();
	int lhs = 0;
    int rhs = scanner.nextInt();
    
    int[] balls = new int[count];
    for (int ix = 0; ix < count; ix++) {
      balls[ix] = scanner.nextInt();
    }
    
    int answer = 0;
    for (int ix = 0; ix < balls.length; ix++) {
      answer += Math.min(balls[ix], rhs - balls[ix]);
    }
    
	System.out.println(answer * 2);
  }
}