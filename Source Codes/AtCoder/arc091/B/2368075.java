import java.util.*;
class Main{
public static void main(String[] args){
Scanner scan = new Scanner(System.in);
int N = scan.nextInt();
int K = scan.nextInt();

//a???, 
long ans = 0;
for(int B=K+1;B<=N;++B){
ans += (long)((N+1)/B)*(B-K)+Math.max(0,(N+1)%B-K);
if(K==0)--ans;
}
System.out.println(ans);
}}