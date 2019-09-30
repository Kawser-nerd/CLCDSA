import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());
    boolean[] rainTimes = new boolean[24*12+1];

    for (int i = 0; i < N; i++) {
      String[] rainTime = br.readLine().split("-");
      int rainFrom = Integer.parseInt(rainTime[0]);
      int rainTo = Integer.parseInt(rainTime[1]);
      for (int j = rainFrom / 100 * 12 + (rainFrom % 100) / 5; j < rainTo / 100 * 12 + (rainTo % 100 + 4) / 5; j++) {
        rainTimes[j] = true;
      }
    }
    
    for (int i = 0; i < 24*12; i++) {
      if (!rainTimes[i]) continue;
      System.out.print(String.format("%02d%02d-", i / 12, i % 12 * 5));
      while (i < 24*12 && rainTimes[i] && rainTimes[i+1]) i++;
      i++;
      System.out.println(String.format("%02d%02d", i / 12, i % 12 * 5));
    }
  }
}