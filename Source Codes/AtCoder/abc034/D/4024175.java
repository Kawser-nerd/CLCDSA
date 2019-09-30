import java.io.*;
import  java.util.*;

import static java.lang.System.in;

class Main{
    static double[][] rec;
    public static void main(String[] args)throws IOException{
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(),K = sc.nextInt();
        rec = new double[n][2];
        double sum=0.0;
        for(int i=0;i<n;i++){
            double w=sc.nextDouble(),p=sc.nextDouble()/100.0;
            rec[i][0]=w; rec[i][1]=p;
            sum+=p;
        }
        if(sum<0.0001){
            System.out.println(0);
            return;
        }
        double lo=0,hi=1;
        for(int i=0;i<33;i++){
            double mid = (lo+hi)/2;
            if(check(mid,K,n)) lo=mid;
            else hi = mid;
        }
        System.out.println(lo*100);
    }
    static boolean check(double target, int K, int n){
        myC mc = new myC(target);
        Arrays.sort(rec,mc);
        double w=0,q=0;
        for(int i=n-1;i>=n-K;i--){
            w+=rec[i][0];
            q+=rec[i][1]*rec[i][0];
        }
        return q/w>=target;
    }
    static class myC implements Comparator<double[]>{
        double target;
        public myC(double t){this.target=t;}
        public int compare(double[] a, double[] b){
            return Double.compare(a[0]*(a[1]-target),b[0]*(b[1]-target));
        }
    }
}