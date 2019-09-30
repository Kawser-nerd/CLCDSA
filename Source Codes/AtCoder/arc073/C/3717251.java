import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        
        int[][] a=new int[n][2];
        int min=Integer.MAX_VALUE,max=Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            int x=sc.nextInt(),y=sc.nextInt();
            if(x>y){
                int z=x;
                x=y;y=z;
            }
            a[i][0]=x;a[i][1]=y;
            min=Math.min(min,x);
            max=Math.max(max,y);
         }
         
         long res=0;
         int mima=min,mami=max;
         for(int i=0;i<n;i++){
             mima=Math.max(mima,a[i][0]);
             mami=Math.min(mami,a[i][1]);
          }
          res=-(long)(mima-min)*(mami-max);
          
          Arrays.sort(a,(x,y)->x[0]-y[0]);
          int[] b=new int[n];
          for(int i=0;i<n;i++)b[i]=a[i][0];
          b[0]=a[0][1];
          int[] suf=new int[n+1];
          int te=Integer.MAX_VALUE;
          suf[n]=te;
          for(int i=n-1;i>=0;i--){
               te=Math.min(te,b[i]);
               suf[i]=te;
          }int kmin=Integer.MAX_VALUE,kmax=Integer.MIN_VALUE;
          long diff=Integer.MAX_VALUE;
          for(int i=0;i<n;i++){
               kmin=Math.min(kmin,a[i][1]);
               kmax=Math.max(kmax,a[i][1]);
               int smin=suf[i+1];
               int smax=b[n-1];
               smin=Math.min(smin,kmin);
               smax=Math.max(smax,kmax);
               smin=Math.min(smin,b[0]);
               smax=Math.max(smax,b[1]);
               diff=Math.min(diff,smax-smin);
          }
          res=Math.min(res,diff*(max-min));
          System.out.println(res);
     }
}