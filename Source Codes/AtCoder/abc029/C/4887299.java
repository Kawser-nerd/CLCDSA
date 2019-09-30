import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    
    int N = sc.nextInt();
    meth(0, N, "");
  }
  public static void meth(int n, int N, String str){
    if(n == N){
      System.out.println(str);
      return;
    }
    
    for(int i = 0; i < 3; i++){
      String str2 = "";
      if(i == 0){
        str2 = str + "a";
        meth(n+1, N, str2);
      }else if(i == 1){
        str2 = str + "b";
        meth(n+1, N, str2);
      }else if(i == 2){
        str2 = str + "c";
        meth(n+1, N, str2);
      }
    }
  }
}