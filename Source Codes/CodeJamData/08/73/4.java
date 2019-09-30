import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class C {
	public static String source="C-small-attempt0";
	public static Scanner in;
	public static PrintWriter out;

		public static void main(String[] args) throws FileNotFoundException,IOException{
			in=new Scanner(new File(source+".in"));
			out=new PrintWriter(new FileWriter(source+".out"));

			int Cases=in.nextInt();
			for(int Case=1;Case<=Cases;Case++){
				int tries=in.nextInt();
				int Q=in.nextInt();in.nextLine();
				Question[] questions=new Question[Q];
				for(int i=0;i<Q;i++){
					questions[i]=new Question(in);
				}
				ArrayList<Double> probs=new ArrayList<Double>();
				int i=0;
				double[] prob=new double[Q+1];
				int[] nums=new int[Q];
				prob[0]=1;
				while(true){
					//System.out.println(i+","+nums[i]);
					prob[i+1]=prob[i]*questions[i].probs[nums[i]];
					i++;
					if(i>=Q){
						probs.add(prob[i]);
						i--;
						nums[i]++;
						while(i>=0 && nums[i]>=4){
							nums[i]=0;
							i--;
							if(i>=0)nums[i]++;
						}
						if(i<0)break;
					}
				}
				Collections.sort(probs);
				Collections.reverse(probs);
				double result=0;
				if(tries>=probs.size()){
					result=1;
				}else{
					for(i=0;i<tries;i++)
						result+=probs.get(i);
				}

				out.printf("Case #"+Case+": "+result+"\n");
			}
			out.flush();
		}
		public static class Question {
			double[] probs;
			public Question(Scanner s){
				probs=new double[4];
				for(int i=0;i<4;i++)
					probs[i]=s.nextDouble();
				s.nextLine();
			}

		}
}
