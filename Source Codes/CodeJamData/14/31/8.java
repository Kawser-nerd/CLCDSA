package codejam.r1c;

import codejam.Task;

import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class A extends Task {
  public static void main(String[] args) throws IOException {
//    runConsole(new A());
//    runSmall(new A(), 0);
    runLarge(new A());
  }

  @Override
  protected String getName() {
    return "A";
  }

  @Override
  protected void runOne(Scanner input, PrintWriter output) {
    String line = input.nextLine();
    long p = Long.parseLong(line.substring(0, line.indexOf("/")));
    long q = Long.parseLong(line.substring(line.indexOf("/") + 1));

    long gcd = BigInteger.valueOf(p).gcd(BigInteger.valueOf(q)).longValue();
    p = p / gcd;
    q = q / gcd;

    long qq = q;
    int step = 0;
    while (qq % 2 == 0) {
      qq /= 2;
      step++;
    }

    if (qq != 1 || step > 40) {
      output.println("impossible");
      return;
    }

    // q = 2^step
    long curMin = p;
    for (int ans = 1; ans <= 40; ans++) {
      // p/q >= 1/2^ans
      // p*2^ans >= q
      curMin *= 2;
      if (curMin >= q) {
        output.println(ans);
        return;
      }
    }

    throw new IllegalStateException();
  }
}
