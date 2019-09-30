import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int ans=0;
        int n=sc.nextInt(),m=sc.nextInt(),k=sc.nextInt();
        boolean po[][]=new boolean[n][m];
        for(int i=0;i<n;i++){
            String[]s=sc.next().split("",0);
            for(int j=0;j<m;j++)po[i][j]=(s[j].equals("o"))?true:false;
        }
        int [][]oo=new int[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int min=0,max=0;
                int in=i;
                while(in>=0&&po[in][j]){
                    in--;
                    min++;
                }in=i;
                while(in<n&&po[in][j]){
                    in++;
                    max++;
                }
                oo[i][j]=Math.min(min,max);
            }
        }
        for(int i=k-1;i<n-k+1;i++)for(int j=k-1;j<m-k+1;j++){
            boolean d=true;
            for(int a=0;a<k;a++){
                d=d&&(oo[i][j-a]>=k-a)&&(oo[i][j+a]>=k-a);
            }
            if(d)ans++;
        }
        System.out.println(ans);
    }
}