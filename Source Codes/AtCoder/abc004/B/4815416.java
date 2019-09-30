//??

import java.util.*;

class Main{
  public static void main(String[] args) {
    Scanner sc= new Scanner(System.in);
    String[][] table= new String[4][4];
    for (int i=0; i<4; i++) {
      table[i]= sc.nextLine().split(" ",0);
    }
    for (int i=3; i>-1; i-=1) {
      System.out.println(table[i][3]+" "+table[i][2]+" "+table[i][1]+" "+table[i][0]);
    }
  }
}