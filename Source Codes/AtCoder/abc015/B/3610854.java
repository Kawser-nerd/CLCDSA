import java.util.*;


class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int N=sc.nextInt();
    int counter=0;
    int souwa=0;
    for(int i=0; i<N; i++){
      int tmp=sc.nextInt();
      if(tmp>0){
        souwa+=tmp;
        counter++;
      }
    }
    System.out.println((souwa+counter-1)/counter);
  }
}