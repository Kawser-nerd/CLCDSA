import java.util.*;
public class Main {
    static class Store implements Comparable<Store>
    {
        long cans,price;
        Store(long cans,long price){
            this.cans =  cans;
            this.price = price;
        }
        public int compareTo(Store s){
            if(s.price < this.price)return 1;
            if(s.price > this.price) return -1;
            return 0;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long M = sc.nextInt();
        ArrayList<Store> stores = new ArrayList<>();
        for(int i = 0 ; i < N ; i++){
            long cost = sc.nextLong();
            long cans = sc.nextLong();
            Store newStore = new Store(cans,cost);
            stores.add(newStore);
        }
        Collections.sort(stores);
        long sum = 0;
        long taken = 0;
        for(int i = 0 ; i < stores.size() ; i++){
            long count = Math.min(M-taken,stores.get(i).cans);
            sum += count * stores.get(i).price;
            taken += count;
            if(taken >= M){
                break;
            }
        }
        System.out.println(sum);
    }
}