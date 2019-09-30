import java.util.*;
import java.io.*;

public class Main{

   private static void Even(int K, int N, PrintWriter output){
       output.print(K / 2);
       for(int i = 1; i < N; ++ i) output.print(" " + K);
       output.println();
   }

   private static void Odd(int K, int N, PrintWriter output){
       ArrayList<Integer> arrayMid = new ArrayList<Integer>();
       for(int i = 0; i < N; ++ i) arrayMid.add(i, (K + 1) / 2);    
       for(int i = 0; i < N / 2; ++ i){
           if(arrayMid.get(arrayMid.size() - 1) <= 1) arrayMid.remove(arrayMid.size() - 1);
           else{
               arrayMid.set((arrayMid.size() - 1), arrayMid.get(arrayMid.size() - 1) - 1);
               while(arrayMid.size() < N) arrayMid.add(K);
           }
       }
       for(int i = 0; i < arrayMid.size(); ++ i){
           output.print(arrayMid.get(i));
           if(i < arrayMid.size() - 1) output.print(" ");
           else output.println();
       }
   }

   public static void main(String [] args){
       InputStream inputStream = System.in;
       OutputStream outputStream = System.out;
       Scanner input = new Scanner(inputStream);
       PrintWriter output = new PrintWriter(outputStream);
       int K = input.nextInt();
       int N = input.nextInt();
       if(K % 2 == 0) Even(K, N, output);
       else Odd(K, N, output);
       input.close();
       output.close();
   }
}