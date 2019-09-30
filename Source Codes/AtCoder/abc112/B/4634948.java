import java.util.*;
public class Main {

	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int T = sc.nextInt();
	int []hairetu1 = new int[N];
	int []hairetu2 = new int[N];
	for(int i=0;i<N;i++) {
		hairetu1[i]=sc.nextInt();
		hairetu2[i]=sc.nextInt();
	}
int count=0;
	for(int i=0;i<N;i++) {
	if(hairetu2[i]<=T){
		count++;
	}
		}
	if(count==0){
		System.out.println("TLE");
		System.exit(0);
	}
	
	int z=0;
	int []hairetu3 = new int[count];
	for(int i=0;i<N;i++) {
		if(hairetu2[i]<=T){
			hairetu3[z]=hairetu1[i];
			z++;
		}
	}
	int min = hairetu3[0];
	for(int i=0;i<count;i++){
		if(min>hairetu3[i]){
			min=hairetu3[i];
		}
	}
	System.out.println(min);
	}
	}