import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int P = sc.nextInt();
        int[] A = new int[n];
        for(int i=0;i<n;i++) A[i]=sc.nextInt();
        long[] odd = new long[n];
        long[] even = new long[n];
        odd[0]=A[0]%2==1?1:0;
        even[0]=A[0]%2==1?0:1;
        for(int i=1;i<n;i++){
            odd[i]=odd[i-1];
            even[i]=even[i-1];
            if(A[i]%2==1){
                even[i]+=odd[i-1];
                odd[i]+=even[i-1]+1;
            }else{
                even[i]+=even[i-1]+1;
                odd[i]+=odd[i-1];
            }
        }
        long ans = P==1?odd[n-1]:even[n-1]+1;
        System.out.println(ans);
    }
}