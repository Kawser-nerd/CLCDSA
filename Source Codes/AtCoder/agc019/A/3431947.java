import java.io.*;
import java.util.*;
import java.math.*;
public class Main {
  public static void main(String[] args) throws Exception {
    String line = null;
    long num = 0;
    long rem = 0;
    long res = 0;
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    line = br.readLine();
    String price[] = line.split(" ");
    line = br.readLine();
    long vol = Long.parseLong(line);
    // ???1?????????????
    long cost1 = Long.parseLong(price[0]) * 4;         // 0.25L
    long cost2 = Long.parseLong(price[1]) * 2;         // 0.50L
    long cost3 = Long.parseLong(price[2]);             // 1.00L
    long d_cost4 = Long.parseLong(price[3]);           // 2.00L * 2
    // 0.25L, 0.5L. 1L???????
    long minPrice = Math.min(Math.min(cost1, cost2), cost3);
    if (minPrice * 2 <= d_cost4) {
      res = minPrice * vol;
    } else {
      num = vol / 2;  // 2L?????
      rem = vol % 2;  // 2L??????(1 or 0)
      res = (d_cost4 * num) + (minPrice * rem);
    }
    System.out.println(res);
  }

}