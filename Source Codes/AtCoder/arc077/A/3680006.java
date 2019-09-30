import java.util.*;


public class Main {
    public static void main(String[] args) {
        // ?????????
        // Let's ???????

        Scanner sc = new Scanner(System.in);
int n=sc.nextInt();
int num[]=new int[n];
for(int i=0;i<n;i++){
num[i]=sc.nextInt();
}
for(int i=n-1;i>=0;i-=2)System.out.print(num[i]+" ");
for(int i=n%2;i<n;i+=2)System.out.print(num[i]+" ");
}
}