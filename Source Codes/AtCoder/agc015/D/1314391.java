import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????
		Scanner scan = new Scanner(System.in);
		long A=scan.nextLong();
		long B=scan.nextLong();


		long[] two = new long[61];
		two[0]=1;
		for(int i=1;i<61;i++){
			two[i]=two[i-1]*2;

		}

		int maxk=0;
out:	for(int j=60;j>=0;j--){
		for(int i=j;i>=0;i--){
			if(A<=two[i]&&B>=two[i]){
				maxk=i;
				break out;
			}//else if(A>two[i]&&B>two[i])
			if(i==0){
				for(int k=1;k<=60;k++){
					if(A<two[k]){
						A-=two[k-1];
						B-=two[k-1];
						break;
					}

				}

			}
		}
		}



//		System.out.println(two[maxk]);

		long ans = two[maxk]-A;
		B-=two[maxk];
//		if(B<A){
			int maxk_=0;
			//B????????????
			for(int i=0;i<=60;i++){
				if(B<two[i]){
					maxk_=i;
					break;
				}
			}
			ans +=two[maxk_];

			if(two[maxk_]<=A){
				ans+=two[maxk]-A;
			}else{
				ans+=two[maxk]-two[maxk_];
			}
		System.out.println(ans);
	}

}