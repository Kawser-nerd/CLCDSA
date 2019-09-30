import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int[] a=new int[n];
        int[] b=new int[n];
        
        
        for(int i=0;i<n;i++){
            a[i]=sc.nextInt();
            b[i]=sc.nextInt();
        }
        Arrays.sort(a);
        Arrays.sort(b);
        int users=0;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                users++;
            }else{
                break;
            }
        }
        int output=users;
        int nowA=users;
        int nowB=0;
        int nowATmp=0;
        int nowBTmp=0;
        
        for(int i=1;i<1000001;i++){
            nowATmp=nowA;
            nowBTmp=nowB;
            for(int j=0;j<n-nowA;j++){
                if(a[nowA+j]==i){
                    users++;
                    nowATmp++;
                }else{
                    break;
                }
            }
            nowA=nowATmp;
            for(int j=0;j<n-nowB;j++){
                if(b[nowB+j]==i-1){
                    users--;
                    nowBTmp++;
                }else{
                    break;
                }
            }
            nowB=nowBTmp;
            if(users>output){
                output=users;
            }
        }
        System.out.println(output);
        
        

    }

}