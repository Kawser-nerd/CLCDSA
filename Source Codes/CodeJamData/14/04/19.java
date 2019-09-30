import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;

import javax.swing.JFileChooser;
import javax.swing.filechooser.FileNameExtensionFilter;



public class Q0D {

	int cn;
	Child[] ch;

	public static void main(String[] args) throws ExecutionException, Throwable{
		JFileChooser jfc = new JFileChooser("./iofile");
		jfc.setFileFilter(new FileNameExtensionFilter(null, "in"));
		while(jfc.showOpenDialog(null) != JFileChooser.APPROVE_OPTION);
		File fi = jfc.getSelectedFile();
		String fo = fi.getPath();
		fo = fo.substring(0, fo.length() - 2) + "out";
		PrintStream ps = new PrintStream(fo);
		
		Q0D q = new Q0D();
		q.ReadInput(fi);
		
		boolean large = fi.getName().contains("large");
		q.PrintOutput(ps, large);
		ps.close();
	}
	
	void ReadInput(File fi) throws IOException{
		Scanner in = new Scanner(fi);
		Scanner line = new Scanner(in.nextLine());
		cn = line.nextInt();
		line.close();
		ch = new Child[cn];
		for(int c = 0; c < cn; c++){
			ch[c] = new Child(in);
		}
		in.close();
	}
	
	
	void PrintOutput(PrintStream ps, boolean large) throws IOException, Throwable, ExecutionException{
		if(large){
			ExecutorService exec = Executors.newFixedThreadPool(Runtime.getRuntime().availableProcessors());
			Future[] fc = new Future[cn];
			for(int c = 0; c < cn; c++){
				fc[c] = exec.submit(ch[c]);
			}
			exec.shutdown();
			for(int c = 0; c < cn; c++){
				while(!fc[c].isDone())
					Thread.sleep(10000);
				ps.format("Case #%d: %s\n", c + 1, ch[c].result);
			}
		}
		else{
			for(int c = 0; c < cn; c++){
				ch[c].run();
				ps.format("Case #%d: %s\n", c + 1, ch[c].result);
			}
		}
	}
	
	static class Child implements Runnable{
		String result = "";
		TreeSet<Double> nb = new TreeSet<Double>();
		TreeSet<Double> kb = new TreeSet<Double>();
		
		Child(Scanner in){
			Scanner line = new Scanner(in.nextLine());
			line.close();
			line = new Scanner(in.nextLine());
			while(line.hasNextDouble())
				nb.add(line.nextDouble());
			line.close();
			line = new Scanner(in.nextLine());
			while(line.hasNextDouble())
				kb.add(line.nextDouble());
			line.close();
		}
		
		int war(){
			TreeSet<Double> n = new TreeSet<Double>(nb);
			TreeSet<Double> k = new TreeSet<Double>(kb);
			int s = 0;
			while(!n.isEmpty()){
				double w = n.pollFirst();
				if(w > k.last()){
					k.pollFirst();
					++s;
				}else{
					k.remove(k.higher(w));
				}
			}
			return s;
		}
		
		int dwar(){
			TreeSet<Double> n = new TreeSet<Double>(nb);
			TreeSet<Double> k = new TreeSet<Double>(kb);
			int s = 0;
			while(!n.isEmpty()){
				double w = n.pollFirst();
				if(w > k.first()){
					k.pollFirst();
					++s;
				}else{
					k.pollLast();
				}
			}
			return s;
		}
		
		
		@Override
		public void run() {
			result = Integer.toString(dwar()) + " " + Integer.toString(war());
		}
		
	}
}