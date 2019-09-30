import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int r=sc.nextInt(),c=sc.nextInt(),n=sc.nextInt();
    
    int[][] hai=new int[2*n][2];
    int size=0;
    for(int i=0;i<n;i++){
      int x0=sc.nextInt(),y0=sc.nextInt();
      int x1=sc.nextInt(),y1=sc.nextInt();
      int v0=check(x0,y0,r,c);
      int v1=check(x1,y1,r,c);
      if(v0<0 || v1<0)continue;
      hai[size][0]=v0;
      hai[size++][1]=i;
      hai[size][0]=v1;
      hai[size++][1]=i;
    }
    hai=Arrays.copyOf(hai,size);
    Arrays.sort(hai,(x,y)->x[0]-y[0]);
    
    int[] stack=new int[2*n];
    size=0;
    for(int i=0;i<hai.length;i++){
      if(size==0) stack[size++]=hai[i][1];
      else if(stack[size-1]==hai[i][1]) size--;
      else stack[size++]=hai[i][1];
    }
    System.out.println((size==0)?"YES":"NO");
  }
  static int check(int a,int b,int r,int c){
    if(a==0) return b;
    if(b==c) return c+a;
    if(a==r) return r+c+(c-b);
    if(b==0) return c+r+c+(r-a);
    return -1;
  }
}