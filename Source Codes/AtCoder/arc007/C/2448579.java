import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Main main=new Main();
		main.run();
	}

	void run() {

		Scanner sc=new Scanner(System.in);
		
		String input=sc.next();
		int n=input.length();
		
		boolean[] signal=new boolean[n];
		
		for(int i=0;i<n;i++) {
			
			if(input.charAt(i)=='o') {
				signal[i]=true;
			}else {
				signal[i]=false;
			}
		}
		
		int result=99999;
		
		
		for(int i=0;i<(1<<n);i++) {
			
			boolean[] now=new boolean[n];
			int counter=0;
			
			for(int j=0;j<n;j++) {
				
				if((i>>j)%2==0) {
					continue;
				}
				counter++;
				
				for(int k=0;k<n;k++) {
					
					if(!signal[k]) {
						continue;
					}
					
					now[(j+k)%n]=true;
					
				}
				
			}
			
			boolean flag=true;
			
			for(int j=0;j<n;j++) {
				if(!now[j]) {
					flag=false;
				}
			}
			
			if(flag) {
				result=Math.min(result,counter);
			}
		}
		
		System.out.println(result);
	}






}