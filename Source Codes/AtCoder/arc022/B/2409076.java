import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n=Integer.parseInt(sc.next());
        int[] a=new int[n];
        for(int i=0;i<n;i++){
            a[i]=Integer.parseInt(sc.next())-1;
        }
        // ???????????????
        int m=0;
        for(int i=0;i<n;i++)    m=Math.max(m,a[i]);
        // ???????
        boolean[] use=new boolean[m+1];
        // ????
        int s=1;
        int t=0;
        // ???1?????????????
        use[a[0]]=true;
        long ret=1;
        while(s<n){
            // ??????
            while(t<s&&use[a[s]]){
                use[a[t]]=false;
                t++;
            }
            // ??????
            while(s<n&&!use[a[s]]){
                use[a[s]]=true;
                s++;
            }
            ret=Math.max(ret,s-t);
        }
        System.out.println(ret);
    }
}