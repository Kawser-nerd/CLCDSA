import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    String S = scanner.next();
    int[] doremi = new int[20];
    for(int i = 0; i < 20; i++){
      if(S.charAt(i) == 'W'){
        doremi[i] = 0;
      }else{
        doremi[i] = 1;
      }
    }
    int num = -1;
    for(int i = 0; i < 16; i++){
      if(doremi[i]*doremi[i+2]*doremi[i+4] == 1){
        num = i+1;
        break;
      }
    }
    if(num%12==1 || num%12==2){
      System.out.println("Fa");
    }else if(num%12==3){
      System.out.println("Mi");
    }else if(num%12==4 || num%12==5){
      System.out.println("Re");
    }else if(num%12==6 || num%12==7){
      System.out.println("Do");
    }else if(num%12==8){
      System.out.println("Si");
    }else if(num%12==9 ||num%12==10){
      System.out.println("La");
    }else if(num%12==11 || num%12==0){
      System.out.println("So");
    }
  }
}