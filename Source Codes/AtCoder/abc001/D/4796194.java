import java.util.*;
public class Main {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    
    // 5?????????
    int[] arr = new int[12*24+1];

    for (int i = 0; i < n; i++) {
      String[] t = sc.next().split("-");
      int s = Integer.parseInt(t[0]);
      // ?????????
      s = s/100 * 60 + s % 100;
      s = s - s % 5;
      int e = Integer.parseInt(t[1]);
      // ?????????
      e = e/100 * 60 + e % 100;
      if(e % 5 != 0) {
        e = e + (5 - e % 5);
      }
      // ??????1???
      arr[s/5] += 1;
      // ??????1????
      arr[e/5] -= 1;
    }

    // ?????????????????
    int sum = 0;
    for (int i = 0; i < 12*24+1; i++) {
      sum += arr[i];
      arr[i] = sum;
    }

    // array[i]????????????
    int start = -1;
    for (int i = 0; i < 12*24+1; i++) {
      if(arr[i] > 0){
        start = i;
        while(i < 12*24+1 && arr[i] > 0){
          i++;
        }
        int end = i;
        System.out.print(String.format("%04d", start/12*100+start%12*5));
        System.out.print("-");
        System.out.println(String.format("%04d", end/12*100+end%12*5));
      }
    }
    
  }
}