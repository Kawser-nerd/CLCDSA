import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    char[] command = {'A', 'B', 'X', 'Y'};
    String s = sc.next();
    char[] c = new char[N];
    for(int i = 0; i < N; i++) {
      c[i] = s.charAt(i);
    }
    int ans = 2000;
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        for(int k = 0; k < 4; k++) {
          for(int l = 0; l < 4; l++) {
            char[] L = {command[i], command[j]};
            char[] R = {command[k], command[l]};
            int count = 0;
            int index = 0;
            while(index < N) {
              if(index + 1 < N) {
                if((L[0] == c[index] && L[1] == c[index + 1]) || (R[0] == c[index] && R[1] == c[index + 1])) {
                  index += 2;
                } else {
                  index++;
                }
              } else {
                index++;
              }
              count++;
            }
            ans = Math.min(ans, count);
          }
        }
      }
    }
    System.out.println(ans);
  }
}