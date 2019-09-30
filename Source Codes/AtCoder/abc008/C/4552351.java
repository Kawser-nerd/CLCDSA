import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int []a=new int[n];
        for(int i=0;i<n;i++)a[i]=sc.nextInt();
        double ans=0;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++)
                if(i!=j&&a[i]%a[j]==0)
                    count++;
            ans+=(count%2==0)?(double)(count/2+1)/(count+1):1.0/2;
        }
        System.out.println(ans);
    }
}