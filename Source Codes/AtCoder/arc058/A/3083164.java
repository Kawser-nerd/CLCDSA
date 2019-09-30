import java.util.*;
import java.io.*;

public class Main {
    public static boolean hated(int price, Set<Integer> hateNum){
        if(price<10) return hateNum.contains(price);
        else return hateNum.contains(price%10)||hated(price/10,hateNum);
    }
    
    public static int pay(int price, Set<Integer> hateNum){
        while(hated(price,hateNum)){
        	price++;
        }
        return price;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        Set<Integer> hateNum = new HashSet<>();
        for(int k=0;k<K;k++) hateNum.add(sc.nextInt());
        System.out.println(pay(N,hateNum));
    }
}