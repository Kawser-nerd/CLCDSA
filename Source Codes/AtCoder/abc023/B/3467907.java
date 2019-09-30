import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    String S = scanner.next();
    boolean flag = true;
    if(N%2==0){
      flag = false;
    }
    if(N%2!=0){
      for(int i = 0; i < S.length(); i++){
        if(N%3==1){
          if(i%3==0 && S.charAt(i)!='b'){
            flag = false;
          }else if(i%3==1 && S.charAt(i)!='c'){
            flag = false;
          }else if(i%3==2 && S.charAt(i)!='a'){
            flag = false;
          }
        }
        if(N%3==0){
          if(i%3==0 && S.charAt(i)!='a'){
            flag = false;
          }else if(i%3==1 && S.charAt(i)!='b'){
            flag = false;
          }else if(i%3==2 && S.charAt(i)!='c'){
            flag = false;
          }
        }
        if(N%3==2){
          if(i%3==0 && S.charAt(i)!='c'){
            flag = false;
          }else if(i%3==1 && S.charAt(i)!='a'){
            flag = false;
          }else if(i%3==2 && S.charAt(i)!='b'){
            flag = false;
          }
        }
      }
    }
    if(flag==true){
      System.out.println(S.length()/2);
    }else if(flag==false){
      System.out.println(-1);
    }
  }
}