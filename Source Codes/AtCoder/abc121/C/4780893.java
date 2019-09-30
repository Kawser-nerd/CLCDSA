import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m =  sc.nextInt();

        List<Store> storeList = new ArrayList<>(n);
        for (int i = 0; i < n; i++){
            long price = sc.nextLong();
            long amount = sc.nextLong();
            Store store = new Store(price, amount);
            storeList.add(store);
        }

        storeList.sort(Comparator.comparingLong(a -> a.price));

        long money = 0L;
        int drinkAmount = 0;
        for (Store store : storeList){
            if (drinkAmount + store.amount >= m){
                money += store.price * (m - drinkAmount);
                break;
            }
            money += store.price * store.amount;
            drinkAmount += store.amount;
        }

        System.out.println(money);
    }

    static class Store{
        long price;
        long amount;
        public Store(long p, long a){
            price = p;
            amount = a;
        }
    }

}