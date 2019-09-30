import java.util.*;

class Main{            
     
   public static void main(String[] args){
       Scanner sc = new Scanner(System.in);  
       
       int N = sc.nextInt();
       int a[] = new int[N];
       
       for(int i = 0;i < N;i++){
           a[i] = sc.nextInt();
       }
       
       int cnt[] = new int[200000];
       
       for(int i = 0;i < N;i++){
           if(a[i] != 0)cnt[a[i]-1]++;
           cnt[a[i]]++;
           cnt[a[i]+1]++;
       }
       
       int res = 0;
       
       for(int i = 0;i < cnt.length;i++){
           res = Math.max(res,cnt[i]);
       }
       
       System.out.println(res);
       
       
   }
}