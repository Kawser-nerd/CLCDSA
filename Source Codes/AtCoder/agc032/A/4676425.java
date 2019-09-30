import java.util.*;
class Main{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int num = sc.nextInt();
    int ans[] = new int[num];
    for(int i = 0; i < num; i ++) {
      ans[i] = -1;
    }
    boolean ok = true;
    for(int i = 0; i < num; i ++) {
      int tmp = sc.nextInt();
      if(tmp > 1) {
        if(ans[tmp - 2] < 0) {
          ok = false;
          break;
        }
      }
      for(int j = num - 1; j >= tmp; j --) {
        ans[j] = ans[j - 1];
      }
      ans[tmp - 1] = tmp;
    }
    if(ok) {
      for(int i = 0; i < num; i ++) {
        System.out.println(ans[i]);
      }
    }else {
      System.out.println(-1);
    }
  }
}