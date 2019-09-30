import java.io.*;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		try {
			Scanner scan = new Scanner(System.in);
			String str_m = scan.next();
			String str_n = scan.next();
			String str_N = scan.next();
			int m = Integer.parseInt(str_m); 
			int n = Integer.parseInt(str_n);
			int N = Integer.parseInt(str_N);  

			int total = N;	
			int amari = 0;	
			int newPencil = 0;
			while(true){	
				if(N >= m){
					amari += N % m;
					newPencil = N/m;
					newPencil *= n;
					N = newPencil;
					total += N;
					
				}else if(N<m && (N + amari) >= m){
					N += amari;
 
					amari = N % m;
					newPencil = N/m;
					newPencil *= n;
					N = newPencil;
					total += N;	
	
				}else{
					break;
				}
			}

			System.out.println(total);

		} catch (Exception e) {
			System.out.println(e);
		}
	}
}