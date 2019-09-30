/*
String[]??????????long???????
???split??contains??????"+"??????????????"\\+"???
???????arr1=arr.clone()
HashSet<>[]???????????????
 */
import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n = sc.nextInt();
        out.println(ans(n,0));
    }
    static int ans(int n,int c){
        if(c==10)return 0;
        int temp=0;
        if((1+n)%power(10,c+1)>=2*power(10,c)){
            temp=power(10,c);
        }else if((1+n)%power(10,c+1)>power(10,c)){
            temp=(n+1)%power(10,c+1)-power(10,c);
        }
        return ans(n,c+1)+power(10,c)*((n+1)/power(10,c+1))+temp;
    }
    static int power(int n,int m){
        if(m==0)return 1;
        if(m%2==1)return power(n,m-1)*n;
        int e=power(n,m/2);
        return e*e;
    }
}