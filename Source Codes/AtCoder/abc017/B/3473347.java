import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    String X = scanner.next();
    int ans = 0;
    for(int i = 0; i < X.length(); i++){
      if(X.charAt(i)=='c'&&X.charAt(i+1)=='h'&&i+1<X.length()){
        ans+=2;
      }else if(X.charAt(i)=='o'||X.charAt(i)=='k'||X.charAt(i)=='u'){
        ans+=1;
      }
    }
    if(ans==X.length()){
      System.out.println("YES");
    }else{
      System.out.println("NO");
    }
  }
}