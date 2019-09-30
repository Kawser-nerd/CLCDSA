import java.util.*;

class Main{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int APrice = sc.nextInt();
    int BPrice = sc.nextInt();
    int ABPrice = sc.nextInt();
    int ATarget = sc.nextInt();
    int BTarget = sc.nextInt();
    
    long answer = 0;
    
    if(APrice + BPrice >= 2 * ABPrice){
      if(ATarget > BTarget){
        answer = 2 * ABPrice * BTarget;
        ATarget -= BTarget;
        if(APrice >= ABPrice * 2){
          answer += ABPrice * 2 * ATarget;
        }else{
          answer += APrice * ATarget;
        }
      }else{
        answer = 2 * ABPrice * ATarget;
        BTarget -= ATarget;
        if(BPrice >= ABPrice * 2){
          answer += ABPrice * 2 * BTarget;
        }else{
          answer += BPrice * BTarget;
        }
      }
    }else{
      answer = APrice * ATarget + BPrice * BTarget;
    }
    
    System.out.println(answer);
  }
}