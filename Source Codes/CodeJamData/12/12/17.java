import java.util.Comparator;
import java.util.HashSet;
import java.util.Scanner;
import java.util.TreeSet;


public class b {

	/**
	 * @param args
	 */
	Scanner in=new Scanner(System.in);
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new b().go();
	}
	private void go() {
		// TODO Auto-generated method stub
		int numc=in.nextInt();
		IN:
		for(int cnum=0;cnum<numc;cnum++){
			int n=in.nextInt();
			int[][] q=new int[n][2];
			for(int i=0;i<n;i++){
				q[i][0]=in.nextInt();
				q[i][1]=in.nextInt();
			}
			int min=0,stars=0;
			HashSet<Integer>chose1=new HashSet<Integer>(),chose2=new HashSet<Integer>();
			OUT:
			for(int i=0;i<2*n;i++){
				if(stars==2*n)break;
				int max=0,maxIndex=-1;
				for(int j=0;j<n;j++){
					if(!chose2.contains(j)){
						if(!chose1.contains(j)){
							if(q[j][1]<=stars){
								stars+=2;
								min++;
								chose2.add(j);
								continue OUT;
							}
							if(q[j][0]<=stars&&q[j][1]>max){
								max=q[j][1];
								maxIndex=j;
							}
						}
						if(q[j][1]<=stars){
							stars+=1;
							min++;
							chose2.add(j);
							chose1.remove(j);
							continue OUT;
						}
					}
				}
				if(maxIndex==-1){
					System.out.printf("Case #%d: Too Bad\n", cnum+1);
					continue IN;
				}
				chose1.add(maxIndex);
				min++;
				stars+=1;
			}
			System.out.printf("Case #%d: %d\n", cnum+1,min);
		}

	}

}
