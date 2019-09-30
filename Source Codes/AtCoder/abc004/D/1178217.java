import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int R = sc.nextInt();
    int G = sc.nextInt();
    int B = sc.nextInt();
    int minCost = Integer.MAX_VALUE;
    // ?????????????
    for(int i = -349; i <= 50; i++) {
      int rcost = 0;
      int gcost = 0;
      int bcost = 0;
      for(int j = i; j < i + G; j++) {
        gcost += (int)Math.abs(j);
      }
      if(i <= -99) {
        for(int j = i - R; j < i; j++) {
          rcost += (int)Math.abs(j + 100);
        } 
      } else {
        int s = (R - 1) / 2;
        int t = (R - 1) - s;
        if(s <= i + 99) {
          rcost = (s * (s + 1)) / 2 + (t * (t + 1)) / 2;
        } else {
          for(int j = i - R; j < i; j++) {
            rcost += (int)Math.abs(j + 100);
          }
        }
      }
      if(i + G >= 100) {
        for(int j = i + G; j < i + G + B; j++) {
          bcost += (int)Math.abs(j - 100);
        }
      } else {
        int u = (B - 1) / 2;
        int v = (B - 1) - u;
        if(u <= 100 - (i + G)) {
          bcost = (u * (u + 1)) / 2 + (v * (v + 1)) / 2;
        } else {
          for(int j = i + G; j < i + G + B; j++) {
            bcost += (int)Math.abs(j - 100);
          }
        }
      }
      minCost = Math.min(minCost, rcost + gcost + bcost);
    }
    System.out.println(minCost);
  }
}