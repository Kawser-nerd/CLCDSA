import java.util.*;

public class Bullseye {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    StringBuilder out = new StringBuilder();
    int numCases = in.nextInt();
    for (int caseNum = 1; caseNum <= numCases; ++caseNum) {
      out.append(String.format("Case #%d: ", caseNum));
      long rad = in.nextLong();
      long t = in.nextLong();
      
      long min = 0; // guaranteed to be "valid"
      long max = Math.min(Long.MAX_VALUE/(2*rad) + 1, (long)Math.sqrt(Long.MAX_VALUE) + 200);
      
      while (min < max - 1) {
        long guess = (max + min)/2;
        long check = eval(guess, rad);
        if (check > t) { // too high
          max = guess;
        } else { // uses less than we have = good
          min = guess;
        }
      }
      out.append(min);
      out.append('\n');
    }
    System.out.print(out);
  }
  
  public static long eval(long numRings, long rad) {
    return (2*numRings + 2*rad - 1)*numRings;
  }
}