import java.util.*;
import java.io.*;
import java.math.*;

public class a {

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new FileReader(args[0]));
    String str;

    int numCases = Integer.parseInt(br.readLine());
    for (int nCase = 1; nCase <= numCases; nCase++) {
     int N = Integer.parseInt(br.readLine());
     int[][] lines = new int[N][2];
     
     for (int i = 0; i < N; i++) {
       String[] sa = br.readLine().split(" ");
       lines[i][0] = Integer.parseInt(sa[0]);
       lines[i][1] = Integer.parseInt(sa[1]);
     }
     int answer = 0;
     if (N == 1)
       answer = 0;
     else if (N == 2) {
       if ((lines[0][0] < lines[1][0] && lines[0][1] > lines[1][1]) ||
           (lines[0][0] > lines[1][0] && lines[0][1] < lines[1][1]))
           answer = 1;
     }
     else
       answer = 666;
     System.out.println("Case #" + nCase + ": " + answer);
    }
    br.close();

  }

}