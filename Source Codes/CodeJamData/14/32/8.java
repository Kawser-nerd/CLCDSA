package codejam.r1c;

import codejam.Task;

import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class B extends Task {
  public static void main(String[] args) throws IOException {
//    runConsole(new B());
//    runSmall(new B(), 0);
    runLarge(new B());
  }

  @Override
  protected String getName() {
    return "B";
  }

  @Override
  protected void runOne(Scanner input, PrintWriter output) {
    int n = input.nextInt();
    input.nextLine();
    String line = input.nextLine() + " ";
    List<String> es = new ArrayList<String>();
    for (int i = 0; i < n; i++) {
      es.add(line.substring(0, line.indexOf(" ")));
      line = line.substring(line.indexOf(" ") + 1);
    }

    long ans = 1;

    for (char ch = 'a'; ch <= 'z'; ch++) {
      List<String> fromBeg = new ArrayList<String>();
      List<String> fromEnd = new ArrayList<String>();
      List<String> whole = new ArrayList<String>();
      List<String> inMiddle = new ArrayList<String>();
      List<String> without = new ArrayList<String>();

      for (String e : es) {
        int firstIndex = Integer.MAX_VALUE, lastIndex = Integer.MIN_VALUE;
        int index = 0;
        for (char c : e.toCharArray()) {
          if (c == ch) {
            firstIndex = Math.min(index, firstIndex);
            lastIndex = Math.max(index, lastIndex);
          }
          index++;
        }
        if (firstIndex == Integer.MAX_VALUE) {
          without.add(e);
          continue;
        }
        for (int i = firstIndex; i <= lastIndex; i++) {
          if (e.charAt(i) != ch) {
            output.println(0);
            return;
          }
        }
        if (firstIndex == 0 && lastIndex == e.length() - 1) {
          whole.add(e);
          continue;
        }
        if (firstIndex == 0) {
          fromBeg.add(e);
          continue;
        }
        if (lastIndex == e.length() - 1) {
          fromEnd.add(e);
          continue;
        }
        inMiddle.add(e);
      }

      es.clear();
      es.addAll(without);

      if (!inMiddle.isEmpty()) {
        if (fromBeg.size() + fromEnd.size() + whole.size() != 0) {
          output.println(0);
          return;
        } else {
          es.addAll(inMiddle);
        }
      } else {
        if (fromBeg.size() > 1 || fromEnd.size() > 1) {
          output.println(0);
          return;
        } else {
          String conc = "";
          for (String s : fromEnd) {
            conc += s;
          }
          for (String s : whole) {
            conc += s;
          }
          for (String s : fromBeg) {
            conc += s;
          }
          if (!conc.isEmpty()) {
            es.add(conc);
          }
          for (int i = 1; i <= whole.size(); i++) {
            ans *= i;
            ans %= 1000000007;
          }
        }
      }
    }

    for (int i = 1; i <= es.size(); i++) {
      ans *= i;
      ans %= 1000000007;
    }

    output.println(ans);
  }
}
