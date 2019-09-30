import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;


public class A {
	public static String source="A-large";
	public static Scanner in;
	public static PrintWriter out;

		public static void main(String[] args) throws FileNotFoundException,IOException{
			in=new Scanner(new File(source+".in"));
			out=new PrintWriter(new FileWriter(source+".out"));

			int Cases=in.nextInt();
			for(int Case=1;Case<=Cases;Case++){
				int R=in.nextInt();in.nextLine();
				recipes=new HashMap<String,Recipe>();
				Recipe goal=null;
				String[] names=new String[R];
				for(int i=0;i<R;i++){
					if(i==0){
						goal=new Recipe(in.nextLine());
						names[i]=goal.name;
					}
					else names[i]=new Recipe(in.nextLine()).name;
				}
				System.out.println();
				for(int i=0;i<R;i++){
					System.out.println(names[i]+" : "+recipes.get(names[i]).mixtures.size()+" "+recipes.get(names[i]).getMinBowls());
				}

				out.printf("Case #"+Case+": "+goal.getMinBowls()+"\n");
			}
			out.flush();
		}
		public static HashMap<String,Recipe> recipes;
		public static class Recipe implements Comparable<Recipe>{
			String name;
			ArrayList<String> mixtures;
			boolean hasElements;
			int minBowls;
			public Recipe(String list){
				Scanner s=new Scanner(list);
				name=s.next();
				mixtures=new ArrayList<String>();
				minBowls=-1;
				int count=s.nextInt();
				for(int i=0;i<count;i++){
					String element=s.next();
					if(element.charAt(0)>='A' && element.charAt(0)<='Z'){
						mixtures.add(element);
					}else hasElements=true;
				}
				recipes.put(name,this);
			}
			public int getMinBowls(){
				if(minBowls>0)return minBowls;
				if(mixtures.size()<=0)return 1;
				ArrayList<Recipe> children=new ArrayList<Recipe>();
				for(int i=0;i<mixtures.size();i++)
					children.add(recipes.get(mixtures.get(i)));
				Collections.sort(children);
				Collections.reverse(children);
				int minBowls=0;
				for(int i=0;i<children.size();i++){
					minBowls=Math.max(i+children.get(i).getMinBowls(),minBowls);
				}
				minBowls=Math.max(minBowls, 1+mixtures.size());
				return minBowls;
			}
			public int compareTo(Recipe r){
				return getMinBowls()-r.getMinBowls();
			}
		}
}
