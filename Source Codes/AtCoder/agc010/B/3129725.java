import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] A = new long[n+1];
        for(int i=1;i<=n;i++) A[i]=sc.nextLong();
        String ans = help(n,A);
        System.out.println(ans);

    }
    static String help(int n, long[] A){
        if(n==1) return "YES";
        long sum = A[1];
        for(int i=2;i<=n;i++) sum+=A[i];
        long temp = ((long)n)*((long)n+1)/2;
        if(sum%temp!=0) return "NO";
        long K = sum/temp;
        long[] x = new long[n+1];
        long sumx=0;
        for(int i=1;i<=n;i++){
            long dif=i==n?(A[1]-A[i]):(A[i+1]-A[i]);
            if(K==dif) continue;
            if((K-dif)%n!=0||K<dif) return "NO";
            x[i]=(K-dif)/n;
            sumx+=x[i];
        }
        if(sumx!=K) return "NO";
        /*ArrayList<Integer> dic = new ArrayList<>();
        for(int i=1;i<=n;i++){
            for(int k=0;k<x[i];k++) dic.add(i);
        }
        long tar = A[1];
        for(int j=0;j<dic.size();j++){
            int cur = dic.get(j);
            if(cur==1) tar-=n;
            else tar-=(n-(cur-1));
        }*/
        //if(tar==0) return "YES";
        else return "YES";
    }
}