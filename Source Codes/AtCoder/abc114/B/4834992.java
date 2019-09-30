import java.util.Scanner;

public class Main{
  public static void main(String [] args){

    //nextLine():1??????????
    //length():???????????
    //substring(a,b):a??b-1????????????????????

    Scanner scanner = new Scanner(System.in);
    String s = scanner.nextLine();

    int[] save = new int[s.length()];
    int min = 1000;

    for(int i = 0; i < s.length()-2; i++){
      save[i] =  Integer.parseInt( s.substring(i,i+3) );
    }

    for(int i = 0; i < s.length()-2; i++){

      save[i] = 753 - save[i];
      if(save[i] < 0){
        save[i] = -save[i];
      }
      if(save[i] < min){
        min = save[i];
      }
    }
    System.out.println(min);
  }
}