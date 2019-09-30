import java.util.*;
import java.io.*;

/*
   AtCoder contest code
   coder : yoichidon
 */

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String reply = sc.next();
        boolean[] ans = new boolean[N];
        for(int n=0; n<N; n++) ans[n] = (reply.charAt(n)=='o');
        boolean[] animal = new boolean[N];

        animal[0]=true; animal[1]=true;
        for(int n=2; n<N; n++){
            animal[n] = ans[n-1] ^ animal[n-2] ^ animal[n-1];
        }
        if((animal[N-2]^animal[0]==animal[N-1]^ans[N-1]) && (animal[N-1]^animal[1] == animal[0]^ans[0])){
            for(int n=0; n<N; n++) System.out.print(animal[n] ? 'S' : 'W');
            System.out.println();
            return;
        }

        animal[0]=true; animal[1]=false;
        for(int n=2; n<N; n++){
            animal[n] = ans[n-1] ^ animal[n-2] ^ animal[n-1];
        }
        if((animal[N-2]^animal[0]==animal[N-1]^ans[N-1]) && (animal[N-1]^animal[1] == animal[0]^ans[0])){
            for(int n=0; n<N; n++) System.out.print(animal[n] ? 'S' : 'W');
            System.out.println();
            return;
        }
        animal[0]=false; animal[1]=true;
        for(int n=2; n<N; n++){
            animal[n] = ans[n-1] ^ animal[n-2] ^ animal[n-1];
        }
        if((animal[N-2]^animal[0]==animal[N-1]^ans[N-1]) && (animal[N-1]^animal[1] == animal[0]^ans[0])){
            for(int n=0; n<N; n++) System.out.print(animal[n] ? 'S' : 'W');
            System.out.println();
            return;
        }

        animal[0]=false; animal[1]=false;
        for(int n=2; n<N; n++){
            animal[n] = ans[n-1] ^ animal[n-2] ^ animal[n-1];
        }
        if((animal[N-2]^animal[0]==animal[N-1]^ans[N-1]) && (animal[N-1]^animal[1] == animal[0]^ans[0])){
            for(int n=0; n<N; n++) System.out.print(animal[n] ? 'S' : 'W');
            System.out.println();
            return;
        }

        System.out.println("-1");



    }
}