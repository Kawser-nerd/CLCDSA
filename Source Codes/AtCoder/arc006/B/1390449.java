import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int L = sc.nextInt();
    int[][] move = new int[L][N];
    for(int i = 0; i < L; i++) {
      for(int j = 0; j < N; j++) {
        move[i][j] = -1;
      }
    }
    int pass = 0;
    sc.nextLine();
    for(int i = 0; i < L; i++) {
      String s = sc.nextLine();
      String[] sp = s.split(" ");
      int index = -1;
      for(int j = 0; j < sp.length; j++) {
        String st = sp[j];
        for(int k = 0; k < st.length(); k++) {
          if(st.charAt(k) == '|') index++;
          if(st.charAt(k) == '-') {
            move[i][index] = index + 1;
            move[i][index + 1] = index;
          }
        }
      }
    }
    String s = sc.nextLine();
    pass = s.indexOf('o') / 2;
    int pos = pass;
    int step = L - 1;
    while(step >= 0) {
      if(move[step][pos] >= 0) pos = move[step][pos];
      step--;
    }
    System.out.println(pos + 1);
  }
}