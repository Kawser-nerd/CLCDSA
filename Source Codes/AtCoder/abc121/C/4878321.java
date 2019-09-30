import java.util.*;
public class Main{
  static class Store implements Comparable<Store>{
    long price, cans;
    Store(long price, long cans){
      this.price = price;
      this.cans = cans;
    }
    public int compareTo(Store obj){
      if(this.price > obj.price){return 1;}
      if(this.price < obj.price){return -1;}
      return 0;
    }
  }
  
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    long N = sc.nextLong();
    long M = sc.nextLong();
    List<Store> stores = new ArrayList<>();
    for(int i=0; i<N; i++){
      stores.add(new Store(sc.nextLong(), sc.nextLong()));
    }
    Collections.sort(stores);
    long sum = 0;
    for(int i=0; i<N; i++){
      Store si = stores.get(i);
      if(si.cans < M){
        sum += si.price*si.cans;
        M -= si.cans;
      }else{
        sum += si.price*M;
        break;
      }
    }
    System.out.print(sum);
  }
}