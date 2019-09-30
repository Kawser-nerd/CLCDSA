import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int LL=sc.nextInt();
    int RR=sc.nextInt();
    int[] L=new int[42];
    int[] R=new int[42];
    for(int i=0; i<42; i++){
      L[i]=0;
      R[i]=0;
    }
    for(int i=0; i<LL; i++){
      L[sc.nextInt()]++;
    }
    for(int i=0; i<RR; i++){
      R[sc.nextInt()]++;
    }
    int sum=0;
    for(int i=0; i<42; i++){
      sum+=Math.min(L[i],R[i]);
    }
    System.out.println(sum);
  }
}