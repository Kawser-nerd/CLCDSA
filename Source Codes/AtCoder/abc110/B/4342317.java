import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int x = sc.nextInt();
      	int y = sc.nextInt();
      int mas1[] = new int[N]; 
      int mas2[] = new int[M];
      int ans = 0;
      
      for(int i=0; i<N;i++){mas1[i]=sc.nextInt();}
      for(int i=0; i<M;i++){mas2[i]=sc.nextInt();}
      Arrays.sort(mas1);Arrays.sort(mas2);
      
      for(int i=x+1;i<=y;i++){if(i>mas1[N-1]&&i<=mas2[0]){ans=1;break;}}
      
      if(ans==1){System.out.print("No War");}
      else{System.out.print("War");}
	}
}