import java.util.*;
public class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    int a=sc.nextInt();
    int b=sc.nextInt();
    String tmps;
    int tmpd;
    int place=0;
    for(int i=0;i<n;i++){
      tmps=sc.next();
      tmpd=sc.nextInt();
      place+=(tmps.equals("East")?1:-1)*(tmpd<a?a:(tmpd>b?b:tmpd));
    }
    if(place>0){
      System.out.println("East"+" "+place);
    }else if(place<0){
      System.out.println("West"+" "+(-place));
    }else{
      System.out.println(0);
    }
  }
}