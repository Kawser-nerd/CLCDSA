import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int h=sc.nextInt();
  int w=sc.nextInt();
  String [][]po=new String[h+2][w+2]; 
  for(int i=0;i<w+2;i++){
  po[0][i]=".";
    po[h+1][i]=".";
  }
  for(int i=1;i<h+1;i++){
  	String s[]=sc.next().split("",0);
    for(int j=0;j<w+2;j++){
    	if(j==0||j==w+1){
          po[i][j]=".";
        }
      else{
      po[i][j]=s[j-1];
      }
    }
  }
  boolean b=true;
  for(int i=1;i<h+1;i++){
  for(int j=1;j<w+1;j++){
  	if(!b)break;
    if(po[i][j].equals("#")){
    	if(po[i-1][j].equals(".")&&po[i+1][j].equals(".")&&po[i][j+1].equals(".")&&po[i][j-1].equals("."))
          b=false;
    }
  }
  }
    System.out.println((b?"Yes":"No"));

}
}