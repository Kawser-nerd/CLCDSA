import java.util.HashMap;
import java.util.Scanner;
import java.awt.Point;
public class Main{

   public static void main(String[] args){
      new Main().solve();  
   }

   public void solve(){
      Scanner scanner = new Scanner(System.in);
      long H = scanner.nextLong();
      long W = scanner.nextLong();
      int N = scanner.nextInt();

      Point[] point = new Point[N];
      for(int i=0; i<N; i++){
         int row = scanner.nextInt();
         int col = scanner.nextInt();
         point[i] = new Point(col, row);
      }

      HashMap<Point,Integer> hashmap = new HashMap<Point,Integer>();

      for(int i=0; i<N; i++){
         for(int y=-1; y<2; y++){
            for(int x=-1; x<2; x++){
               Point p = new Point(point[i].x+x, point[i].y+y);
               if(hashmap.get(p) == null){
                  hashmap.put(p,1);
               }else{
                  hashmap.put(p,hashmap.get(p)+1);
               }
            }
         }
      }

      long[] counter = new long[10];
      for(int i=0; i<counter.length; i++){
         counter[i] = 0;
      }
      long sum = (H-2)*(W-2);
      for(HashMap.Entry<Point,Integer> map : hashmap.entrySet()){
         if(1<map.getKey().x && map.getKey().x<W && 1<map.getKey().y && map.getKey().y<H){
            counter[map.getValue()]++;
            sum--;
         }
      }
      counter[0] = sum;
      for(int i=0; i<counter.length; i++){
         System.out.println(counter[i]);
      }

   }

}