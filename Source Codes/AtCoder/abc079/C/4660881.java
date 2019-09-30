import java.util.Scanner;

public class Main {

  private static String[] results = new String[3];

  private static int[] input = new int[4];

  public static void main(String args[]) {
    Scanner scanner = new Scanner(System.in);
 
    String line = scanner.nextLine();
    

    for(int i = 0;i < line.length();i++){
      input[i] = Character.getNumericValue(line.charAt(i));
    }

    boolean flg = dfs(0,input[0]);

    String A = Integer.toString(input[0]);
    String B = Integer.toString(input[1]);
    String C = Integer.toString(input[2]);
    String D = Integer.toString(input[3]);

    // String answer = A+results[0]+B+results[1]+C+results[2]+D+"=7";

    System.out.print(A+results[0]+B+results[1]+C+results[2]+D+"=7");
    scanner.close();
  }

  public static boolean dfs(int index,int sum){

    if(index == 3 && sum == 7){
      return true;
    }else if(index <=2){

      results[index] = "+";

      if(dfs(index+1,sum+input[index+1])){
        return true;
      }
  
      results[index] = "-";

      if(dfs(index+1,sum-input[index+1])){
        return true;
      }
  
    }

    return false;
  }

}