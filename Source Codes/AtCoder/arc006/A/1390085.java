import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    ArrayList<Integer> passingN = new ArrayList<Integer>();
    for(int i = 0; i < 6; i++) {
      passingN.add(sc.nextInt());
    }
    int B = sc.nextInt();
    int count1 = 0;
    int count2 = 0;
    for(int i = 0; i < 6; i++) {
      int buyN = sc.nextInt();
      if(passingN.contains(buyN)) count1++;
      if(B == buyN) count2++;
    }
    int ans = 0;
    if(count1 == 3) ans = 5;
    if(count1 == 4) ans = 4;
    if(count1 == 5) ans = 3;
    if(count1 == 5 && count2 == 1) ans = 2;
    if(count1 == 6) ans = 1;
    System.out.println(ans);
  }
}