import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] S=sc.next().toCharArray();
        char[] T=sc.next().toCharArray();
        int[] Si=new int[S.length+1];
        int[] Ti=new int[T.length+1];
        Si[0]=0;
        for(int i=0;i<S.length;i++){
            Si[i+1]=Si[i]+S[i]-'A'+1;
        }
        Ti[0]=0;
        for(int i=0;i<T.length;i++){
            Ti[i+1]=Ti[i]+T[i]-'A'+1;
        }
        int q=sc.nextInt();
        for(int i=0;i<q;i++){
            int a=sc.nextInt();
            int b=sc.nextInt();
            int c=sc.nextInt();
            int d=sc.nextInt();
            int result=0;
            result=Si[b]-Ti[d]-Si[a-1]+Ti[c-1];
            if(result%3==0){
                System.out.println("YES");
            }else{
                System.out.println("NO");
            }
        }

    }
}