import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.BitSet;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.Vector;

class probB {
    private static BufferedReader input;
    private static BufferedWriter output;

    public static void main(String[] args) throws FileNotFoundException,
						  IOException {
	String type = "test";
	if (args.length > 0){
	    String arg = args[0].toUpperCase();
	    while (arg.charAt(0) == '-'){
		arg = arg.substring(1);
	    }
	    if (arg.charAt(0) == 'S'){
		type = "small";
	    }
	    if (arg.charAt(0) == 'L'){
		type = "large";
	    }
	}
	String prename = "d:\\CodeJam\\Round1\\ProblemB\\b-".concat(type);
	String inname = prename.concat(".in");
	String outname = prename.concat(".out");
	System.out.println(inname);
	System.out.println(outname);
	input  = new BufferedReader(new FileReader(inname));
	output = new BufferedWriter(new FileWriter(outname));
	int N = Integer.parseInt(input.readLine());
	for (int i = 0; i < N; ++i){
	    String solution = solve();
	    output.write("Case #"+(i+1)+": "+solution);
	    output.newLine();
	}
	output.close();
    }

    public static String solve() throws IOException {
	int N = Integer.parseInt(input.readLine());
	int M = Integer.parseInt(input.readLine());
	BitSet[] NonMaltedPrefs = new BitSet[M];
	int[] MaltedPrefs = new int[M];
	for (int i = 0; i < M; ++i){
	    NonMaltedPrefs[i] = new BitSet(N);
	    NonMaltedPrefs[i].clear();
	    MaltedPrefs[i] = -1;
	    String[] words = input.readLine().split(" ");
	    int T = Integer.parseInt(words[0]);
	    for (int j = 1; j <= T; ++j){
		int flnum = Integer.parseInt(words[2*j-1]) - 1;
		int maltedornot = Integer.parseInt(words[2*j]);
		if (maltedornot == 0){
		    NonMaltedPrefs[i].flip(flnum);
		} else {
		    MaltedPrefs[i] = flnum;
		}
	    }
	}
	int donesincechange = 0;
	int i = 0;
	BitSet MustMakeMalted = new BitSet(N);
	MustMakeMalted.clear();
	while (donesincechange < M){
	    ++donesincechange;
	    ++i;
	    i %= M;
	    NonMaltedPrefs[i].andNot(MustMakeMalted);
	    if (NonMaltedPrefs[i].isEmpty()){
		if (MaltedPrefs[i] == -1)
		    return "IMPOSSIBLE";
		if (!MustMakeMalted.get(MaltedPrefs[i])){
		    donesincechange = 0;
		    MustMakeMalted.flip(MaltedPrefs[i]);
		}
	    }
	}
	String answer = "";
	for (int j = 0; j < N; ++j){
	    if (MustMakeMalted.get(j)){
		answer = answer + "1 ";
	    } else {
		answer = answer + "0 ";
	    }
	}
	return answer;
    }
}