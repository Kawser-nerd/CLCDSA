import java.util.*;
class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    String S = sc.next();
    int right_c = 0;
    int left_c = 0;
    String new_S = S;
    String old = "";
    for(int i = 0;i < N;i++){
      if(S.charAt(i)=='('){
        left_c++;
      }else if(S.charAt(i)==')'){
        if(left_c==0){
          right_c++;
        }else{
          left_c--;
        }
      }
    }
    for(int i = 0;i < right_c;i++){
      new_S = "(" + new_S;
    }
    for(int i = 0;i < left_c;i++){
      new_S = new_S + ")";
    }
    System.out.println(new_S);
  }
}