import java.util.*;
class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int A[]=new int[n];
        int ans=0;
        boolean flag=true;
    for(int i=0;i<n;i++){
        A[i]=Integer.parseInt(sc.next());
    }
    while(flag){
        for(int i=0;i<n;i++){
            if(A[i]%2==0){A[i]/=2;}
            else{flag=false;}
            }
        if(flag){ans++;}
        }
    System.out.print(ans);
    }
}