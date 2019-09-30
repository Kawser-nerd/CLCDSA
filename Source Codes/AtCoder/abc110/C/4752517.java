import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    String t = sc.next();
    sc.close();
    //-97(int)
    int[] listS = new int[26];
    int[] listT = new int[26];
    boolean ans = true;
    for(int i = 0;i<s.length();i++){
      if((listS[C(s,i)] == C(t,i) || listS[C(s,i)] == 0) && (listT[C(t,i)] == C(s,i) || listT[C(t,i)] == 0)){
        listS[C(s,i)] = C(t,i);
        listT[C(t,i)] = C(s,i);
      }else{
        ans = false;
        break;
      }
    }
    System.out.println(ans ? "Yes" : "No");
  }
  
  public static int C(String s,int i){
    return (int)s.charAt(i)-97;
  }
}