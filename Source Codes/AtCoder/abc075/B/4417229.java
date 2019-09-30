import java.util.*;
public class Main{
public static void main(String[]args){
  Scanner sc=new Scanner(System.in);
  int h=sc.nextInt();
  int w=sc.nextInt();
  int po[][]=new int[h+2][w+2];
  for(int i=0;i<h;i++){
  String p=sc.next();
    String[]s=p.split("",0);
    for(int j=0;j<w;j++)po[i+1][j+1]=(s[j].equals("#"))?1:0;
  }
  int ans[][]=new int[h][w];
  for(int i=0;i<h;i++){
  for(int j=0;j<w;j++){
    System.out.print((po[i+1][j+1]==1)?"#":po[i][j]+po[i+1][j]+po[i+2][j]+po[i][j+1]+po[i+2][j+1]+po[i][j+2]+po[i+1][j+2]+po[i+2][j+2]);
  }
  System.out.println();
  }
}

}