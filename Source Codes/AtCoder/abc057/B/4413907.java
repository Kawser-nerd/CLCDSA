import java.util.*;
public class Main{public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  int m=sc.nextInt();
  int[][]p=new int[n][2];
  int[][]h=new int[m][2];
  for(int i=0;i<n;i++){
  p[i][0]=sc.nextInt();
    p[i][1]=sc.nextInt();
  }
  for(int i=0;i<m;i++){
  h[i][0]=sc.nextInt();
    h[i][1]=sc.nextInt();
  }
  for(int i=0;i<n;i++){
    int point=0,plen=1000000000;
  for(int j=0;j<m;j++){
  	int len=Math.abs(p[i][0]-h[j][0])+Math.abs(p[i][1]-h[j][1]);
    if(plen>len){point=j;plen=len;}
  }
    System.out.println(point+1);
  }
  
}}