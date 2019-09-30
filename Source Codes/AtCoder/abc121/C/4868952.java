import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int  N = sc.nextInt();
        long M = sc.nextLong();
        long[] A = new long[N],
               B = new long[N];
        List<long[]> al = new ArrayList<>();
        for(int i = 0; i < N; i++){
            A[i] = sc.nextLong();
            B[i] = sc.nextLong();
            al.add(new long[]{A[i], B[i]});
        }
        al.sort(Comparator.comparing(x -> x[0]));   
        int shop = 0;
        long money = 0;
        while(true){
            long stock = al.get(shop)[1],
                 price = al.get(shop)[0];
            if(stock < M){
                money += price*stock;
                M -= stock;
                shop++;
            }
            else{
                money += price*M;
                break;
            }
        }
        System.out.println(money);
    }
}