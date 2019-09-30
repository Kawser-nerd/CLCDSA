import java.util.*;
public class Main{
public static void main(String[]args){
  Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
    int m=sc.nextInt();
  int po[][]=new int[n][n];
  int p[][]=new int[m][m];
  for(int i=0;i<n;i++){
  String a=sc.next();
    String []s=a.split("",0);
    for(int j=0;j<n;j++){
      po[i][j]=(s[j].equals("#"))?1:0;
    }
  }
  for(int i=0;i<m;i++){
  String a=sc.next();
    String []s=a.split("",0);
    for(int j=0;j<m;j++){
      p[i][j]=(s[j].equals("#"))?1:0;
    }
  }
  boolean b=false,b2=true;
  for(int i=0;i<n-m+1;i++){
  for(int j=0;j<n-m+1;j++){
      b2=true;
      for(int k=0;k<m;k++){
          for(int l=0;l<m;l++){
              if(po[i+k][j+l]!=p[k][l])b2=false;
          }
      }if(b2){b=true;break;}
  }   if(b2)break;
  }
  System.out.println(b?"Yes":"No");
}

}