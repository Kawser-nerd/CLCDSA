import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????
		Scanner scan =new Scanner(System.in);

		Amida amida = new Amida(scan);
		amida.res();
	}

}
class Amida{
	int N,M,D;
	int[] f;
	List<Integer>[] seni;
	int[] used;
	int[] res;
	int[] index;

	@SuppressWarnings("unchecked")
	Amida(Scanner scan){
		N=scan.nextInt();
		M=scan.nextInt();
		D=scan.nextInt();
		f = new int[N+1];
		seni = new ArrayList[N+1];
		used = new int[N+1];
		for(int i=0;i<N+1;i++){
			f[i]=i;
		}
		for(int i=0;i<M;i++){
			int A=scan.nextInt();
			int left=f[A];
			int right=f[A+1];
			f[A]=right;
			f[A+1]=left;
		}
		res = new int[N+1];
		index=new int[N+1];
	}


	void res(){
		for(int i=0;i<N;i++){
			int next=i+1;
			if(used[next]>0){
				continue;
			}
			used[next]=next;
			seni[i+1]=new ArrayList<Integer>();
			seni[i+1].add(next);
			index[i+1]=0;
			for(int j=0;j<N;j++){
				next=f[next];
				used[next]=i+1;
				if(next==i+1){
					break;
				}
				seni[i+1].add(next);
				index[next]=j+1;
			}
		}

		for(int i=1;i<N+1;i++){
			//int index=seni[used[i]].indexOf(i);
			int s=D%seni[used[i]].size();
			res[seni[used[i]].get((s+index[i])%seni[used[i]].size())]=i;
		}
		for(int i=1;i<N+1;i++){
			System.out.println(res[i]);
		}



	}
}