import java.util.*;
import java.io.*;
import java.math.*;

public class b {

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new FileReader(args[0]));
    String str;

    int numCases = Integer.parseInt(br.readLine());
    for (int nCase = 1; nCase <= numCases; nCase++) {
      String[] sa = br.readLine().split(" ");
      int L = Integer.parseInt(sa[0]);
      int P = Integer.parseInt(sa[1]);
      int C = Integer.parseInt(sa[2]);
      double R = (double)P/L;
      int count = 0;
      while (R > C) {
        R = Math.sqrt(R);
        count++;
      }
      System.out.println("Case #" + nCase + ": " + count);
    }
    br.close();

  }

}
