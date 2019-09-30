import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int w=sc.nextInt();int h=sc.nextInt();
  int n=sc.nextInt();
  int po[][]=new int[w][h];
  for(int i=0;i<n;i++){
  	int a=sc.nextInt();int b=sc.nextInt();int c=sc.nextInt();
    if(c==1){
      for(int j=0;j<h;j++){
      	for(int k=0;k<a;k++){
        	po[k][j]=1;
        }
      }
    }
    else if(c==2){
      for(int j=0;j<h;j++){
      	for(int k=a;k<w;k++){
        	po[k][j]=1;
        }
      }
    }
    else if(c==3){
      for(int j=0;j<b;j++){
      	for(int k=0;k<w;k++){
        	po[k][j]=1;
        }
      }
    }
    else{
      for(int j=b;j<h;j++){
      	for(int k=0;k<w;k++){
        	po[k][j]=1;
        }
      }
    }
  }
  int count=0;
  for(int i=0;i<h;i++){
    
  for(int j=0;j<w;j++){
  if(po[j][i]==1){
  count++;
  }
  }
  }
  System.out.println(h*w-count);
}
}