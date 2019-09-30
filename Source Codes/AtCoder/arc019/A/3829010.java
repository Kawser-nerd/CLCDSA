import java.util.Scanner;
import java.util.Arrays;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    String S = scanner.next();
    char[] c = new char[S.length()];
    for(int i = 0; i < S.length(); i++){
      c[i] = S.charAt(i);
      if(c[i] == 'O'){
        System.out.print('0');
      }else if(c[i] == 'D'){
        System.out.print('0');
      }else if(c[i] == 'I'){
        System.out.print('1');
      }else if(c[i] == 'Z'){
        System.out.print('2');
      }else if(c[i] == 'S'){
        System.out.print('5');
      }else if(c[i] == 'B'){
        System.out.print('8');
      }else{
        System.out.print(c[i]);
      }
    }
    System.out.println();
  }
}